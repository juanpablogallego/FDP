#include<iostream>

// One dimensional implementation of a finite difference grid

class FD_grid{
	int num_nodes (0);		// when zero use node_space
	double initial_node (0);	// where to start the grid
	double final_node (1);		// where to end the grid
	double node_space (0); 		// when zero use num_nodes
	std::vector<double> nodes (2);	// vector with the nodes
   public:
	void set_param(double initial_node, double final_node, int num_nodes);		// set the parameters of the grid
	void set_param(double initial_node, double final_node, double node_space);	// set the parameters of the grid
	void set_nodes(void)								// set the nodes of the grid
}

void FD_grid::set_param(double x0, double xf, int n)
{
	initial_node=x0;
	final_node=xf;
	num_nodes=n;
}

void FD_grid::set_param(double x0, double xf, double dx)
{
	initial_node=x0;
	final_node=xf;
	node_space=dx;
}

void FD_grid::set_nodes(void)
{
	if(node_space==0)
	{
		node_space=(final_node-initial_node)/num_nodes;
	}
	double x=initial_node;
	while (x<final_node)
	{
		x=x+node_space;
		nodes.pushback(x);
	}
	nodes.pushback(final_node);
}
