#include<iostream>
#include"fdgrid.h"
#include<iterator>
#include<cstdlib>
#include <math.h>


using namespace std;


//	Burgers equation object containing:
//		- the coordinates x, y, z 	(TODO: Higher dimentions.)
//		- the states u, v, w		(TODO: System of equation?)
//		- the dimension
//		- the initial condition (function)
//		- the flux function

//template <typename GridType>
class FD_Conservation_Laws{
	int dim, n;
	vector<double> x, y, z; // Coordinates
	vector<double> u, u0; 	// State and Initial Condition
	vector<double> flux;	// Evaluation of the flux function
public:
	template <typename GridType> FD_Conservation_Laws(GridType& );		// Constructors
	template <typename GridType> FD_Conservation_Laws(GridType& , int); 				
	void set_dimension(int);						// TODO: Update code for higher dimensions
	void set_ic(vector<double>&,vector<double>&); 				// Evaluate Initial Condition (const x,u) for now
	template <typename InputVector> InputVector Burgers_1D_Flux(InputVector&); 		// Burgers Flux function
	void get_state(vector<double>&);
};


//	Constructor for the Conservation Law  object
template <typename GridType> 
FD_Conservation_Laws::FD_Conservation_Laws(GridType& grid) //(FD_grid::FD_grid& grid)
{
	FD_Conservation_Laws(grid, 1);
};

template <typename GridType> 
FD_Conservation_Laws::FD_Conservation_Laws(GridType& grid, int dim) //(FD_grid::FD_grid& grid, int dim)
{
	cout<<"\n \t Constructor initialized";
	n=pow(grid.get_num_nodes(),dim);
	switch (dim)
	{
	case 1:
		grid.get_nodes(x);
		set_ic(x, u0);
		u = u0;
		break;
	case 2:			// TODO: Flux functions for higher dimensions
		break;
	case 3:
		break;
	default:
		break;
	}
	flux=Burgers_1D_Flux(u);

};

//	Initial Condition for the one-dimenstional Burgers equation, in this case it is an exponential bump exp(-(10x)^2)
void FD_Conservation_Laws::set_ic(vector<double>& x, vector<double>& u0)
{
	for(unsigned int i = 0; i < x.size(); i++)
	//for(vector<double>::iterator i = x.begin(); i != x.end(); i++)
	{
		double x0 = -(100*x[i]*x[i]);
		u0[i] = exp(x0); 
	}

};

template <typename InputVector> 
InputVector FD_Conservation_Laws::Burgers_1D_Flux(InputVector& u)
{
	typedef typename InputVector::value_type number;
	InputVector flux;
	for(unsigned int i = 0; i < u.size(); i++)
	{
		number aux=u[i]*u[i]; 		// TODO: Add flux functions for higher dimensions
		flux.push_back(aux);
		cout<<"\n \t "<<aux;
	}
	return flux;
};//*/

//	Set dimension of the conserbation law, which is one by default.
void FD_Conservation_Laws::set_dimension(int d)
{
	dim=d;
};

void FD_Conservation_Laws::get_state(vector<double>& state)
{
	state=u;
};


