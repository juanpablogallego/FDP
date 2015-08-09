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

template<typename PolyBasisCoef>
void Cell<PolyBasisCoef>::set_coef(vector<double>& _coef)
{
  coef=_coef;
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

template <typename Points, typename TypeBasis, typename TypeBasisCoef>
void FE_grid<Points, TypeBasis, TypeBasisCoef>::set_1d_grid()
{
  for(unsigned int i = 0; i < Nodes.size()-1; i++)
  {
    int id = i;
    std::vector<double> cell_nodes, neighbor, coef;
    cell_nodes.push_back(Nodes[i]);
    cell_nodes.push_back(Nodes[i+1]);
    
    neighbor.push_back(i-1);
    neighbor.push_back(i+1);
    
    Cell<TypeBasisCoef> _cell(id, cell_nodes, coef);
    
    Grid.push_back(_cell);
  }
};