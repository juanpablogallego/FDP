#include<iostream>
#include<vector>

#include"fdgrid.h"
#include"fe_definitions.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------------------
//		Classes for the domain discretzation in cells
//--------------------------------------------------------------------------------------------------------------------

template<typename PolyBasisCoef>
class Cell				// General class
{
  int dim, num_corners, 
      num_edges, num_faces, 		// parameters of the general class
      cell_id, ref_level;	
  vector<int> corners;			// Template parameter can be eather int for 1D or vectors for 2 and 3D
  vector<int> neighbors;		// can be ordered left 0, right 1, botom 2, top 3, front 4, behind 5
  vector<int> edges;
  vector<int> faces;
  PolyBasisCoef coef;
public:
  Cell();						// Constructors
  Cell(int, vector<int>&,vector<int>&); 		// Put this line to add the coefficients , PolyBasisCoef
  
  void set_corners(vector<int>&);			// Set functions
  void set_neighbours(vector<int>&);
  void set_edges(vector<int>&);
  void set_faces(vector<int>&);
  void set_coef(vector<double>&);
  
  int get_id();
  vector<int> get_corners();				// Get Functions
  vector<int> get_neighbours();
  vector<int> get_edges();
  vector<int> get_faces();
  vector<double> get_coef();
};

	  // TODO: Fill the constructors for the cell class

template<typename PolyBasisCoef>
Cell<PolyBasisCoef>::Cell()
{

};

//	One dimensional constructors
template<typename PolyBasisCoef>
Cell<PolyBasisCoef>::Cell (int _id, vector< int >& _corners, vector< int >& _neighbors) //, PolyBasisCoef _coef
{
  cell_id = _id;
  neighbors =_neighbors;
  corners = _corners;
  //coef = _coef;
};


//-----------------------------------------------------------
//		Set Functions
//-----------------------------------------------------------

template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_corners(vector<int>& _corners)
{
  corners=_corners;
};

template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_neighbours(vector<int>& _neighbors)
{
  neighbors=_neighbors;
};

template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_edges(vector<int>& _edges)
{
  edges=_edges;
};

template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_faces(vector<int>& _faces)
{
  faces=_faces;
};

template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_coef(vector<double>& _coef)
{
  coef=_coef;
};

//-----------------------------------------------------------
//		Get Functions
//-----------------------------------------------------------
template<typename PolyBasisCoef>
int Cell<PolyBasisCoef>::get_id()
{
  return cell_id;
};

template<typename PolyBasisCoef>
vector<int> Cell<PolyBasisCoef>::get_corners()
{
  return corners;
};

template<typename PolyBasisCoef>
vector<int> Cell<PolyBasisCoef>::get_neighbours()
{
  return neighbors;
};

template<typename PolyBasisCoef>
vector<int> Cell<PolyBasisCoef>::get_edges()
{
  return edges;
};

template<typename PolyBasisCoef>
vector<int> Cell<PolyBasisCoef>::get_faces()
{
  return faces;
};

template<typename PolyBasisCoef>
vector<double> Cell<PolyBasisCoef>::get_coef()
{
  return coef;
};

//-----------------------------------------------------------
//		Square type of cells
//-----------------------------------------------------------

template<typename PolyBasisCoef>
class Square : Cell<PolyBasisCoef>
{
    int dim, num_corners, 
	num_edges, num_faces, 		// parameters of the general class
	cell_id, ref_level;
  int parent;				// Parent in case of refinement
  vector<int> corners;			// Should be of size 4 
  vector<int> neighbors;		// can be ordered left 0, right 1, botom 2, top 3.
  vector<int> edges;			// Edges of the square
  vector<int> child;			// Children in case of refinement
  PolyBasisCoef coef;
public:
  Square();
  Square(vector<int>&, vector< int >& , PolyBasisCoef );
};

template<typename PolyBasisCoef>
Square<PolyBasisCoef>::Square()
{
  dim=2; num_corners=4; num_edges=4; num_faces= ref_level=0;
};

template<typename PolyBasisCoef>
Square<PolyBasisCoef>::Square ( vector< int >& _corners, vector< int >& _neighbors, PolyBasisCoef _coef)
{
  Square();
  corners=_corners;
  neighbors = _neighbors;
  coef = _coef;
};

//--------------------------------------------------------------------------------------------------------------------
//		Finite Element Grid
//--------------------------------------------------------------------------------------------------------------------

template <typename Points, typename TypeBasis, typename TypeBasisCoef>
class FE_grid : FD_grid
{
  int dim, num_cells;
  vector<Points> Nodes;
  vector<vector<int> > Triangulation;			// Tree that determines the neighbours of each Cell
  vector<Cell<TypeBasisCoef> > Grid;			// Colection of cells conforming the grid
  GeneralPolyBasis<TypeBasis, TypeBasisCoef> PolyBasis;	// Polynomial Basis
public:
    FE_grid ( );
    FE_grid (vector<Points>&);
    FE_grid (vector<Points>&, vector<vector<int> >&);
    FE_grid (vector<Points>&, vector<vector<int> >&, GeneralPolyBasis<TypeBasis, TypeBasisCoef>&);
    void set_nodes(vector<Points>&);
    void set_triangulation(vector<vector<int> >&);
    void set_polybasis(GeneralPolyBasis<TypeBasis, TypeBasisCoef>&);
    void set_grid(); 					// Should be generated internally, no need for argument vector<Cell<TypeBasisCoef> > &
    void set_1d_grid();
    void generate_triangulation();
};

template <typename Points, typename TypeBasis, typename TypeBasisCoef>
FE_grid<Points, TypeBasis, TypeBasisCoef>::FE_grid()
{

};

//		TODO: Fill in all the constructors to read the triangulation and the polynomial basis

template <typename Points, typename TypeBasis, typename TypeBasisCoef>
FE_grid<Points, TypeBasis, TypeBasisCoef>::FE_grid(vector<Points>& _nodes)
{
  Nodes = _nodes;
  set_1d_grid();
};

template <typename Points, typename TypeBasis, typename TypeBasisCoef>
FE_grid<Points, TypeBasis, TypeBasisCoef>::FE_grid(vector<Points>& _nodes, vector<vector<int> >& _triang)
{
  Nodes = _nodes;
  Triangulation = _triang;
};

template <typename Points, typename TypeBasis, typename TypeBasisCoef>
FE_grid<Points, TypeBasis, TypeBasisCoef>::FE_grid(vector<Points>& _nodes, vector<vector<int> >& _triang, GeneralPolyBasis<TypeBasis, TypeBasisCoef>& _basis)
{
  Nodes = _nodes;
  Triangulation = _triang;
  PolyBasis = _basis;
};