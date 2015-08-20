#include<math.h>

#include"initial_condition.h"

void step1D(std::vector<double> &x, std::vector<double> &u0)
{
  for(unsigned int i = 0; i<x.size(); i++)
  {
    if(x[i]<0)
      u0[i]=2;
    else
      u0[i]=1;    
  }
};

void gaussian(std::vector<double> &x, std::vector<double> &u0)
{
  for(unsigned int i = 0; i < x.size(); i++)
  {
    double x0 = -x[i]*x[i];
    x0 = exp(x0);
    u0.push_back(x0);
  }
};



