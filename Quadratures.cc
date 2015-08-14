#include<iostream>
#include<vector>
#include<math.h>

#include<fstream>
#include<string>
#include<sstream>

#include"Quadratures.h"
#include"utilities.h"
#include"PolySet.h"


//#include"utilities.h"

using namespace std;

//template <typename Number>
vector<long double> GaussQuadratureWeights(vector<long double> & nodes)
{
  int p = nodes.size();
  vector<long double> weights(p);
  vector<vector<long double> >  Legendre = LegendreCoefficients(p);
  vector<long double> poly = Legendre[p];
  diff<long double>(poly);
  
  for(unsigned int i = 0; i < p; i++)
  {
    long double f_xi = poly_eval<long double>(poly, nodes[i]);
    weights[i]=2/((1-nodes[i]*nodes[i])*(f_xi*f_xi));
  }
  return weights;
};

//template<typename Number>
//void GaussQuadratureNodes(int, vector<Number>&, vector<Number>&);

//template<typename Number>
void GaussQuadratureNodes ( int p, vector<long double> &_points, vector<long double> &_weights)
{
  if(p<1)
  {
    std::cout << "\n\t Wrong polynomial order! \n";
    vector<long double> points;
    points.push_back(-1);
    //return points;
  }
  vector<long double> points(p), weights(p);
  switch(p)
  {
    case 1:
    {      
      points = {0};
      _weights = GaussQuadratureWeights(points);
      _points = points;
      break;
    }
    case 2:
    {
      points = {-0.5773502691896257, 0.5773502691896257};
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;
    }
    case 3:
    {
      points = {-0.7745966692414834, 0.0000000000000000, 0.7745966692414834};
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;
    }
    case 4:
    {
      points = {-0.8611363115940526, -0.3399810435848563, 0.3399810435848563, 0.8611363115940526};      
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;    
    }
        
    case 5:
    {
      points = {-0.9061798459386640, -0.5384693101056831, 0.0000000000000000, 0.5384693101056831, 0.9061798459386640};      
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;    
    }
    
    case 6:
    {
      points = {-0.9324695142031521, -0.6612093864662645, -0.2386191860831969, 0.2386191860831969, 0.6612093864662645, 0.9324695142031521};      
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;    
    }

    case 7:
    {
      points = {-0.9491079123427585, -0.7415311855993945, -0.4058451513773972, 0.0000000000000000, 0.4058451513773972, 0.7415311855993945, 0.9491079123427585};
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;   
    }
    
    case 8:
    {
      points = {-0.9602898564975363, -0.7966664774136267, -0.5255324099163290, -0.1834346424956498, 0.1834346424956498, 0.5255324099163290, 0.7966664774136267, 0.9602898564975363};      
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;   
    }

    case 9:
    {
      points = {-0.9681602395076261, -0.8360311073266358, -0.6133714327005904, -0.3242534234038089, 0.0000000000000000, 0.3242534234038089, 0.6133714327005904, 0.8360311073266358, 0.9681602395076261};      
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;   
    }
    
    case 10:
    {
      points = {-0.9739065285171717, -0.8650633666889845, -0.6794095682990244, -0.4333953941292472, -0.1488743389816312, 0.1488743389816312, 0.4333953941292472, 0.6794095682990244, 0.8650633666889845, 0.9739065285171717};
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;   
    }

    case 11:
    {
      points = {-0.9782286581460570, -0.8870625997680953, -0.7301520055740494, -0.5190961292068118, -0.2695431559523450, 0.0000000000000000, 0.2695431559523450, 0.5190961292068118, 0.7301520055740494, 0.8870625997680953, 0.9782286581460570};
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;   
    }
    
    case 12:
    {
      points = {-0.9815606342467192, -0.9041172563704749, -0.7699026741943047, -0.5873179542866175, -0.3678314989981802, -0.1252334085114689, 0.1252334085114689, 0.3678314989981802, 0.5873179542866175, 0.7699026741943047, 0.9041172563704749, 0.9815606342467192};      
      _points = points;
      _weights = GaussQuadratureWeights(points);
      break;
    }
    default:
    {
      //std::vector<double> points;
      const char * filename = "GaussQuadWnX.txt";
      ifstream quad_file;
      quad_file.open(filename);
      ostringstream p_string;
      p_string << p;
      
      string _p_string=p_string.str();
      _p_string="n = "+_p_string;
      
      //unsigned int n_line=0;
      string input_line;
      
      for(unsigned int line_number = 0; getline(quad_file, input_line); line_number++) 
      {
	if (input_line.find(_p_string) != string::npos) 
	{
	  cout << "Reading quadrature nodes: " << _p_string << " from file "<<filename<<" at line: " << line_number << "\n";
	  for(unsigned int i = 0; i < p; i++)
	  {
	    getline(quad_file, input_line);
	    stringstream _input_line(input_line);
	    int j;
	    long double weight, point;
	    _input_line >> j >> weight >> point;
	    points[i]=point;
	    weights[i] = weight;
	  }
	  quad_file.close();
	  _points = points;
	  _weights = weights;
	  break;
	}
      }
    }
  }
};
