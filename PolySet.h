#include<iostream>
#include<vector>
#include<string>

using namespace std;


//-----------------------------------------------------------------------------------------------------------
//			Monomial Class 1D

class Monomial
{
  int order;				// order of the monomial
  int id;				// can be useful
 // vector<int> multid_order;		// Order of the monomial as a vector for multi dimensional polynomials
  double coef;				// Coefitient of the monomial
  string name;
public:
  Monomial();
  Monomial(int, double);
  double eval(double);
  void diff();
  void write_monomial();
  void set_id(int);
  int get_id();
};


//-----------------------------------------------------------------------------------------------------------
//			Monomial Class Multi D
/*class MonMultiD
{
  int order;				// order of the monomial
  int id;				// can be useful
  vector<int> multid_order;		// Order of the monomial as a vector for multi dimensional polynomials
  double coef;				// Coefitient of the monomial
  string name;
public:
  Monomial();
  Monomial(int);
  Monomial(vector<int>);
  void set_order(int);
  void set_order(vector<int>);
  double eval(double);
  double eval(vector<double>);
  void diff();
};//*/

//-----------------------------------------------------------------------------------------------------------


/*class Polynomial
{
  vector<double> polycoef;		// Vector coeficient for polylnomials 
  vector<Monomial> Polynom;
public:
  Polynomial();
  Polynomial(vector<Monomial>,vector<double>);
  void diff(int);
  
};//*/

//-----------------------------------------------------------------------------------------------------------

class PolyBasis
{
  int Num_Monomes;
  vector<Monomial> basis;
  vector<double> coef;
public:
  PolyBasis(int);
  void write_PolyBasis();
  vector<double> eval(double);
  
};



//-----------------------------------------------------------------------------------------------------------