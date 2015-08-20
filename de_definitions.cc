#include<iostream>
#include<iterator>

#include"PolySet.h"
#include"utilities.h"
#include"fe_definitions.h"

void CreateMassMatrix(BasisType& Basis, vector<vector<double> > &Matrix)
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
    copy(matrix_row.begin(), matrix_row.end(), ostream_iterator<double>(std::cout, "\t "));
  }
};