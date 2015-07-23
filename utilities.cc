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

double MyMaxEntry(vector<double>& vector)
{
  double a=vector[0];					// Store the first value of the vector
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
void fillzeros(vector<double>& a, int number)
{
  for(unsigned int i=0; i<number; i++)
    a.push_back(0);
};

/*
 * 	Add double vectors using the operator "+"
 */
vector<double> operator+(vector<double>& a,vector<double>& b)
{
  int n=a.size()-b.size();
  if(n<0)
    fillzeros(a, -n);
  else if(n>0)
    fillzeros(b, n);
  vector<double> c;
  for(unsigned int i=0;i<a.size();i++)
    c.push_back(a[i]+b[i]);
  return c;
};

/*
 * 	Substract double vectors using the operator "-"
 */
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
double operator*(vector<double>& a,vector<double>& b)
{
  double c=0;
  for(unsigned int i=0;i<a.size();i++)
    c+=a[i]*b[i];
  return c;
};

/*
 * 	Scalar product between a double and a double vectors using the operator "*"
 */
vector<double> operator*(double a, vector< double >& b)
{
  vector<double> c;
  for(unsigned int i=0;i<b.size();i++)
    c.push_back(a*b[i]);
  return c;
};

/*
 * 	Scalar product between a integer and a double vectors using the operator "*"
 */
vector<double> operator*(int a, vector< double >& b)
{
  vector<double> c;
  for(unsigned int i=0;i<b.size();i++)
    c.push_back(a*b[i]);
  return c;
};

/*
 * 	Vector division over integer value using operator "/".
 */
vector<double> operator/(vector< double >& a, int b )
{
  vector<double> c;
  for(unsigned int i=0;i<a.size();i++)
    c.push_back(a[i]/b);
  return c;
};

/*
 * 	Vector division over double value using operator "/".
 */
vector<double> operator/(vector< double >& a, double b )
{
  vector<double> c;
  for(unsigned int i=0;i<a.size();i++)
    c.push_back(a[i]/b);
  return c;
};

/*
 * 	Matrix vector multiplication
 */

vector<double> multiAx(vector<vector<double> > &A, vector<double> &x)
{
  vector<double> b, temp;
  for(unsigned int i = 0; i < A.size(); i++)
  {
    temp = A[i];
    b.push_back(temp*x);
  }
  return b;
};//*/

vector<double> operator*(vector< vector<double> > &A, vector< double >&x)
{
  return multiAx(A,x);
}


/*
 * 	Norm of a double vector
 */
double Norm(vector<double> a)
{
  double norm=a*a;
  return sqrt(norm);
};

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

/*
 * Retuns The Legendre Coefficients for Polynomial Basis recursively
 */


vector<vector<double> > LegendreCoefficients(int max_degree) //LegendrePolynomials
{
  vector<double> temp_row;
  vector<vector<double> > polyset;

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
	double n = j - 1;
	vector<double> x = polyset[1], poly_1=polyset[j-1], poly_2=polyset[j-2];
	poly_1=polymult(x,poly_1);
	poly_1= (2*n+1)*poly_1;
	poly_2= n * poly_2;	
	temp_row = (poly_1 - poly_2);
	temp_row = temp_row/(n+1);
	polyset.push_back(temp_row);
      }
    }
  }
  return polyset;
};//*/