#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include"Quadratures.h"
#include"utilities.h"
#include"PolySet.h"

vector<double> GaussQuadratureNodes ( int p)
{
  if(p<1)
  {
    std::cout << "\n\t Wrong polynomial order! \n";
    vector<double> points;
    return points.push_back(-1);
  }
  vector<double> points(p);
  switch(p)
  {
    case 1:
    {      
      points = {0};
      return points;
    }
    case 2:
    {
      points = {-0.5773502691896257, 0.5773502691896257};
      return points;
    }
    case 3:
    {
      points = {-0.7745966692414834, 0.0000000000000000, 0.7745966692414834};
      return points;
    }
    case 4:
    {
      points = {-0.8611363115940526, -0.3399810435848563, 0.3399810435848563, 0.8611363115940526};      
      return points;
    }
        
    case 5:
    {
      points = {-0.9061798459386640, -0.5384693101056831, 0.0000000000000000, 0.5384693101056831, 0.9061798459386640};      
      return points;
    }
    
    case 6:
    {
      points = {-0.9324695142031521, -0.6612093864662645, -0.2386191860831969, 0.2386191860831969, 0.6612093864662645, 0.9324695142031521};      
      return points;
    }

    case 7:
    {
      points = {-0.9491079123427585, -0.7415311855993945, -0.4058451513773972, 0.0000000000000000, 0.4058451513773972, 0.7415311855993945, 0.9491079123427585};
      return points;
    }
    
    case 8:
    {
      points = {-0.9602898564975363, -0.7966664774136267, -0.5255324099163290, -0.1834346424956498, 0.1834346424956498, 0.5255324099163290, 0.7966664774136267, 0.9602898564975363};      
      return points;
    }

    case 9:
    {
      points = {-0.9681602395076261, -0.8360311073266358, -0.6133714327005904, -0.3242534234038089, 0.0000000000000000, 0.3242534234038089, 0.6133714327005904, 0.8360311073266358, 0.9681602395076261};      
      return points;
    }
    
    case 10:
    {
      points = {-0.9739065285171717, -0.8650633666889845, -0.6794095682990244, -0.4333953941292472, -0.1488743389816312, 0.1488743389816312, 0.4333953941292472, 0.6794095682990244, 0.8650633666889845, 0.9739065285171717};
      return points;
    }

    case 11:
    {
      points = {-0.9782286581460570, -0.8870625997680953, -0.7301520055740494, -0.5190961292068118, -0.2695431559523450, 0.0000000000000000, 0.2695431559523450, 0.5190961292068118, 0.7301520055740494, 0.8870625997680953, 0.9782286581460570};
      return points;
    }
    
    case 12:
    {
      points = {-0.9815606342467192, -0.9041172563704749, -0.7699026741943047, -0.5873179542866175, -0.3678314989981802, -0.1252334085114689, 0.1252334085114689, 0.3678314989981802, 0.5873179542866175, 0.7699026741943047, 0.9041172563704749, 0.9815606342467192};      
      return points;
    }
    default:
    {
      const char * filename = "GaussQuadWnX.txt";
      std::ifstream quad_file;
      quad_file.open(filename);
      ostringstream p_string;
        p_string << p;
      
      std::string _p_string=p_string.str();
      _p_string="n = "+_p_string;
      
      unsigned int n_line=0;
      
      for(unsigned int curLine = 0; getline(quad_file, n_line); curLine++) {
	if (n_line.find(_p_string) != string::npos) {
	  cout << "found: " << _p_string << "line: " << curLine << endl;	  
	}
}
      
      return points;     
    }
  }
};
/*{
  vector<double> points(p);
  switch(p)
  {
    case 1:
    {
      points = {0};
    }
    case 2:
    {
      points = {1.0/sqrt(3), -1.0/sqrt(3)};
      return points;
    }
    case 3:
    {
      points = {-sqrt(3.0/5.0), 0.0, sqrt(3.0/5.0)};
      return points;
    }
    case 4:
    {
      double a = 3.0/7.0, b = sqrt(6.0/5.0), c = 2.0/7.0;
      points = {-sqrt(a +c*b), -sqrt(a -c*b), sqrt(a -c*b), sqrt(a +c*b)};
      return points;
    }
    case 5:
    {
      points = {-sqrt(5 +sqrt(6/5)*2)/3, -sqrt(5 -sqrt(6/5)*2)/3, 0, sqrt(5 -sqrt(6/5)*2)/3, sqrt(5 +sqrt(6/5)*2)/3};
      return points;
    }
  }
};//*/

vector<double> GaussQuadratureWeights(vector<double> & nodes)
{
  int p = nodes.size();
  vector<double> weights(p);
  vector<vector<double> >  Legendre = LegendreCoefficients(p);
  vector<double> poly = Legendre[p];
  diff(poly);
  
  for(unsigned int i = 0; i < p; i++)
  {
    double f_xi = poly_eval(poly, nodes[i]);
    weights[i]=2/((1-nodes[i]*nodes[i])*(f_xi*f_xi));
  }
  return weights;
};