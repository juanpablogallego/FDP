// Author:	Juan Pablo Gallego Valencia
// Created:	July 2015

#include<vector>
#include<string>
#include<sstream>

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

