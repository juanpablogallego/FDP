#include<iostream>
#include"cons_law.h"
#include"fdgrid.h"
#include<iterator>
#include<cstdlib>


int main()
{
	//	Create the 1D grid
      	FD_grid grid(-1,1,30);
      	int dim=1;

	//	Verify if the grid actually works
	int n=grid.get_num_nodes();
      	std::cout<<"Number of nodes: "<< n<<std::endl;
      	std::vector<double> v(n), dn;
      	grid.get_nodes(v);
      	std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " "));
	std::cout<<"\n";
//*/

	//	Create the Conservation Law object
	FD_Conservation_Laws claw(grid, dim);

	//	Read initial condition and store it in state
	std::vector<double> state;
	claw.get_state(state);
	

	// 	Print the initial condition
	std::cout<<" \n		----------	Initial Condition	----------	 \n";
      	std::copy(state.begin(), state.end(), std::ostream_iterator<double>(std::cout, " "));
	std::cout<<"\n";
      	return 0;
}

