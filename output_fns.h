
#ifndef __OUTPUT_FNS_H__
#define __OUTPUT_FNS_H__

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

template<typename Datatype>
void output_fn(ofstream &printResults, string title, vector<Datatype> data)
{  
  printResults << title <<"\n";
  for(unsigned int i=0; i < data.size(); i++)
    printResults << data[i] << "\n";
};

template<typename Datatype>
void output_fn(ofstream &printResults, string title, vector<vector<Datatype>> data)
{
  printResults<< title <<"\n";
  for(unsigned int i=0; i < data.size(); i++)
  {
    vector<int> line=data[i];
    copy(line.begin(), line.end(), ostream_iterator<double>(printResults, " \t"));
    printResults<< "\n";
  }
};

#endif