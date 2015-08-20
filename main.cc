// Author:	Juan Pablo Gallego Valencia
// Created:	July 2015

#include<iostream>
#include<iterator>
#include<cstdlib>
#include<string.h>


#include"cons_law.h"		// Should include just one library to call all the rest
				// TODO: everything must be done through parameters.


int main(int argc, char **argv) {
  
  //create Conservation law object
  std::string cl_flux = "advection";
  std::string cl_ic = "step1D";
  int dim =1, n = 101, p=2;
  DG_Conservation_Laws claw(cl_flux , cl_ic,  dim , n, p);
	
	//Create the 1D grid
	/*int dim=1, n=101;
	FE_grid<double, vector<double>> grid (-5,5,n);
	grid.set_1d_grid();
	grid.set_triangulation();//*/
	
	// Create Polynomial basis
	/*int order = 2;
	vector<vector<double> > coef = LegendreCoefficients(order);
	typedef GeneralPolyBasis<Polynomial, vector<vector<double> > > BasisType;
	
	BasisType Basis(order, coef);
	Basis.normalize_base();
  
	vector<vector<double> > Matrix;
	CreateMassMatrix(Basis, Matrix);//*/
	
	
	// Write grid in a file
	/*const char *filename = "grid.dat";
	std::ofstream printResults;
	
	printResults.open (filename);
	
	string Title1 ="# Nodes";
	vector<double> nodes;
	nodes = grid.get_nodes();
	output_fn(printResults, Title1, nodes);
	
	vector<vector<int>> triangulation;
	triangulation = grid.get_triangulation();
	string Title2 ="# Triangulation";
	output_fn(printResults, Title2, triangulation);
	
	printResults.close();//*/
	
	// Run test case
	

	//	Verify if the grid actually works
	//int n=grid.get_num_nodes();
      	//std::cout<<"Number of nodes: "<< n<<std::endl;
      	//std::vector<double> v(n);
      	//grid.get_nodes(v);
      	//std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " \n"));
	//std::cout<<"\n";
//*/

	//	Create the Conservation Law object
	// FD_Conservation_Laws claw(grid, dim);
	
	//	Save initial Condition
	// claw.write_results(filename);
	
	//	Run Conservation law
	// claw.run();

/*	//	Read initial condition and store it in state
	vector<double> state;
	claw.get_state(state);

	// 	Print the initial condition
	std::cout<<" \n		----------	Initial Condition	----------	 \n";
      	std::copy(state.begin(), state.end(), std::ostream_iterator<double>(std::cout, " \n"));
	std::cout<<"\n";
//*/

	return 0;
};


