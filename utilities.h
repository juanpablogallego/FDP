
#include<vector>
#include<string>
#include<sstream>

/*
 * 	Find the maximum value of a vector, should work for defined types of values (double, int, float)
 * 		TODO: Define a maximum of a vector (by its norm?)
 */

/*
 * 	Template versions of the + and - operators for different kind of vectors
 */

/*
 * 	Functions that can be compiled in the object utilities.o
 * 	(the explanations are in the utilities.cc file)
 */


//template<typename Number>
//Number MyMaxEntry(std::vector<Number>& );

template <typename InputVector, typename OutputValue> OutputValue MyMaxEntry(InputVector& vector) // Template version
{
  OutputValue a=vector[0];				// Store the first value of the vector
  for(unsigned int i=1; i<vector.size(); i++)		// Sweep the vector
    a=(a>vector[i]?a:vector[i]);			// Store the maximum between elements of the vector
  return a;						// Return the maximum value
};

const char * Gen_Seq_File_Names(std::string, std::string, int, int );


template<typename Number>
std::vector<Number> operator+(std::vector<Number>&,std::vector<Number>&);

//template<typename Number>
std::vector<double> operator-(std::vector<double>& ,std::vector<double>& );

//template<typename Number>
//std::vector<Number> operator=(std::vector<Number> , std::vector<Number> );

template<typename Number>
Number operator*(std::vector<Number>&,std::vector<Number>&);

template<typename Number>
std::vector<Number> operator*(Number , std::vector< Number >& );

template<typename Number>
std::vector<Number> operator/(std::vector< Number >& , Number );

template<typename Number>
std::vector<Number> operator/(std::vector< Number >& , int );

template<typename Number>
std::vector<Number> multiAx(std::vector<std::vector<Number> > &, std::vector<Number> &);

template<typename Number>
std::vector<Number> operator*(std::vector< std::vector<Number> > &, std::vector< Number >&);

template<typename Number>
Number Norm(std::vector<Number> );

int factorial(int );

//template<typename Number>
//Number poly_eval (std::vector<Number> &, Number );

template<typename Number>
Number poly_eval (std::vector<Number> &_poly, Number _value)
{
  Number value=0.0, power=1.0;
  for(unsigned int i = 0; i < _poly.size(); i++)
  {
    value+=_poly[i]*power;
    power*=_value;
  }
  return value;
};

template<typename Number>
std::vector<Number> integrate(std::vector<Number> &);

template<typename Number>
std::vector<std::vector<Number>> transpose(std::vector<std::vector<Number>>& );

//template<typename Number>
//std::vector<Number> polymult(std::vector<Number> , std::vector<Number> );

//std::vector<std::vector<double> > operator|= (std::vector<std::vector<double> > & );

//template<typename Number>
std::vector<std::vector<double> > LegendreCoefficients(int);


