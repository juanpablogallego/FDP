#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
#include<iterator>
#include<vector>


#include"utilities.h"

using namespace std;


  /*
  // first solution
  while(_temp_seq.length()<width)
    _temp_seq="0"+_temp_seq;
  full_name=root_name+_temp_seq+".txt";
  */

/*const char * Gen_Seq_File_Names(string root_name,string extension, int seq_name, int width)
{
  string full_name;
  std::ostringstream temp_seq;
  temp_seq << seq_name;
  string _temp_seq = temp_seq.str();
  

  
  // second solution
  int diff = width - _temp_seq.length();
  root_name.append(diff, '0');
  full_name = root_name + _temp_seq + extension;
  
  return full_name.c_str();
};*/

/*int factorial(int a)
{
  if(a==0)  return 1;
  else if(a==1) return 1;
  else if((a>1)) return a*=factorial(a-1);
};//*/

/*vector<vector<double>> transpose(vector<vector<double> > & A)
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
      //copy(column.begin(), column.end(), std::ostream_iterator<double>(std::cout, "\t "));
    }
    transA.push_back(column);
  }

  return transA;
};//*/

int main()
{
  /*string root_name = "burgers";
  string extension = ".dat";
  int seq_name=10;
  int width=4;
  
  const char * full_name = Gen_Seq_File_Names(root_name, extension, seq_name, width);
  cout <<"\n" << full_name << "\n";*/
  
  /*int order=5, n= factorial(order);  
  cout <<"\n \t Order \t" << order << "\n";
  cout <<"\n \t factorial \t"<<n <<"\n";
  */
  
  vector<vector<double> > A, B;
  vector<double> a;
  a.push_back(1.5); a.push_back(2);
  A.push_back(a);
  a.clear();
  a.push_back(3); a.push_back(4);
  A.push_back(a);

  cout<<"\n\t Matrix A:\n";
  for(unsigned int i=0; i<A.size(); i++)
  {
    vector<double> row = A[i];
    copy(row.begin(), row.end(), std::ostream_iterator<double>(std::cout, "\t "));
    cout<<"\n";
  }
  
  B = transpose(A);

  cout<<"\n\t Matrix B:\n"<< "\t B size " << B.size()<< "\n";
  for(unsigned int i=0; i<B.size(); i++)
  {
    vector<double> rowB = B[i];
    copy(rowB.begin(), rowB.end(), std::ostream_iterator<double>(std::cout, "\t "));
    cout<<"\n";
  }
  
  return 0;
  
};