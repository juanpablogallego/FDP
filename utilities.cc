// Author:	Juan Pablo Gallego Valencia
// Created:	July 2015

#include<vector>
#include<string>
#include<sstream>
#include<iterator>
#include<iostream>


/*
 * 	Utility functions to ease my life with coding
 */


/*
 * 	Returns the maximum entrance of a vector
 */

double MyMaxEntry(std::vector<double>& vector)
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
const char * Gen_Seq_File_Names(std::string root_name, std::string extension, int width, int seq_name)
{
  std::string full_name;				// Container for the full name
  std::ostringstream temp_seq;				// Auxiliary variable to store a string with the sequence number
  temp_seq << seq_name;
  std::string _temp_seq = temp_seq.str();
  
  int diff = width - _temp_seq.length();		// Number of zeros to be added to the sequence number
  root_name.append(diff, '0');				// Add the zeros to the root name
  full_name = root_name + _temp_seq + extension;	// Stick together the full name
  
  return full_name.c_str();				// Return the full name with " const char * " format
};

/*
 * Retuns The Legendre Coefficients for Polynomial Basis until k = 4 (TODO: Se podria hacer generico?)
 */

std::vector<std::vector<double> > LegendreCoefficients(int order)
{
  std::cout<< "\n \t Legendre Coeficients: \n";
  
  std::vector<std::vector<double> > Coefficients;
  std::vector<double> temp;
  temp.push_back(1);
  std::copy(temp.begin(), temp.end(), std::ostream_iterator<double>(std::cout, ", "));
  std::cout<<"\n";
  Coefficients.push_back(temp);
  if(order==0)
    return Coefficients;
  
  temp[0]=0;
  temp.push_back(1);
  std::copy(temp.begin(), temp.end(), std::ostream_iterator<double>(std::cout, ", "));
  std::cout<<"\n";
  Coefficients.push_back(temp);
  if(order==1)
    return Coefficients;
  
  temp[0]=-0.5;
  temp[1]=0;
  temp.push_back(1.5);
  std::copy(temp.begin(), temp.end(), std::ostream_iterator<double>(std::cout, ", "));
  std::cout<<"\n";
  Coefficients.push_back(temp);
  if(order==2)
    return Coefficients;
  
  temp[0]=0;
  temp[1]=-1.5;
  temp[2]=0;
  temp.push_back(2.5);
  std::copy(temp.begin(), temp.end(), std::ostream_iterator<double>(std::cout, ", "));
  std::cout<<"\n";
  Coefficients.push_back(temp);
  if(order==3)
    return Coefficients;
  
  temp[0]=3.0/8.0;
  temp[1]=0;
  temp[2]=-30.0/8.0;
  temp[3]=0;
  temp.push_back(35.0/8.0);
  std::copy(temp.begin(), temp.end(), std::ostream_iterator<double>(std::cout, ", "));
  std::cout<<"\n";
  Coefficients.push_back(temp);
  if(order==4)
    return Coefficients;
  
};