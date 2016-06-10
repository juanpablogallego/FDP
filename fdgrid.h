// Author:	Juan Pablo Gallego Valencia
// Created:	May 2015

#ifndef __FDGRID_H__
#define __FDGRID_H__

#include<iostream>
#include<vector>

// One dimensional implementation of a finite difference grid

class FD_grid
{
  int num_nodes;		// when zero use node_space
  double initial_node;	// where to start the grid
  double final_node;		// where to end the grid
  double node_space; 		// when zero use num_nodes
  std::vector<double> nodes;	// vector with the nodes
  std::vector<std::vector<double> > nodes2d, nodes3d; // Objects storing nodes in 2 and 3 dimentions
  /*	struct cell{
   *	      unsigned int dim, num_corners;
   *	      std::vector<std::vector<double> > corners;
};//*/
public:
  FD_grid();
  FD_grid(double,double,int);
  FD_grid(double,double,double);
  void set_param(double initial_node, double final_node, int num_nodes);	// set the parameters of the grid
  void set_param(double initial_node, double final_node, double node_space);	// set the parameters of the grid
  void set_nodes(void);								// set the nodes of the grid
  void set_nodes(std::vector<double>);
  int get_num_nodes(void);
  void get_nodes(std::vector<double>&);						// get the nodes
  void get_nodes(std::vector< std::vector<double> >&, int);						// get the nodes
  void create_multid_nodes(int);
  void move_nodes(std::vector<double>);
  double get_dx();
  void export_grid(const char *);
};

#endif