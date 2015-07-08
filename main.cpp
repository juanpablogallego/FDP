#include <iostream>
#include<iterator>
#include<cstdlib>
#include"cons_law.h"

int main(int argc, char **argv) {
    //std::cout << "Hello, world!" << std::endl;
    
    	//	Create the 1D grid
      	FD_grid grid(-1,1,31);
      	int dim=1;

	//	Verify if the grid actually works
	int n=grid.get_num_nodes();
      	std::cout<<"Number of nodes: "<< n<<std::endl;
      	std::vector<double> v(n), dn;
      	grid.get_nodes(v);
      	std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " \n"));
	std::cout<<"\n";
//*/

	//	Create the Conservation Law object
	FD_Conservation_Laws claw(grid, dim);

	//	Read initial condition and store it in state
	vector<double> state;
	claw.get_state(state);
	

	// 	Print the initial condition
	std::cout<<" \n		----------	Initial Condition	----------	 \n";
      	std::copy(state.begin(), state.end(), std::ostream_iterator<double>(std::cout, " \n"));
	std::cout<<"\n";
      	return 0;
    
    //return 0;
}
