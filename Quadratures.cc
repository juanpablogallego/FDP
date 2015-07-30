#include"Quadratures.h"
#include"utilities.h"
#include"PolySet.h"

vector<double> GaussQuadratureNodes ( int p)
{
  vector<double> points(p);
  switch(p)
  {
    case 1:
    {
      points = {0};
    }
    case 2:
    {
      points = {1.0/sqrt(3), -1.0/sqrt(3)};
      return points;
    }
    case 3:
    {
      points = {-sqrt(3.0/5.0), 0.0, sqrt(3.0/5.0)};
      return points;
    }
    case 4:
    {
      double a = 3.0/7.0, b = sqrt(6.0/5.0), c = 2.0/7.0;
      points = {-sqrt(a +c*b), -sqrt(a -c*b), sqrt(a -c*b), sqrt(a +c*b)};
      return points;
    }
    case 5:
    {
      points = {-sqrt(5 +sqrt(6/5)*2)/3, -sqrt(5 -sqrt(6/5)*2)/3, 0, sqrt(5 -sqrt(6/5)*2)/3, sqrt(5 +sqrt(6/5)*2)/3};
      return points;
    }
  }
};

vector<double> GaussQuadratureWeights(vector<double> & nodes)
{
  int p = nodes.size();
  vector<double> weights(p);
  vector<vector<double> >  Legendre = LegendreCoefficients(p);
  vector<double> poly = Legendre[p];
  diff(poly);
  
  for(unsigned int i = 0; i < p; i++)
  {
    double f_xi = poly_eval(poly, nodes[i]);
    weights[i]=2/((1-nodes[i]*nodes[i])*(f_xi*f_xi));
  }
  return weights;
};