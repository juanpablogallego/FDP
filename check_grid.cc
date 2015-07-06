#include<iostream>
#include<iterator>
#include<cstdlib>
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
	std::vector<double> v(n), dn;

	// Read nodes from the grid object
	grid.get_nodes(v);

	// Output the nodes entry
	std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " "));
	std::cout<<"\n";
	
	// Generate a displacement for the nodes
	/*double alea;
	for(unsigned int j=0; j<grid.get_num_nodes(); j++)
	{
		alea= rand() % 10;
		dn.push_back(alea/10);
	}
	std::cout << "\n displacements: \n";
	std::copy(dn.begin(), dn.end(), std::ostream_iterator<double>(std::cout, " "));//*/

	// Modify the nodes by dn
	/*grid.move_nodes(dn);
	grid.get_nodes(v);
	std::cout << "\n modified nodes: \n";
	std::copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " "));//*/

	// Multi-D nodes
	unsigned int dim=3;
	grid.create_multid_nodes(dim);
	std::vector<std::vector<double> > v1;
	grid.get_nodes(v1,dim);
	for(unsigned int i=0;i<v1.size();i++)
	{
		std::vector<double> aux=v1[i];
        	std::copy(aux.begin(), aux.end(), std::ostream_iterator<double>(std::cout, "\t"));
		std::cout<<"\n";
	}


	return 0;
}
