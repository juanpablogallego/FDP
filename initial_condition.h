#ifndef __INITIAL_CONDITION_H__
#define __INITIAL_CONDITION_H__

#include<iostream>
#include<vector>

void eval_step1D(std::vector<double> &, std::vector<double> &);

void eval_gaussian(std::vector<double> &, std::vector<double> &);

void eval_sin(std::vector<double> &, std::vector<double> &);

double eval_step1D(double);

double eval_gaussian(double);

#endif