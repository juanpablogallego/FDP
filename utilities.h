
#include<vector>
#include<string>
#include<sstream>

/*
 * 	Find the maximum value of a vector, should work for defined types of values (double, int, float)
 * 		TODO: Define a maximum of a vector (by its norm?)
 */

template <typename InputVector, typename OutputValue> OutputValue MyMaxEntry(InputVector& vector) // Template version
{
  OutputValue a=vector[0];				// Store the first value of the vector
  for(unsigned int i=1; i<vector.size(); i++)		// Sweep the vector
    a=(a>vector[i]?a:vector[i]);			// Store the maximum between elements of the vector
  return a;						// Return the maximum value
};

/*
 * 	Template versions of the + and - operators for different kind of vectors
 */

template<typename Tipo>
std::vector<Tipo> operator+(std::vector<Tipo>& a,std::vector<Tipo>& b)
{
  std::vector<Tipo> c;
  for(unsigned int i=0;i<a.size();i++)
    c.push_back(a[i]+b[i]);
  return c;
};

template<typename Tipo>
std::vector<Tipo> operator-(std::vector<Tipo>& a,std::vector<Tipo>& b)
{
  std::vector<Tipo> c;
  for(unsigned int i=0;i<a.size();i++)
    c.push_back(a[i]-b[i]);
  return c;
};

/*
 * 	Functions that can be compiled in the object utilities.o
 * 	(the explanations are in the utilities.cc file)
 */
double MyMaxEntry(std::vector<double>& );

const char * Gen_Seq_File_Names(std::string, std::string, int, int );

std::vector<std::vector<double> > LegendreCoefficients(int);

std::vector<double> operator+(std::vector<double>&,std::vector<double>&);

std::vector<double> operator-(std::vector<double>&,std::vector<double>&);

double operator*(std::vector<double>&,std::vector<double>&);

std::vector<double> operator*(double , std::vector< double >& );

std::vector<double> multiAx(std::vector<std::vector<double> > &, std::vector<double> &);

std::vector<double> operator*(std::vector< std::vector<double> > &, std::vector< double >&);

double Norm(std::vector<double> );

int factorial(int );

double poly_eval (std::vector<double> &, double );

std::vector<double> integrate(std::vector<double> &);

std::vector<std::vector<double>> transpose(std::vector<std::vector<double>>& );

//std::vector<std::vector<double> > operator|= (std::vector<std::vector<double> > & );
