#include<iostream>
#include<vector>
#include<iterator>

#include"PolySet.h"


using namespace std;


int main()
{
  
  //		Monomial tester
  {
  int _order=2;
  double _coef=0.5;
  double x0 = 3;
  Monomial parabola(_order, _coef);
  
  parabola.write_monomial();
  
  double y = parabola.eval(x0);
  
  cout<< "\n \t y(" << x0 <<") = "<< y << "\n";
  
  parabola.diff();
    
  parabola.write_monomial();
  
  y = parabola.eval(x0);
  
  cout<< "\n \t dy(" << x0 <<") = "<< y << "\n";
  }

  //		PolyBasis tester
  {
  PolyBasis Basis(3);
  Basis.write_PolyBasis();
  
  double x0=7;
  
  vector<double> state = Basis.eval(x0);
  
  cout << "\n \t M("<< x0 <<") = {";
  copy(state.begin(), state.end(), std::ostream_iterator<double>(std::cout, ", "));
  cout << "} \n";
  }
  
  return 0;
};