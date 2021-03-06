#include"fegrid.h"

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

/*
template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_normal(vector<double> & normal_vector)
{
  normals=normal_vector;
};

template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_center(vector<double> &_center)
{
  center=_center;
};//*/



/*template<typename PolyBasisCoef>
vector<int> Cell<PolyBasisCoef>::get_neighbours()
{
  return neighbors;
};*/

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

template<typename PolyBasisCoef>
vector<vector<double> > Cell<PolyBasisCoef>::get_normals()
{
  return normals;
};

template<typename PolyBasisCoef>
vector<double> Cell<PolyBasisCoef>::get_center()
{
  return center;
};

/*
 * 	make two vectors equal using the operator "="
 */
template<typename PolyBasisCoef>
vector<double> Cell<PolyBasisCoef>::operator=(vector<double> &b)
{
  vector<double> a(b);
  return a;
};

/*
 * -----------------------------------------------------------------------
 *		FE_grid functions
 * ----------------------------------------------------------------------- 
 */

/*template <typename Points, typename TypeBasis, typename TypeBasisCoef>
void FE_grid<Points, TypeBasis, TypeBasisCoef>::set_polybasis(GeneralPolyBasis<Polynomial, vector<double>>& _basis)
{
    PolyBasis = _basis;
};//*/

template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
int FE_grid<Points, TypeBasisCoef>::get_dim()
{
  return dim;
};

template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
int FE_grid<Points, TypeBasisCoef>::get_num_cells()
{
  return num_cells;
};

template <typename Points, typename TypeBasisCoef> //template <typename Points, typename TypeBasis, typename TypeBasisCoef>
TypeBasisCoef FE_grid<Points, TypeBasisCoef>::get_coef_cell(int i)
{
    Cell<TypeBasisCoef> _cell= Grid[i];
    TypeBasisCoef coef = _cell.get_coef();
    return coef;
};
