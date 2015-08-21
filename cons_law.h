// Author:	Juan Pablo Gallego Valencia
// Created:	June 2015

#include<iostream>
#include<iterator>
#include<cstdlib>

#include<fstream>
#include<string>
#include<sstream>
#include<algorithm> 
#include<stdlib.h>
#include<iomanip>

#include"initial_condition.h"
#include"Quadratures.h"
#include"fegrid.h"
#include"fe_definitions.h"

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
class FD_Conservation_Laws
{
  int dim, n;
  double dx;
  //GridType grid;
  std::vector<double> x, y, z; // Coordinates
  std::vector<double> u, u0; 	// State and Initial Condition
  std::vector<double> flux;	// Evaluation of the flux function
public:
  
  // Constant type functions to be defined in cons_law.cc
  void set_dimension(int);								// TODO: Update code for higher dimensions
  void set_ic(std::vector<double>&,std::vector<double>&); 				// Evaluate Initial Condition (const x,u) for now
  void get_state(std::vector<double>&);							// Return state of conservation laws
  void write_results(const char*);							// Write results in a file
  void write_char(const char* , std::vector<std::pair<double, double> > &, double);	// Write the characteristic curves
  void run();
  
  // template functions to be defined here in the header file
  template <typename GridType> FD_Conservation_Laws(GridType& );			// Constructors
  template <typename GridType> FD_Conservation_Laws(GridType& , int); 		
  template <typename InputVector> InputVector Burgers_1D_Flux(InputVector&); 		// Burgers Flux function
  template <typename InputVector, typename StateVector, typename type_dt> StateVector OneStepScheme(InputVector&, StateVector&, type_dt);
  
	    // Characteristic analysis
  template <typename Number> std::pair<Number, Number> CharLine(Number, Number, Number);				// Create a characteristic line (2 values). Input param: (x0, u0, dt)

  
  
};

/*
 *	Constructors for the Conservation Law object
 */

template <typename GridType> 
FD_Conservation_Laws::FD_Conservation_Laws(GridType& grid, int dim)
{
  std::cout<<"\n \t Constructor initialized";
  n=pow(grid.get_num_nodes(),dim);
  switch (dim)
  {
    case 1:
      //FD_grid grid;
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

template <typename GridType> 
FD_Conservation_Laws::FD_Conservation_Laws(GridType& grid) //(FD_grid::FD_grid& grid)
{
  FD_Conservation_Laws(grid, 1);
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
  }
  return flux;
};




/*--------------------------------------------------------------------------------------------------
 * 	Discontinuous Galerkin Conservation Law Object
 *--------------------------------------------------------------------------------------------------
 */

/*
 * 	TODO: DEFINE THE RUN FUNCTION
 *	TODO: Update code for higher dimensions
 */
class DG_Conservation_Laws
{
  FE_grid<double,vector<double>> grid;
  GeneralPolyBasis<Polynomial, vector<double>> Basis;
  int dim, n, p, dof, num_states;			// dim: Dimension, n: number of cells, p: order of the polynomial, dof: degrees of freedom
  double dx, cfl, h;			// dx: volume of the cell, cfl: cfl constant, h: ratio between  the timestep and the volume
//  std::vector<double> x, y, z; // Coordinates
  std::vector<double> q_points, weights, nodes;
  std::vector<double> u, u0, u_old; 	// State and Initial Condition
  std::vector<double> flux;		// Evaluation of the flux function
  enum ConservFlux {advection, burgers, euler, maxwell, mhd};
  ConservFlux flux_type;
  enum InitialCond {step1D, gaussian1D};
  InitialCond ic;
public:
  
  // Constant type functions to be defined in cons_law.cc
  void initialize();
  void get_state(std::vector<double>&);							// Return state of conservation laws
  
  void set_equ_flux(std::string &);
  
  void set_ic( string& );
  void eval_ic(vector<double>&, vector<double>&);
  double eval_ic(double);
  void calculate_ic();
  
  void write_results(const char*);							// Write results in a file
  void write_char(const char* , std::vector<std::pair<double, double> > &, double);	// Write the characteristic curves
  
  double NumInt(vector<double>&);
  DG_Conservation_Laws(string& , string&, int , int, int );			// Constructors
};

