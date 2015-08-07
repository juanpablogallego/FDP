// Author:	Juan Pablo Gallego Valencia
// Created:	July 2015

#include<iostream>
#include<iterator>
#include<cstdlib>
#include<string.h>

//#include"fdgrid.h"
#include"cons_law.h"
#include"fegrid.h"

int main(int argc, char **argv) {
	
	//Create the 1D grid
	int dim=1;
	FD_grid grid (-5,5,101);

/*	//	Verify if the grid actually works
	int n=grid.get_num_nodes();
      	std::cout<<"Number of nodes: "<< n<<std::endl;
      	std::vector<double> v(n);
      	grid.get_nodes(v);
      	std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " \n"));
	std::cout<<"\n";
//*/

	//	Create the Conservation Law object
	FD_Conservation_Laws claw(grid, dim);
	
	//	Save initial Condition
	const char *filename = "burgers_ic.dat";
	claw.write_results(filename);
	
	//	Run Conservation law
	claw.run();

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


