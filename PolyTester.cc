#include<iostream>
#include<vector>
#include<iterator>

#include"PolySet.h"
#include"utilities.h"

using namespace std;


int main()
{
  
  //		Monomial tester
  /*{
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
  }//*/

  //		PolyBasis tester
  /*{
  PolyBasis Basis(3);
  Basis.write_PolyBasis();
  
  double x0=7;
  
  vector<double> state = Basis.eval(x0);
  
  cout << "\n \t M("<< x0 <<") = {";
  copy(state.begin(), state.end(), std::ostream_iterator<double>(std::cout, ", "));
  cout << "} \n";
  }//*/
  
  //		Polynomial Tester
  /*{
  double order = 2, x0 = 3;
  vector<double> coef;
  coef.push_back(0); coef.push_back(0);coef.push_back(1);
  
  Polynomial poly(order, coef);
  
  double y0 = poly.eval(x0);
  
  cout << "\n \t Polynom \n \t P =  ";
  poly.write();
  cout << "\n";
  
  cout << "\n \t Valuation of the polynomial in x0 = "<< x0 << ": \t y0 = " << y0 << "\n";
  }//*/
  
  //		General Basis tester
  /*{
  
  int order = 4;
  
  vector<vector<double> > coef = LegendreCoefficients(order);

  vector<double> temp;
  
  for(unsigned int i=0; i<coef.size(); i++)
  {
    temp=coef[i];
    cout<<"\n";
    copy(temp.begin(), temp.end(), ostream_iterator<double>(cout, ", "));
  }

  
  /*vector<double> temp;
  temp.push_back(1);//temp.push_back(2);temp.push_back(1);
  coef.push_back(temp);
  temp=coef[0];
  
  cout<<"\n\t"; copy(temp.begin(), temp.end(), std::ostream_iterator<double>(std::cout, ", "));

  
  vector<double> temp1;
  temp1.push_back(0);temp1.push_back(1);//temp1.push_back(1);
  coef.push_back(temp1);
  temp1=coef[1];
  
  cout<<"\n\t"; copy(temp1.begin(), temp1.end(), std::ostream_iterator<double>(std::cout, ", "));  
  
  vector<double> temp2;
  temp2.push_back(0.5);temp2.push_back(0);temp2.push_back(1.5);
  coef.push_back(temp2);
  temp2=coef[2];
  
  cout<<"\n\t"; copy(temp2.begin(), temp2.end(), std::ostream_iterator<double>(std::cout, ", "));//*/

  
  /*GeneralPolyBasis<Polynomial, vector<vector<double> > > Basis(order, coef);
  
  
  Basis.write();
  
  double x0=0.7;
  
  vector<double> state = Basis.eval(x0);
  
  cout << "\n \t M("<< x0 <<") = {";
  copy(state.begin(), state.end(), std::ostream_iterator<double>(std::cout, ", "));
  cout << "} \n";
  }//*/
  
  
  //		Polynomial Multiplication check
  {
    vector<double> a(4,0), b(2,0), c;
    a[0]=0; a[1]=0; a[2]=1; a[3]=2;
    b[0]=1; b[1]=1;
    
    Polynomial poly_a(a), poly_b(b), poly_c = polymult(poly_a, poly_b);
    poly_c.write();
    cout<<"\n";
    
    poly_a = diff(poly_c);
    poly_a.write();
    cout<<"\n";
    //poly_c.diff();
    poly_c.write();
    
  }//*/

  return 0;
};