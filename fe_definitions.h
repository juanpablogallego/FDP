#include<iostream>
#include<iterator>

#include"PolySet.h"

typedef GeneralPolyBasis<Polynomial, vector<vector<double> > > BasisType;

/*
 * 	Function to calculate the Mass Matrix for a FE scheme in one cell
 * 	- input	: Basis (an object from the GeneralPolyBasis class)
 * 	- output: Matrix (a vector<vector<double> > matrix to store the Mass Matrix)
 * 
 * 		It extracts one element at a time form the base, multiplies it for the entire
 * 	base, integrates the resulting polynomial and evaluates the integral in the end point
 * 	of the reference domain, which are supposed to be -1 and 1. Then it returns the 
 * 	difference of the evaluation of these points.
 *
 * 		If the Basis is orthogonal the matrix should be diagonal.
 */

void CreateMassMatrix(BasisType &, vector<vector<double> > &);		// WARNING: It can happen that the function has to be moved here

/*
 * 	Evaluates different fluxes depending on the equation
 * 	TODO: Add the swiching between different equations
 */

// WARNING: this has to be changed, switch does not work with strings

template <typename Number>
Number eval_flux(Number u, string &fluxtype, Number a=0)
{
  switch(fluxtype)
  {
    case "advection":
    {
      Number flux = advect_flux1D<Number>(u);
      return flux;
    }
    
    case "burgers":
    {
      Number flux = burgers_flux1D<Number>(u);
      return flux;
    }
  }
};

//TODO: Move to a file exclusive with numerical fluxes
template <typename Number>
Number lax_friedrich(Number in, Number out, Number alpha, string &fluxtype, Number a=0)
{
  Number flux;
  flux = 0.5*((out + in) + alpha*(eval_flux<Number>(out, fluxtype, a)- eval_flux<Number>(in, fluxtype, a)));
};

//TODO:  Move to a file exclusive for flux functions
template <typename Number>
Number burgers_flux1D(Number u)
{
  Number flux = u*u;
  return flux;
};

template <typename Number>
Number advect_flux1D(Number a, Number u)
{
  Number flux = a*u;
  return flux;
};