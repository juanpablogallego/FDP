
#include<vector>
#include<string>
#include<sstream>

template <typename InputVector, typename OutputValue> OutputValue MyMaxEntry(InputVector& vector) // Template version
{
  OutputValue a=vector[0];				// Store the first value of the vector
  for(unsigned int i=1; i<vector.size(); i++)		// Sweep the vector
    a=(a>vector[i]?a:vector[i]);			// Store the maximum between elements of the vector
  return a;						// Return the maximum value
};


double MyMaxEntry(std::vector<double>& );

const char * Gen_Seq_File_Names(std::string, std::string, int, int );

std::vector<std::vector<double> > LegendreCoefficients(int );
