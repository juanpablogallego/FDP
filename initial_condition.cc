#include<math.h>

#include"initial_condition.h"

void eval_step1D (std::vector<double> &x, std::vector<double> &u0)
{
  for(unsigned int i = 0; i<x.size(); i++)
  {
    if(x[i]<0)
      u0[i]=2;
    else
      u0[i]=1;    
  }
};

void eval_gaussian(std::vector<double> &x, std::vector<double> &u0)
{
  for(unsigned int i = 0; i < x.size(); i++)
  {
    double x0 = -x[i]*x[i];
    x0 = exp(x0);
    u0.push_back(x0);
  }
};

void eval_sin(std::vector<double> &x, std::vector<double> &u0)
{
  for(unsigned int i = 0; i < x.size(); i++)
  {
    u0.push_back(sin(x[i]));
  }
};

double eval_step1D (double x)
{
  double u0;
  if(x<0)
    return u0=2;
  else
    return u0=1;
};

double eval_gaussian(double x)
{
    double u0 = -x*x;
    return u0 = exp(u0);
};
