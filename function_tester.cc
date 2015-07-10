#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>


using namespace std;


const char * Gen_Seq_File_Names(string root_name,string extension, int seq_name, int width)
{
  string full_name;
  std::ostringstream temp_seq;
  temp_seq << seq_name;
  string _temp_seq = temp_seq.str();
  
  /*
  // first solution
  while(_temp_seq.length()<width)
    _temp_seq="0"+_temp_seq;
  full_name=root_name+_temp_seq+".txt";
  */
  
  // second solution
  int diff = width - _temp_seq.length();
  root_name.append(diff, '0');
  full_name = root_name + _temp_seq + extension;
  
  return full_name.c_str();
};



int main()
{
  string root_name = "burgers";
  string extension = ".dat";
  int seq_name=10;
  int width=4;
  
  const char * full_name = Gen_Seq_File_Names(root_name, extension, seq_name, width);
  cout <<"\n" << full_name << "\n";
  return 0;
  
};