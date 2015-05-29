#include<iostream>
#include<iterator>
#include"fdgrid.h"

int main()
{
	//double x0=0, xf=1; int n=21; //dx=0.1;
	FD_grid grid(0, 2, 0.5);
	//grid.set_param(x0,xf,dx);
	//grid.set_param(x0,xf,n);
	grid.set_nodes();
	//int
	int n=grid.get_num_nodes();
	std::cout<<"Number of nodes: "<< n<<std::endl;
	std::vector<double> v(n);
	grid.get_nodes(v);

	std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " "));

	return 0;
}
