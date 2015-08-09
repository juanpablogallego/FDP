#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include"cons_law.h"
#include"utilities.h"


/*
 *	Initial Condition for the one-dimenstional Burgers equation, in this case it is an exponential bump exp(-(10x)^2)
 */
void FD_Conservation_Laws::set_ic(std::vector<double>& x, std::vector<double>& u0)
{
  for(unsigned int i = 0; i < x.size(); i++)
  {
    double x0 = -x[i]*x[i];
    x0 = exp(x0);
    u0.push_back(x0);
  }
};

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
void FD_Conservation_Laws::get_state(std::vector<double>& state)
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
  /* // Old version (c++98)
  FILE * printResults = std::fopen(filename,"w");
  std::fprintf(printResults, "# x \t u \n" );
  for(unsigned int i=0; i < x.size(); i++)
    std::fprintf(printResults, " %e \t %e \n" , x[i], u[i]);
  std::fclose(printResults);//*/
  
  // New version (C++0X)
  std::ofstream printResults;
  printResults.open (filename);
  printResults << "# \t x \t u\n";
  for(unsigned int i=0; i < x.size(); i++)
    printResults << x[i] << "\t" << u[i] << "\n";
  printResults.close();  
};



void FD_Conservation_Laws::write_char(const char* filename, std::vector<std::pair<double, double> > &CharLines, double dt)
{
  std::ofstream printResults;
  printResults.open (filename);
  printResults << "# Characteristic lines time: \n";
  printResults << "# \t t \t lines\n";
  
  // Initial point of the characteristics
  //printResults << "";
  std::pair<double,double> par1 = CharLines[0];
  for(unsigned int i=1; i < CharLines.size(); i++)
  {
    std::pair<double,double> par2 = CharLines[i];
    if(par1.second>par2.second)
    {
      printResults << par1.first << "\t 0 \n"; //<< u[i] << "\n";    
      printResults << par1.second << "\t "<< 5*dt << " \n \n";  
      
      printResults << par2.first << "\t 0 \n"; //<< u[i] << "\n";    
      printResults << par2.second << "\t "<< 5*dt << " \n \n";      
    }
    par1=par2;
  }
  
  printResults.close();  
};


/*
 * 	Characteristic lines:
 * 	- Make two points (at t = 0 and t = dt) from a specific initial condition and save each one of them in a pair (x0, x_dt)
 * 	- Input: Space coordinate coordinate_0, Value of the state at the coordinate_0 state_0, and time slot width dt.
 */
template <typename Number>
std::pair<Number,Number> FD_Conservation_Laws::CharLine(Number coordinate_0, Number state_0, Number dt)
{
  std::pair<Number, Number> Char_Points(coordinate_0, coordinate_0 + 5*state_0*dt);
  
  return Char_Points;
  //Characteristic.push_back(Char_Points);
  //Characteristic.push_back(Char_Point_2);
  
};

/*
 * 	Main sequence of time evolution
 * 	TODO: Create a parameter class to abvoid recompiling every time a constant value is changed
 */
void FD_Conservation_Laws::run()
{  
  double finalT = 2.0;
  double t=0.0;
  
  std::string outputname = "burgers-";
  std::string charname = "burg_char-";

  std::string extension = ".dat";

  int width_seq = 4;
  
  int step_number=0, plots_number=20;
  
  double dt_write=finalT/(plots_number+1), next_w_time=dt_write;
  
  
  while(t < finalT)
  {
    //double max_u = MyMaxEntry<std::vector<double>, double>(u);
    double max_u = MyMaxEntry(u);

    double dt = 0.5*dx/max_u;
    
    
    //	Calculate scheme and new flux
    u = OneStepScheme(x, u, dt);
    flux = Burgers_1D_Flux(u);
    
    std::vector<std::pair<double, double>> CValues;
    for(unsigned int i=0; i<x.size();i++)
    {
      std::pair<double, double> charpair = CharLine<double>(x[i], u[i], dt);//CharLine<double>(x[i], u[i], dt);
      CValues.push_back(charpair);
    }
    
    if(t>next_w_time)
    {
      step_number++;
      next_w_time+=dt_write;
      
      const char * _filename = Gen_Seq_File_Names(outputname, extension, width_seq, step_number);
      write_results(_filename);
      
      const char * _filenamechar = Gen_Seq_File_Names(charname, extension, width_seq, step_number);
      write_char(_filenamechar, CValues, dt);
    }
    t+=dt;
  } 
};

