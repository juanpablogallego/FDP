#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Monomial
{
  int order, id;
  vector<int> multid_order;
  double coef;
  vector<double> multid_coef;
  string name;
public
  Monomial();
  Monomial(int);
  Monomial(vector<int>);
  void set_order(int);
  void set_order(vector<int>);
  double eval(double);
  double eval(vector<double>);
  void diff();
  void diff(int);
};

class PolyBasis
{
  
  int Num_Monomes;
  vector<Monomial> basis;
  
};
