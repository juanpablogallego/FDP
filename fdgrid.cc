#include<iostream>
#include<fstream>
#include<string>
#include"fdgrid.h"

/*
 *	Constructors
 */
FD_grid::FD_grid()
{
  num_nodes = 0;		// when zero use node_space
  initial_node = 0;	// where to start the grid
  final_node = 1;		// where to end the grid
  node_space = 0; 		// when zero use num_nodes
};

FD_grid::FD_grid(double x0, double xf, int n)
{
  num_nodes = n;		// when zero use node_space
  initial_node = x0;	// where to start the grid
  final_node = xf;		// where to end the grid
  node_space = 0; 		// when zero use num_nodes
  set_nodes();
};

FD_grid::FD_grid(double x0, double xf, double dx)
{
  num_nodes = 0;		// when zero use node_space
  initial_node = x0;	// where to start the grid
  final_node = xf;		// where to end the grid
  node_space = dx; 		// when zero use num_nodes
  set_nodes();
};

/*
 *	Set parameters to the grid object depending on what is given
 */

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

/*
 * 	Create a 1D vector of nodes based on number of nodes or space between them
 */
void FD_grid::set_nodes(void) // 
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

/*
 *	Set a specific vector of values as nodes
 */

void FD_grid::set_nodes(std::vector<double> v) 
{
  nodes=v;
};

/*
 * 	Return the number of nodes of a 1d grid
 */
int FD_grid::get_num_nodes()
{
  return num_nodes;
};

/*
 *	Return a vector containing the 1d nodes of a grid
 */
void FD_grid::get_nodes(std::vector<double> &v)
{
  v=nodes;
};

/*
 *	Return a vector containing the 1d nodes of a grid
 */
void FD_grid::get_nodes(std::vector<std::vector<double> > &v, int d)	
{
  switch(d)
  {
    case 2:
      v=nodes2d;
      break;
    case 3:
      v=nodes3d;
      break;
    default:
      std::cout<< " \n ------ Not a valid dimension (so far) ------ \n";
  }
};

/*
 * 	Create a Cartesian and equidistant multi-D grid based on the entries of nodes
 */
void FD_grid::create_multid_nodes(int des_dim)
{
  if(des_dim==2)
  {
    std::vector<double> entry2(2);
    for(unsigned int i=0;i<nodes.size();i++)
    {
      for(unsigned int j=0;j<nodes.size();j++)
      {
	entry2[0] = nodes[j]; entry2[1]= nodes[i];
	nodes2d.push_back(entry2);
      }
    }
  }
  else if(des_dim==3)
  {
    std::vector<double> entry3(3);
    for(unsigned int i=0;i<nodes.size();i++)
    {
      for(unsigned int j=0;j<nodes.size();j++)
      {
	for(unsigned int k=0;k<nodes.size();k++)
	{
	  entry3[0] = nodes[k]; entry3[1] = nodes[j]; entry3[2] = nodes[i];
	  nodes3d.push_back(entry3);
	}
      }
    }
  }
  else
  { 
    std::cout<< " \n ------ Not a valid dimension (so far) ------ \n";
  }
  
};

/*
 * 	Returns the value of the distance between nodes
 */
double FD_grid::get_dx()
{
  return node_space;
}

/*
 * 	Modify the vector of nodes adding a dn vector
 */
void FD_grid::move_nodes(std::vector<double> dn)
{
  for(unsigned int i=0;i<=nodes.size();i++)
  {
    nodes[i]+=dn[i];
  }
};

/*void FD_grid::export_grid(const char *file_name)
{
  std::ifstream grid_file;
  grid_file.open(file_name);
  
  grid_file << "# Nodes \n";
  for(unsigned int i=0; i<num_nodes; i++)
  {
    grid_file << i << "\t"<< nodes[i]<<"\n";
  }
  
  grid_file.close();
};//*/

