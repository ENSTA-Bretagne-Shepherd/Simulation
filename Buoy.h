#ifndef Buoy_H
#define Buoy_H

#include <math.h>


class Buoy
{    public:
            double x,y,z; // state variables
            double beta,sigma,rho,k; //parameters
            double xdot,ydot,zdot;  //link variables

            void Clock();
            void Pendulum();
            void Lorenz();
            explicit Buoy ();
        ~Buoy();
 };

#endif // Buoy_H
