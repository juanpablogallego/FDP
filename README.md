# FDP
Finite Difference and Elements code

Finite difference:

A simple finite difference application for solving hyperbolic equations of consevation laws. 

Grid used:                      So far a equidistant Cartesian grid is generated with arbitraty amount of points in 1, 2                                 and 3 space dimension.

Type of equations:              1D Scalar conservation laws (planning to extend it to multi-dimensional  systems).

Initial conditions implemented: Gaussian bell exp(-x^2), sin(x). and step function.

Test cases implemented:         1D inviscid Burgers' equation.


Finite Elements:

A polynomial basis function class was implemented including functions to multiply, integrate and differenciate polynomials. There is an initial implementation of 1-dimensional Legendre polynomial basis until order 4. 

A class for the finite element grid was created based in three objects: the polynomial basis, a vector of cell objects, and a triangulation.
