#include<iostream>
#include<vector>
#include<string>
#include<math.h>

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
  string name = "x";
public:
  Polynomial();
  Polynomial(vector<double>&);
  Polynomial(int,vector<double>&);

  void set_name(string);
  vector<double> get_coef();
  double eval(double);
  void diff();
  void write();
  void integrate();
  double integrate(double, double);
  void set_polynom(vector<double>&);
  
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
/*
 * 		General Polynomial Basis Class 1D
 * 	- All the functions rely on the functions with the same name from the objects
 * 	  BasisFuncType
 */

template<typename BasisFuncType, typename BasicFuncCoef>
class GeneralPolyBasis
{
  int basis_size;
  vector<BasisFuncType> basis;
public:
  GeneralPolyBasis();
  GeneralPolyBasis(int, BasicFuncCoef&);
  void write();
  vector<double> eval(double);
  int get_base_size();
  BasisFuncType get_base(int);
  void poly_mult(BasisFuncType);
  void integrate_base();
  void normalize_base();
};

/*
 *	Class definitions (cannot be added in PolySet.cc because of the templates)
 */

//	Default Constructor
template<typename BasisFuncType, typename BasicFuncCoef>
GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::GeneralPolyBasis (){};

//	Constructor using a vector of coefficients and the maximum order of the polynomial
template<typename BasisFuncType, typename BasicFuncCoef>
GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::GeneralPolyBasis ( int max_order, BasicFuncCoef &_coef)
{
  for(unsigned int i=0; i<=max_order; i++)
  {
    //BasisFuncType element(max_order,_coef[i]);
    BasisFuncType element(_coef[i]);
    
    element.set_id(i+1);
    basis.push_back(element);
  }
  basis_size=basis.size();
};

//	Evaluate the basis functions in a double value
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

//	Return the size of the polynomial basis
template<typename BasisFuncType, typename BasicFuncCoef>
int GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::get_base_size()
{
  return basis_size;
};

//	Return a sible element from the base
template<typename BasisFuncType, typename BasicFuncCoef>
BasisFuncType GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::get_base(int i)
{
  return basis[i];
};

//	Multiply a polynomial with the entire basis
template<typename BasisFuncType, typename BasicFuncCoef>
void GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::poly_mult(BasisFuncType poly)
{
  typedef double Number;
  for(unsigned int i = 0; i < basis_size; i++)
  {
    BasisFuncType _temp = basis[i];
    basis[i]=polymult(poly,_temp);
  }
};

//	Write the basis functions in a understandable manner
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

/*
 * 	Integrates the basis of polynomials
 * 	- relies on the integration of each element (polynomial) of the basis
 */
template<typename BasisFuncType, typename BasicFuncCoef>
void GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::integrate_base()
{
  for(unsigned int i = 0; i < basis_size; i++)
  {
    BasisFuncType poly=basis[i];
    poly.integrate();
    basis[i]=poly;
  }
};


/*
 * 	Normalize the base of polynomials
 */

template<typename BasisFuncType, typename BasicFuncCoef>
void GeneralPolyBasis<BasisFuncType, BasicFuncCoef>::normalize_base()
{
  for(unsigned int i =0; i<basis_size; i++)
    basis[i] = basis[i]/poly_element_norm(basis[i]);
};

/*
 * 	Divition operator between a polynimial and a number
 */
template<typename Number>
Polynomial operator/(Polynomial& a, Number b )
{
  Polynomial poly_c;
  vector<double> c, a_coef=a.get_coef();
  for(unsigned int i=0;i<a_coef.size();i++)
    c.push_back(a_coef[i]/b);
  poly_c.set_polynom(c);
  return poly_c;
};


/*
 * 	Additional functions for polynomials defined en PolySet.cc
 */

template<typename Number>
vector<Number> polymult(vector<Number> , vector<Number> );

//template<typename Number>
Polynomial polymult(Polynomial &, Polynomial &);

Polynomial integrate(Polynomial &);

Polynomial diff(Polynomial &);

//template<typename Number>
//void diff(vector<Number> &);

template<typename Number>
void diff(vector<Number> &polycoef)
{
  vector<Number> _temp_coef=polycoef;
  polycoef.clear();
  for(unsigned int i = 1; i < _temp_coef.size(); i++)
  {
    polycoef.push_back(_temp_coef[i]*i);
  }
};

template<typename Number>
Number poly_element_norm(Polynomial& );
