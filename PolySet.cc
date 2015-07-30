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
};

/*
 *	Constructor with a vector and the maximum order
 * 	- It is based on Monomials, might be implemented better just using
 * 	  a vector and ignoring the monomial part, but then a different
 * 	  way to write the polynom must be defined.
 */
Polynomial::Polynomial ( int _id, vector<double> &_coef)
{
  polycoef = _coef;
  id=_id;
};

/*
 * 	Set a Polynomial with a specific input vector of coefficients
 */
void Polynomial::set_polynom(vector<double> &_coef)
{
  polycoef=_coef;
  //set_polynom();
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
 * 	- (worth to implement without monomes) -> already done
 */
void Polynomial::diff()
{
  vector<double> _temp_coef=polycoef;
  polycoef.clear();
  for(unsigned int i = 1; i < _temp_coef.size(); i++)
  {
    polycoef.push_back(_temp_coef[i]*i);
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
 * 	Definite integral of the polynomial
 */

double Polynomial::integrate ( double a, double b)
{
  integrate();
  double c =eval(b)- eval(a);
  return c;
};


void Polynomial::set_name ( string _name)
{
  name=_name;
}

/*
 * 	Write the Polynomial in a understandable form
 * 	- Uses the write() function of its monomials
 * 	- Since it is a function seldom used, it can the definition
 * 	  of monomials if needed, but the depence sould be eliminated
 */
void Polynomial::write()
{
  for(unsigned int i = 0; i < polycoef.size(); i++)
  {        
    if((i > 0)&&(polycoef[i]>0))    
      cout<<" + ";
    
    if ((i==0)&&(polycoef[i]!=0))
      cout <<  polycoef[i];
    else if((polycoef[i] > 0)&&(polycoef[i]==1))
      cout << name << "^" << i;
    else if(polycoef[i] == 0)
      cout << "";
    else if(polycoef[i] == -1)
      cout << " - " << name << "^" << i;
    else
      cout << polycoef[i] << "*" <<  name << "^" << i;
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


//	Using polynomials
Polynomial polymult(Polynomial &a, Polynomial &b)
{
  vector<double> c = polymult(a.get_coef(), b.get_coef());
  Polynomial poly_c(b.get_id(), c);
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
  Polynomial poly_b(a.get_id(), b);
  return poly_b;
};

Polynomial diff(Polynomial &a)
{
  Polynomial b = a;
  b.diff();
  return b;
};

void diff(vector<double> &polycoef)
{
  vector<double> _temp_coef=polycoef;
  polycoef.clear();
  for(unsigned int i = 1; i < _temp_coef.size(); i++)
  {
    polycoef.push_back(_temp_coef[i]*i);
  }
};

double poly_element_norm(Polynomial &poly)
{
  Polynomial poly_square = polymult(poly,poly);
  double norm = poly_square.integrate(-1, 1);
  return sqrt(norm);
};

