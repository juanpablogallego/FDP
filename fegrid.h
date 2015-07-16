#include<iostream>
#include<vector>
#include"fdgrid.h"



//--------------------------------------------------------------------------------------------------------------------
//		Classes for the polynomial basis functions

template<typename TypeElement>
class Element			// It should be a 
{
  int dim;
  std::vector<int> order;
  TypeElement element;
};

//--------------------------------------------------------------------------------------------------------------------
//		Classes for the domain discretzation in cells
class Cell					// General class
{
  int dim, num_corners, num_edges, num_faces, 	// parameters of the general class
      cell_id, ref_level;	
  std::vector<int> corners;		// Template parameter can be eather int for 1D or vectors for 2 and 3D
  std::vector<int> neighbors;			// can be ordered left 0, right 1, botom 2, top 3, front 4, behind 5
  std::vector<double> TrialFuncCoef;
};

//--------------------------------------------------------------------------------------------------------------------
//		Finite Element Grid
class FE_grid : FD_grid
{
  int dim, num_cells;
public:
  std::vector<Cell> Grid;								// Colection of cells conforming the grid
  std::vector<std::vector<int> > Triangulation;						// Tree that determines the neighbours of each Cell
  template <typename TypeElement> std::vector<Element<TypeElement> > PolyBasis;		// Polynomial Basis
  std::vector<PolyBasis> PolyBasisSet;							// This is weird, could handle a set of different polynomial basis
};