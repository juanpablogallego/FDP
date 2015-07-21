#include"PolySet.h"
#include"utilities.h"

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

void CreateMassMatrix(BasisType Basis, vector<vector<double> > &Matrix)
{
  Basis.write();
  
  vector<BasisType> tens_product_base;
  
  int b_size= Basis.get_base_size();
  BasisType _temp;
  
  Polynomial poly;
  
  for(unsigned int i = 0; i < b_size; i++)
  {
    _temp = Basis;
    poly = Basis.get_base(i);
    _temp.poly_mult(poly);
    //_temp.write(); cout<<"\n";
    _temp.integrate_base();
    tens_product_base.push_back(_temp);
  };
  
  vector<double> matrix_row (b_size,0), eval_baseM(b_size,0), eval_basem(b_size,0);
  for(unsigned int i = 0; i < b_size;i++)
  {
    _temp = tens_product_base[i];
    eval_basem = _temp.eval(-1);
    eval_baseM = _temp.eval(1);
    matrix_row = eval_baseM - eval_basem;
    Matrix.push_back(matrix_row);
    cout<<"\n";
    copy(matrix_row.begin(), matrix_row.end(), std::ostream_iterator<double>(std::cout, "\t "));
  }
};

