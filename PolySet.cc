#include"PolySet.h"

//using namespace std;

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

void Monomial::write_monomial()
{
//  cout<< "\n \t" << "y = " << coef << "*" << name << "^" << order;
  cout<< coef << "*" << name << "^" << order;


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


void PolyBasis::write_PolyBasis()
{
  Monomial temp;
  cout << "\n \t Polynomial Basis \n \t M = { ";
    for(unsigned int i=0;i<basis.size();i++)
    {
      temp = basis[i];
      temp.write_monomial();
      cout << " ("<<temp.get_id()<<"), ";
    }
    cout << "} \n";
};

