#include<iostream>

template <typename Number>
Number MapJacobian1D(Number a, Number b)
{
  Number jacob=2/(a-b);
  return jacob;
};

template <typename Number>
Number B2FMapPonit1D( Number psi, Number a, Number b)
{
  Number m = (b-a)/2, psi0=(a+b)/2, x;
  return x = m*psi + psi0;
};

template <typename Number>
Number F2BMapPonit1D( Number x, Number a, Number b)
{
  Number m = 2/(b-a), x0=(a+b)/(b-a), psi;
  return psi = m*x - x0;
};