
#ifndef __DIFF_OPERATORS_H__
#define __DIFF_OPERATORS_H__


#include<iostream>
#include<vector>

using namespace std;

void diff1(vector<double> domain, vector<double> image, vector<double> &diff)
{
	for(int i=domain.begin()+1;i++;i=domain.end()-1)
	{
		diff; //revisar los esquemas para calcular derivadas en FD
	}

}

#endif