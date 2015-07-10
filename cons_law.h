// Author:	Juan Pablo Gallego Valencia
// Created:	June 2015

#include<iostream>
#include<iterator>
#include<cstdlib>
#include<math.h>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm> 
#include<stdlib.h>
#include<iomanip>

#include"fdgrid.h"
#include"utilities.h"

using namespace std;


/*
 *	Concervation Law Object:
 - the coordinates x, y, z 	(TODO: Higher dimentions.)
 - the states u, v, w		(TODO: System of equation?)
 - the dimension
 - the initial condition (function)
 - the flux function
 */

/*
 * Conservation Laws class for FD implementation, it contais the dimention dim, the cartesian variables x, y, z and the state u
 */
class FD_Conservation_Laws{
  int dim, n;
  double dx;
  vector<double> x, y, z; // Coordinates
  vector<double> u, u0; 	// State and Initial Condition
  vector<double> flux;	// Evaluation of the flux function
public:
  template <typename GridType> FD_Conservation_Laws(GridType& );			// Constructors
  template <typename GridType> FD_Conservation_Laws(GridType& , int); 				
  void set_dimension(int);								// TODO: Update code for higher dimensions
  void set_ic(vector<double>&,vector<double>&); 					// Evaluate Initial Condition (const x,u) for now
  template <typename InputVector> InputVector Burgers_1D_Flux(InputVector&); 		// Burgers Flux function
  void get_state(vector<double>&);							// Return state of conservation laws
  void write_results(const char*);							// Write results in a file
  template <typename InputVector, typename StateVector, typename type_dt> StateVector OneStepScheme(InputVector&, StateVector&, type_dt);
  void run();
  
  // Characteristic analysis
  template <typename OutputVector, typename SpaceVector, typename StateVector, typename type_dt>
    OutputVector CharLine(SpaceVector, StateVector, type_dt);				// Create a characteristic line (2 values). Input param: (x0, u0, dt)
};


/*
 *	Constructors for the Conservation Law object
 */
template <typename GridType> 
FD_Conservation_Laws::FD_Conservation_Laws(GridType& grid) //(FD_grid::FD_grid& grid)
{
  FD_Conservation_Laws(grid, 1);
};

template <typename GridType> 
FD_Conservation_Laws::FD_Conservation_Laws(GridType& grid, int dim) //(FD_grid::FD_grid& grid, int dim)
{
  cout<<"\n \t Constructor initialized";
  n=pow(grid.get_num_nodes(),dim);
  switch (dim)
  {
    case 1:
      grid.get_nodes(x);
      dx = grid.get_dx();
      set_ic(x, u0);
      u = u0;
      break;
    case 2:			// TODO: Flux functions for higher dimensions
      break;
    case 3:
      break;
    default:
      break;
  }
  flux=Burgers_1D_Flux(u);
  
};

/*
 *	Initial Condition for the one-dimenstional Burgers equation, in this case it is an exponential bump exp(-(10x)^2)
 */
void FD_Conservation_Laws::set_ic(vector<double>& x, vector<double>& u0)
{
  for(unsigned int i = 0; i < x.size(); i++)
    //for(vector<double>::iterator i = x.begin(); i != x.end(); i++)
  {
    double x0 = -x[i]*x[i];
    x0 = exp(x0);
    u0.push_back(x0);
  }
  
};

/*
 * 	Numerical flux for the 1-dimentional burgers equations
 */
template <typename InputVector> 
InputVector FD_Conservation_Laws::Burgers_1D_Flux(InputVector& u)
{
  typedef typename InputVector::value_type number;
  InputVector flux;
  for(unsigned int i = 0; i < u.size(); i++)
  {
    number aux=u[i]*u[i]; 		// TODO: Add flux functions for higher dimensions
    flux.push_back(aux);
    //cout<<"\n \t "<<aux; //output flux values
  }
  return flux;
};//*/

/*
 * 	Set dimension of the conserbation law, which is one by default.
 */
void FD_Conservation_Laws::set_dimension(int d)
{
  dim=d;
};

/*
 *	Return state
 */
void FD_Conservation_Laws::get_state(vector<double>& state)
{
  state=u;
};

/*
 * 	Simplest stable numerical scheme
 * 	Boundary conditions are supposed to be periodic
 */
template <typename InputVector, typename StateVector, typename type_dt>
StateVector FD_Conservation_Laws::OneStepScheme(InputVector& x, StateVector& u, type_dt dt)
{
  StateVector u_new(u.size());
  type_dt lambda = dt/dx;
  for(unsigned int i = 1; i < u.size()-1; i++)				// Exclude boundary terms
    u_new[i] = 0.5*(u[i-1]+u[i+1]) - 0.5*lambda*(flux[i+1]-flux[i-1]);
  
  //	Default boundary conditions: Periodic		TODO: Function switching between different kinds of boundaries
  u_new[0] = 0.5*(u[u.size()-1]+u[1]) - lambda*(flux[1]-flux[flux.size()-1]);
  u_new[u_new.size()-1] = 0.5*(u[u.size()-2]+u[0]) - lambda*(flux[0]-flux[u.size()-2]);
  
  return u_new;
  
};

/*
 * 	Write results in a file which name is storef in "filename"
 * 	TODO: Find a way to send this function into utilities or to an additional file dedicated to outputs
 */

void FD_Conservation_Laws::write_results(const char* filename)
{
  FILE * printResults = fopen(filename,"w");
  fprintf(printResults, "# x \t u \n" );
  for(unsigned int i=0; i < x.size(); i++)
    fprintf(printResults, " %e \t %e \n" , x[i], u[i]);
  fclose(printResults);
};

/*
 * 	Main sequence of time evolution
 * 	TODO: Create a parameter class to abvoid recompiling every time a constant value is changed
 */

void FD_Conservation_Laws::run()
{  
  double finalT = 2.0;
  double t=0.0;
  
  string outputname = "burgers-";
  string extension = ".dat";
  int width_seq = 4;
  
  int step_number=0, plots_number=20;
  
  double dt_write=finalT/plots_number, next_w_time=dt_write;
  
  
  while(t < finalT)
  {
    
    double max_u = MyMaxEntry<vector<double>, double>(u);
    double dt = 0.5*dx/max_u;
    
    
    //	Calculate scheme and new flux
    u = OneStepScheme(x, u, dt);
    flux = Burgers_1D_Flux(u);
    
    if(t>next_w_time)
    {
      step_number++;
      next_w_time+=dt_write;
      
      const char * _filename = Gen_Seq_File_Names(outputname, extension, width_seq, step_number);
      write_results(_filename);
    }
    t+=dt;
  } 
};

/*
 * 	Characteristic lines:
 * 	- Make two points (at t = 0 and t = dt) from a specific initial condition and save each one of them as a pair (x,t) = (coordenada espacial, tiempo)
 */

template <typename OutputVector, typename SpaceVector, typename StateVector, typename type_dt>
OutputVector FD_Conservation_Laws::CharLine(SpaceVector coordinate_0, StateVector state_0, type_dt dt)
{
  vector< pair<SpaceVector, type_dt> > Char_Point_1(coordinate_0, 0);
  vector< pair<SpaceVector, type_dt> > Char_Point_2(coordinate_0 + state_0*dt);
  
  vector<OutputVector> Characteristic;
  Characteristic.push_back(Char_Point_1);
  Characteristic.push_back(Char_Point_2);
  
};


