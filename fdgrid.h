// Author:	Juan Pablo Gallego Valencia
// Created:	May 2015


#include<iostream>
#include<vector>

// One dimensional implementation of a finite difference grid

class FD_grid{
	int num_nodes;		// when zero use node_space
	double initial_node;	// where to start the grid
	double final_node;		// where to end the grid
	double node_space; 		// when zero use num_nodes
	std::vector<double> nodes;	// vector with the nodes
   public:
	FD_grid(void);
	FD_grid(double,double,int);
	FD_grid(double,double,double);
	void set_param(double initial_node, double final_node, int num_nodes);		// set the parameters of the grid
	void set_param(double initial_node, double final_node, double node_space);	// set the parameters of the grid
	void set_nodes(void);								// set the nodes of the grid
	void set_nodes(std::vector<double>);
	int get_num_nodes(void);
	void get_nodes(std::vector<double>&);						// get the nodes
	void move_nodes(std::vector<double>);
};


FD_grid::FD_grid(){

	num_nodes = 0;		// when zero use node_space
	initial_node = 0;	// where to start the grid
	final_node = 1;		// where to end the grid
	node_space = 0; 		// when zero use num_nodes
};

FD_grid::FD_grid(double x0, double xf, int n){

	num_nodes = n;		// when zero use node_space
	initial_node = x0;	// where to start the grid
	final_node = xf;		// where to end the grid
	node_space = 0; 		// when zero use num_nodes
};

FD_grid::FD_grid(double x0, double xf, double dx){

	num_nodes = 0;		// when zero use node_space
	initial_node = x0;	// where to start the grid
	final_node = xf;		// where to end the grid
	node_space = dx; 		// when zero use num_nodes
};


void FD_grid::set_param(double x0, double xf, int n) // set parameters for a grid with number of nodes
{
	initial_node=x0;
	final_node=xf;
	num_nodes=n;
};

void FD_grid::set_param(double x0, double xf, double dx) // set parameters for a grid with space between nodes
{
	initial_node=x0;
	final_node=xf;
	node_space=dx;
};

void FD_grid::set_nodes(void) // create a 1d vector of nodes based on number of nodes or space between them
{
	if(node_space==0)
	{
		node_space=(final_node-initial_node)/(num_nodes-1);
	}
	double x=initial_node;
	nodes.push_back(x);
	while (x+node_space<final_node)
	{
		x=x+node_space;
		nodes.push_back(x);
	}
	nodes.push_back(final_node);
	num_nodes=nodes.size();
};

void FD_grid::set_nodes(std::vector<double> v) // create a 1d vector of nodes based on number of nodes or space between them
{
	nodes=v;
};

int FD_grid::get_num_nodes(){ // return the number of nodes of a 1d grid
	return num_nodes;
};

void FD_grid::get_nodes(std::vector<double> &v){	// return a vector containing the 1d nodes of a grid
	v=nodes;
};

void FD_grid::move_nodes(std::vector<double> dn){
	for(unsigned int i=0;i++;i<=nodes.size())
	{
		nodes[i]+=dn[i];
	}
};
