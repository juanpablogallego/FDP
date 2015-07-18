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
  void write();
  void set_id(int);
  int get_id();
  double get_coef();
};

//-----------------------------------------------------------------------------------------------------------
//			Polynomial Class 1D

class Polynomial : public Monomial
{
  vector<double> polycoef;		// Vector coeficient for polylnomials 
  int max_order;
  int id;
  vector<Monomial> polynom;
public:
  Polynomial();
  Polynomial(vector<double>&);
  Polynomial(int, vector<double>&);

  //void set_id(int);
  vector<double> get_coef();
  double eval(double);
  void diff();
  void write();
  
};

//-----------------------------------------------------------------------------------------------------------
//			Monomial Basis Class 1D

class PolyBasis
{
  vector<Monomial> basis;
  vector<Polynomial> basis_p;
  vector<double> coef;
public:
  PolyBasis(int);
  void write();
  vector<double> eval(double);
};
//-----------------------------------------------------------------------------------------------------------
//			General Polynomial Basis Class 1D

template<typename BasisFuncType, typename BasicFuncCoef>
class GeneralPolyBasis
{
  vector<BasisFuncType> basis;
  //vector<BasicFuncCoef> coef;
public:
  GeneralPolyBasis(int, BasicFuncCoef&);
  void write();
  vector<double> eval(double);
};

//		Class definitions

template<typename BasisFuncType, typename BasicFuncCoef>
GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::GeneralPolyBasis ( int max_order, BasicFuncCoef &_coef)
{
  for(unsigned int i=0; i<=max_order; i++)
  {
    BasisFuncType element(max_order,_coef[i]);
//    BasisFuncType element(i,_coef[i]);
    element.set_id(i+1);
    basis.push_back(element);
  }
};

template<typename BasisFuncType, typename BasicFuncCoef>
void GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::write()
{
  BasisFuncType temp;
  cout << "\n \t Polynomial Basis \n \t V = { ";
    for(unsigned int i=0;i<basis.size();i++)
    {
      temp = basis[i];
      temp.write();
      cout << " ("<<temp.get_id()<<")";
      if(i<basis.size()-1)
	cout << ", ";
    }
    cout << "} \n";
};

template<typename BasisFuncType, typename BasicFuncCoef>
vector<double> GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::eval ( double _value)
{
  double value;
  vector<double> vector_value;
  BasisFuncType temp;
  for(unsigned int i = 0; i < basis.size(); i++)
  {
    temp = basis[i];
    value=temp.eval(_value);
    vector_value.push_back(value);
  }
  return vector_value;
};

vector<double> polymult(vector<double> a, vector<double> b);

Polynomial polymult(Polynomial &a, Polynomial &b);

Polynomial diff(Polynomial &a);

//*/