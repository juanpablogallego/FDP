#include"PolySet.h"

/*
 * 		Contructors and functions from the Monomial, Polynomial and PolyBasis. Plus
 * 	useful functions to deal with polynomials, like polynomial multiplication, differentiation
 * 	and integration.
 */
//------------------------------------------------------------------------------------------------
//		Monomial Class definitions

/*
 * 	Monomial class constructors
 */
Monomial::Monomial()
{
  order=0;
  id=0;
  name='x';
  coef = 1;
};

Monomial::Monomial ( int _order, double _coef)
{
  order = _order;
  coef = _coef;
  id = 0;
  name = 'x';
};

/*
 * 	Set ID of the Monom (might be useful later)
 */
void Monomial::set_id ( int _id)
{
  id=_id;
};

/*
 * 	Get ID of the Monom (might be useful later)
 */
int Monomial::get_id()
{
  return id;
};

/*
 * 	Evaluate the Monom in a double point
 */
double Monomial::eval ( double _value)
{
  double value = coef;
  for(unsigned int i = 0; i < order; ++i)
    value *= _value;
  return value;
};

/*
 * 	Differentiate the Monom
 * 	- It modifies the Monom (CAUTION)
 */
void Monomial::diff()
{
  if(order!=0)
  {
    coef*=order;
    order-=1;
  }
  else
    coef=0;
};

/*
 * 	Write the Monom as a string so I can see what is inside it
 */
void Monomial::write()
{
  if ((order==0)&&(coef!=0))
    cout<<  coef;
  else if((coef > 0)&&(coef!=1.0))
    cout<< coef << "*" << name << "^" << order;
  else if(coef == 0)
    cout << "";
  else if(coef == -1)
    cout<< " - " << name << "^" << order;
  else
    cout<< " "<<coef << "*" <<  name << "^" << order;
};

/*
 * 	Returns the coefficient of the monom
 */
double Monomial::get_coef()
{
  return coef;
};


//------------------------------------------------------------------------------------------------
//		Polynomial Class definitions

/*
 * 	Polynomial class constructors
 */

//	Default constructor
Polynomial::Polynomial()
{
  
};
//	Constructor from a vector
Polynomial::Polynomial ( vector<double> &_coef)
{
  polycoef = _coef;
  for(unsigned int i = 0; i < _coef.size(); i++)
  {
    Monomial temp(i, _coef[i]);
    polynom.push_back(temp);
  }
};

/*
 *	Constructor with a vector and the maximum order
 * 	- It is based on Monomials, might be implemented better just using
 * 	  a vector and ignoring the monomial part, but then a different
 * 	  way to write the polynom must be defined.
 */
Polynomial::Polynomial ( int _max_order, vector<double> &_coef)
{
  polycoef = _coef;
  for(unsigned int i = 0; i<=_max_order, i < _coef.size(); i++)
  {
    Monomial temp(i, _coef[i]);
    polynom.push_back(temp);
  }
};

/*
 * 	Set the Polynomial inside the object, meaning the vector of monomes.
 * 	- It seems the simplest polynom would be just a vector.
 * 	- TODO: Change the Polynomial class to use just vectors.
 */
void Polynomial::set_polynom()
{
  polynom.clear();
  for(unsigned int i = 0; i < polycoef.size(); i++)
  {
    Monomial temp(i, polycoef[i]);
    polynom.push_back(temp);
  }
};

/*
 * 	Set a Polynomial with a specific input vector of coefficients
 */
void Polynomial::set_polynom(vector<double> &_coef)
{
  polycoef=_coef;
  set_polynom();
};

/*
 * 	Evaluates the polynomial in a specific double point
 * 	- It does not depend on the monomials (another reason to
 * 	  eliminate them)
 */
double Polynomial::eval ( double _value)
{
  double value=0.0, power=1.0;
  for(unsigned int i = 0; i < polycoef.size(); i++)
  {
    value+=polycoef[i]*power;
    power*=_value;
  }
  return value;
};

/*
 * 	Return the vector of coeffitients
 */
vector< double > Polynomial::get_coef()
{
  return polycoef;
};

/*
 * 	Differentiate the polynomial
 * 	- CAUTION: Modifies the polynomial.
 * 	- worth to implement without monomes
 */
void Polynomial::diff()
{
  polycoef.clear();
  for(unsigned int i = 0; i < polynom.size(); i++)
  {
    Monomial temp = polynom[i];
    temp.diff();
    polycoef.push_back(temp.get_coef());
    polynom[i]=temp;
  }
};

/*
 * 	Integrate the polynomial
 * 	- CAUTION: Modifies the polynomial.
 * 	- does not use monomes
 */
void Polynomial::integrate()
{
  vector<double> b = polycoef;
  int order = b.size();
  b.push_back(b[order-1]/order);
  for(unsigned int i = order-1; i > 0; i--)
  {
    b[i] = b[i-1]/i;
  }
  b[0] = 0.0;
  set_polynom(b);
};

/*
 * 	Write the Polynomial in a understandable form
 * 	- Uses the write() function of its monomials
 * 	- Since it is a function seldom used, it can the definition
 * 	  of monomials if needed, but the depence sould be eliminated
 */
void Polynomial::write()
{
  Monomial temp;
  for(unsigned int i = 0; i < polynom.size(); i++)
  {
    temp = polynom[i];
    if((i > 0)&&(temp.get_coef()>0))
      cout<<" + ";
    temp.write();
  }
};


//------------------------------------------------------------------------------------------------
//		PolyBasis Class definitions

/*
 * 	Constructor of the Polynomial basis specialized in just monomials x^i
 * 	- It uses the monomial class everywhere
 */
PolyBasis::PolyBasis ( int max_order)
{
  for(unsigned int i=0; i<=max_order; i++)
  {
    Monomial monom(i,1);
    monom.set_id(i);
    basis.push_back(monom);
  }
};

/*
 * 	Evaluate the basis in a double value and returns a double vector
 * 	with the results.
 */
vector< double > PolyBasis::eval ( double _value)
{
  double value;
  vector<double> vector_value;
  Monomial temp;
  for(unsigned int i = 0; i < basis.size(); i++)
  {
    temp = basis[i];
    value=temp.eval(_value);
    vector_value.push_back(value);
  }
  return vector_value;
};

/*
 * 	Write the Polynomial basis in a readable manner.
 * 	- uses monomials
 */
void PolyBasis::write()
{
  Monomial temp;
  cout << "\n \t Polynomial Basis \n \t M = { ";
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


//------------------------------------------------------------------------------------------------
//		General and useful polynomial functions

/*
 * 	Polynomial Multiplication functions
 * 	- Multiplies polynomials using as arguments ether the polynomials
 * 	  or vectors of coefficients
 */

// 	Unsing vector of coeffitients
vector<double> polymult(vector<double> a, vector<double> b)
{
  int size = a.size()+b.size()-1;
  vector<double> c(size, 0.0);
  for(unsigned int i = 0; i < a.size(); i++)
  {
    for(unsigned int j = 0; j < b.size(); j++)
      c[i+j]+=a[i]*b[j];
  }
  return c;
};

//	Using polynomials
Polynomial polymult(Polynomial &a, Polynomial &b)
{
  vector<double> c = polymult(a.get_coef(), b.get_coef());
  Polynomial poly_c(c);
  return poly_c;
};

/*
 * 	Polynomial Integration and differentiation
 * 	- This functions differentiate and integrate the polynomials
 * 	  without modifying them. The result is given as an output
 * 	  polynomial.
 */

Polynomial integrate(Polynomial &a)
{
  vector<double> b = a.get_coef();
  int order = b.size();
  b.push_back(b[order-1]/order);
  for(unsigned int i = order-1; i > 0; i--)
  {
    b[i] = b[i-1]/i;
  }
  b[0] = 0.0;
  Polynomial poly_b(b);
  return poly_b;
};

Polynomial diff(Polynomial &a)
{
  Polynomial b = a;
  b.diff();
  return b;
};
