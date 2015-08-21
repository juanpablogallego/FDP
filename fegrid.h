#include<iostream>
#include<vector>

#include"fdgrid.h"

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
  vector<double> center;
  vector<double> normals;		// normal vectors in each "important" interface
  PolyBasisCoef coef;
public:
  Cell();						// Constructors
  Cell(int&, vector<int>&,vector<int>&); 		// Put this line to add the coefficients , PolyBasisCoef
  
  void set_corners(vector<int>&);			// Set functions
  void set_neighbours(vector<int>&);
  void set_edges(vector<int>&);
  void set_faces(vector<int>&);
  void set_coef(vector<double>&);
  void set_normal(vector<double>&);
  void set_center(vector<double>&);
  
  int get_id();
  vector<int> get_corners();				// Get Functions
  vector<int> get_neighbours();
  vector<int> get_edges();
  vector<int> get_faces();
  vector<double> get_coef();
  vector<vector<double> > get_normals();
  vector<double> get_center();
  
  vector<double> operator=(vector<double> &);
};

	  // TODO: Fill the constructors for the cell class

template<typename PolyBasisCoef>
Cell<PolyBasisCoef>::Cell()
{

};

//	One dimensional constructors
template<typename PolyBasisCoef>
Cell<PolyBasisCoef>::Cell ( int& _id, vector< int >& _corners, vector< int >& _neighbors) //, PolyBasisCoef _coef
{
  cell_id = _id;
  corners = _corners;
  neighbors = _neighbors;
  //coef = _coef;
};


//-----------------------------------------------------------
//		Set Functions
//-----------------------------------------------------------


template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_normal(vector<double> & normal_vector)
{
  normals=normal_vector;
};

template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_center(vector<double> &_center)
{
  center=_center;
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
vector<int> Cell<PolyBasisCoef>::get_neighbours()
{
  return neighbors;
};

template<typename PolyBasisCoef>
vector<int> Cell<PolyBasisCoef>::get_corners()
{
  return corners;
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


template <typename Points, typename TypeBasisCoef> // typename TypeBasis,
class FE_grid //: public FD_grid
{
  double dx;						// Minimum dx of the grid
  int p, dim, num_cells;
  vector<Points> Nodes;
  vector<vector<int> > Triangulation;			// Tree that determines the neighbours of each Cell
  vector<Cell<TypeBasisCoef> > Grid;			// Colection of cells conforming the grid
public:
    //GeneralPolyBasis<TypeBasis, TypeBasisCoef> PolyBasis;	// Polynomial Basis
    FE_grid ( );
    FE_grid ( double, double, int );
    FE_grid (vector<Points>&);
    FE_grid (vector<Points>&, vector<vector<int> >&);
    //FE_grid (vector<Points>&, vector<vector<int> >&, GeneralPolyBasis<TypeBasis, TypeBasisCoef>&);
    void set_nodes(vector<Points>&);
    void set_nodes_1d(double, double, int);
    void set_triangulation();
    //void set_polybasis(GeneralPolyBasis<TypeBasis, TypeBasisCoef>&);
    //void set_polybasis(GeneralPolyBasis<Polynomial, vector<double>>&);
    void set_grid(); 					// Should be generated internally, no need for argument vector<Cell<TypeBasisCoef> > &
    void set_1d_grid();
    void generate_triangulation();
    
    int get_dim();
    int get_num_cells();
    vector<Points> get_nodes();
    double get_min_dx();
    vector<vector<int>> get_triangulation();
    
    /*
     * 	Functions to modify and obtain values directly from a specific cell in the vector Grid.
     */
    
    void set_coef_cell(int, TypeBasisCoef &);
    TypeBasisCoef get_coef_cell(int);
    vector<int> get_corners(int);

};

template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
FE_grid<Points, TypeBasisCoef>::FE_grid()
{

};

//		TODO: Fill in all the constructors to read the triangulation and the polynomial basis

template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
FE_grid<Points, TypeBasisCoef>::FE_grid(vector<Points>& _nodes)
{
  Nodes = _nodes;
  set_1d_grid();
  set_triangulation();
};

template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
FE_grid<Points, TypeBasisCoef>::FE_grid ( double initpoint, double endpoint, int numnodes)
{
  set_nodes_1d(initpoint, endpoint, numnodes);
  set_1d_grid();
  set_triangulation();
};


template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
FE_grid<Points, TypeBasisCoef>::FE_grid(vector<Points>& _nodes, vector<vector<int> >& _triang)
{
  Nodes = _nodes;
  Triangulation = _triang;
};

template <typename Points, typename TypeBasisCoef> //template  <typename Points, typename TypeBasis, typename TypeBasisCoef>
vector<Points> FE_grid<Points, TypeBasisCoef>::get_nodes()
{
  return Nodes;
};


template <typename Points, typename TypeBasisCoef> //template  <typename Points, typename TypeBasis, typename TypeBasisCoef>
vector<vector<int>> FE_grid<Points, TypeBasisCoef>::get_triangulation()
{
  return Triangulation;
};

template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
double FE_grid<Points, TypeBasisCoef>::get_min_dx()
{
  return dx;
};

template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
vector<int> FE_grid<Points, TypeBasisCoef>::get_corners(int i)
{
    Cell<TypeBasisCoef> _cell= Grid[i];
    vector<int> corners = _cell.get_corners();
    return corners;
};


template <typename Points, typename TypeBasisCoef> //template  <typename Points, typename TypeBasis, typename TypeBasisCoef>
void FE_grid<Points, TypeBasisCoef>::set_nodes_1d(double initial_node, double final_node, int num_nodes)
{
  double node_space=(final_node-initial_node)/(num_nodes-1);
  double x=initial_node;
  Nodes.push_back(x);
  while (x+node_space<final_node)
  {
    x=x+node_space;
    Nodes.push_back(x);
  }
  num_nodes=Nodes.size();
  Nodes[num_nodes-1]= final_node;
  cout<< "\n \t Number of nodes: " << num_nodes;
  cout<< "\n \t Space between nodes: " << node_space;

};


template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
void FE_grid<Points, TypeBasisCoef>::set_1d_grid()
{
  dx = 1.0e14;
  for(unsigned int i = 0; i < Nodes.size()-1; i++)
  {
    int id = i;
    std::vector<int> cell_nodes, neighbors;
    cell_nodes.push_back(i);
    cell_nodes.push_back(i+1);
    
    double diametro = Nodes[i+1]-Nodes[i];
    dx = (dx < diametro)? dx : diametro;		// Set the smallest cell diameter
    
    vector<double> center, norms;
    center.push_back((Nodes[i+1]+Nodes[i])/2);
    norms.push_back(-1); norms.push_back(1);
    neighbors.push_back(i-1);
    neighbors.push_back(i+1);
    
    Cell<TypeBasisCoef> _cell(id, cell_nodes, neighbors);
    _cell.set_center(center);
    _cell.set_normal(norms);
    
    Grid.push_back(_cell);
  }
  num_cells = Grid.size();
};

template <typename Points, typename TypeBasisCoef> //template  <typename Points, typename TypeBasis, typename TypeBasisCoef>
void FE_grid<Points, TypeBasisCoef>::set_triangulation()
{
  for(unsigned int i = 0; i < Grid.size(); i++)
  {
    Cell<vector<double>> _cell = Grid[i];
    vector<int> neighbor = _cell.get_neighbours();
    Triangulation.push_back(neighbor);
  }
};

template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
void FE_grid<Points, TypeBasisCoef>::set_coef_cell(int i, TypeBasisCoef & _coef)
{
  Cell<TypeBasisCoef> _cell= Grid[i];
  _cell.set_coef(_coef);
};