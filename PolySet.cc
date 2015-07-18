#include"PolySet.h"


//------------------------------------------------------------------------------------------------
//		Monomial Class definitions

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

void Monomial::set_id ( int _id)
{
  id=_id;
};

int Monomial::get_id()
{
  return id;
};

double Monomial::eval ( double _value)
{
  double value = coef;
  for(unsigned int i = 0; i < order; ++i)
    value *= _value;
  return value;
};

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

double Monomial::get_coef()
{
  return coef;
};


//------------------------------------------------------------------------------------------------
//		Polynomial Class definitions

Polynomial::Polynomial()
{
  
};

Polynomial::Polynomial ( vector<double> &_coef)
{
  polycoef = _coef;
  for(unsigned int i = 0; i < _coef.size(); i++)
  {
    Monomial temp(i, _coef[i]);
    polynom.push_back(temp);
  }
};

Polynomial::Polynomial ( int _max_order, vector<double> &_coef)
{
  polycoef = _coef;
  for(unsigned int i = 0; i<=_max_order, i < _coef.size(); i++)
  {
    Monomial temp(i, _coef[i]);
    polynom.push_back(temp);
  }
};

double Polynomial::eval ( double _value)
{
  double value=0.0, power=1.0;
  for(unsigned int i = 0; i < polycoef.size(); i++)
  {
    value+=polycoef[i]*power;
    power*=_value;
  }
  return value;
  
  /*double value=0;
  for(unsigned int i = 0; i < polynom.size(); i++)
  {
    Monomial temp = polynom[i];
    value+=temp.eval(_value);
  }
  return value;//*/
};

vector< double > Polynomial::get_coef()
{
  return polycoef;
};



void Polynomial::diff()
{
  for(unsigned int i = 0; i < polynom.size(); i++)
  {
    Monomial temp = polynom[i];
    temp.diff();
    polynom[i]=temp;
  }
};

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

PolyBasis::PolyBasis ( int max_order)
{
  for(unsigned int i=0; i<=max_order; i++)
  {
    Monomial monom(i,1);
    monom.set_id(i);
    basis.push_back(monom);
  }
};

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

/*
 * 	Polynomial Multiplication function
 */

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


Polynomial polymult(Polynomial &a, Polynomial &b)
{
  vector<double> c = polymult(a.get_coef(), b.get_coef());
  Polynomial poly_c(c);
  return poly_c;
};

Polynomial diff(Polynomial &a)
{
  Polynomial b = a;
  b.diff();
  return b;
};
