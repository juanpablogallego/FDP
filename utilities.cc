// Author:	Juan Pablo Gallego Valencia
// Created:	July 2015

#include<vector>
#include<string>
#include<sstream>
#include<iterator>
#include<iostream>
#include <cmath>

using namespace std;

/*
 * 		Utility functions to ease my life with coding, general functions that can be
 * 	useful in the whole program.
 */




/*
 * 	Returns the maximum entrance of a vector
 */
template<typename Number>
Number MyMaxEntry(vector<Number>& vector)
{
  Number a=vector[0];					// Store the first value of the vector
  for(unsigned int i=1; i<vector.size(); i++)		// Sweep the vector
    a=(a>vector[i]?a:vector[i]);			// Store the maximum between elements of the vector
  return a;						// Return the maximum value
};

/*
 * 	Genrate the name of a file for a sequence of outputs
 * 	- Input	: Root name, extrension of the file, width of digits in the file
 * 	- Output: const char* formated name of a file	
 */
const char * Gen_Seq_File_Names(string root_name, string extension, int width, int seq_name)
{
  string full_name;				// Container for the full name
  ostringstream temp_seq;				// Auxiliary variable to store a string with the sequence number
  temp_seq << seq_name;
  string _temp_seq = temp_seq.str();
  
  int diff = width - _temp_seq.length();		// Number of zeros to be added to the sequence number
  root_name.append(diff, '0');				// Add the zeros to the root name
  full_name = root_name + _temp_seq + extension;	// Stick together the full name
  
  return full_name.c_str();				// Return the full name with " const char * " format
};

/*
 * 	Complete a vector with zeros while trying to sum or substract with a bigger vector
 */
template<typename Number>
void fillzeros(vector<Number>& a, int number)
{
  for(unsigned int i=0; i<number; i++)
    a.push_back(0);
};

/*
 * 	Add double vectors using the operator "+"
 */
template<typename Number>
vector<Number> operator+(vector<Number>& a,vector<Number>& b)
{
  int n=a.size()-b.size();
  if(n<0)
    fillzeros(a, -n);
  else if(n>0)
    fillzeros(b, n);
  vector<Number> c;
  for(unsigned int i=0;i<a.size();i++)
    c.push_back(a[i]+b[i]);
  return c;
};

/*
 * 	Substract double vectors using the operator "-"
 */
//template<typename Number>
vector<double> operator-(vector<double>& a,vector<double>& b)
{
  int n=a.size()-b.size();
  if(n<0)
    fillzeros(a, -n);
  else if(n>0)
    fillzeros(b, n);
  vector<double> c;
  for(unsigned int i=0;i<a.size();i++)
    c.push_back(a[i]-b[i]);
  return c;
};

/*
 * 	Scalar product between double vectors using the operator "*"
 */
template<typename Number>
Number operator*(vector<Number>& a,vector<Number>& b)
{
  Number c=0;
  for(unsigned int i=0;i<a.size();i++)
    c+=a[i]*b[i];
  return c;
};

/*
 * 	Scalar product between a double and a double vectors using the operator "*"
 */
template <typename Number>
vector<Number> operator*(Number a, vector< Number >& b)
{
  vector<Number> c;
  for(unsigned int i=0;i<b.size();i++)
    c.push_back(a*b[i]);
  return c;
};

/*
 * 	Scalar product between a integer and a double vectors using the operator "*"
 */
template <typename Number>
vector<Number> operator*(int a, vector< Number >& b)
{
  vector<Number> c;
  for(unsigned int i=0;i<b.size();i++)
    c.push_back(a*b[i]);
  return c;
};

/*
 * 	Vector division over integer value using operator "/".
 */
template<typename Number>
vector<Number> operator/(vector< Number >& a, int b )
{
  vector<Number> c;
  for(unsigned int i=0;i<a.size();i++)
    c.push_back(a[i]/b);
  return c;
};

/*
 * 	Vector division over double value using operator "/".
 */

template<typename Number>
vector<Number> operator/(vector< Number >& a, Number b )
{
  vector<Number> c;
  for(unsigned int i=0;i<a.size();i++)
    c.push_back(a[i]/b);
  return c;
};

/*
 * 	Matrix vector multiplication
 */

template<typename Number>
vector<Number> multiAx(vector<vector<Number> > &A, vector<Number> &x)
{
  vector<Number> b, temp;
  for(unsigned int i = 0; i < A.size(); i++)
  {
    temp = A[i];
    b.push_back(temp*x);
  }
  return b;
};//*/

template<typename Number>
vector<Number> operator*(vector< vector<Number> > &A, vector< Number >&x)
{
  return multiAx(A,x);
}


/*
 * 	Norm of a double vector
 */
template<typename Number>
Number Norm(vector<Number> a)
{
  Number norm=a*a;
  return sqrt(norm);
};

/*
 * 	Computes the factorial of a integral value
 */
int factorial(int a)
{
  if(a==0)  return 1;
  else if(a==1) return 1;
  else if((a>1)) return a*=factorial(a-1);
};



vector<double> integrate(vector<double> &_poly)
{
  vector<double> b = _poly;
  int order = b.size();
  b.push_back(b[order-1]/order);
  for(unsigned int i = order-1; i > 0; i--)
  {
    b[i] = b[i-1]/i;
  }
  b[0] = 0.0;
  return b;
};

/*
 * 	Transpose a Matrix
 * 
 */

vector<vector<double>> transpose(vector<vector<double> > & A)
{
  vector<vector<double> > transA; //[A.size()][A.size()];
  vector<double> column;
  
  for(unsigned int j=0; j<A.size(); j++)
  {
    column.clear();
    for(unsigned int i=0; i<A.size(); i++)
    {
      vector<double> row = A[i];
      column.push_back(row[j]);
    }
    transA.push_back(column);
  }
  /*vector<vector<double> > B;
  for(unsigned int i; i<A.size(); i++)
  {
    vector<double> newrow = A[i];
    for(unsigned int j; j<A.size(); j++)
    {
      newrow.push_back(transA[i][j]);
    }
    B.push_back(newrow);
  }*/
  return transA;
};

/*vector<vector<double> > operator|= (vector<vector<double> >& A, void)
{
  vector<vector<double>> B = transpose(A);
  return B;
};*/




// 	Unsing vector of coeffitients
template<typename Number>
std::vector<Number> polymult(std::vector<Number> a, std::vector<Number> b)
{
  int size = a.size()+b.size()-1;
  std::vector<Number> c(size, 0.0);
  for(unsigned int i = 0; i < a.size(); i++)
  {
    for(unsigned int j = 0; j < b.size(); j++)
      c[i+j]+=a[i]*b[j];
  }
  return c;
};

/*
 * Retuns The Legendre Coefficients for Polynomial Basis recursively
 */
//template<typename Number>
std::vector<std::vector<double> > LegendreCoefficients(int max_degree) 
{
  std::vector<double> temp_row;
  std::vector<std::vector<double> > polyset;

  temp_row.push_back(1);
  polyset.push_back(temp_row);
  if(max_degree>0)
  {
    temp_row.clear();
    temp_row.push_back(0);
    temp_row.push_back(1);
    polyset.push_back(temp_row);
    if( max_degree > 1 )
    {
      for(unsigned int j = 2; j <= max_degree; j++)
      {
	double n = j -1;
	std::vector<double> x = polyset[1], poly_1=polyset[j-1], poly_2=polyset[j-2];
	poly_1 = polymult<double>(x,poly_1);
	poly_1 = (2*n+1)*poly_1;
	poly_2 = n * poly_2;	
	temp_row = (poly_1 - poly_2);
	temp_row = temp_row / (n+1);
	polyset.push_back(temp_row);
      }
    }
  }
  return polyset;
};

