
#ifndef __QUADRATURES_H__
#define __QUADRATURES_H__

#include<iostream>
#include<vector>
#include<math.h>

#include<fstream>
#include<string>
#include<sstream>

using namespace std;

vector<double> GaussQuadratureWeights(vector<double> & );

void GaussQuadratureNodes ( int , vector<double> &, vector<double> &);

#endif