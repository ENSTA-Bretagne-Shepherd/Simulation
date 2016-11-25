#include "sailboat.h"


#include <GL/gl.h>
#include <GL/glu.h>
extern double dt;


Buoy::Buoy()
{   sigma = 10.0; beta = 8.0/3.0; rho = 24.3;x = 0.0;y = 0.0;z=0.0;number = 0;
    k = 1.0;u = 0.0; xdot = 0.0; ydot = 0.0; zdot = 0.0;
}

Buoy::~Buoy()
{
}

double sign(double a)
{if (a>0) return 1; else return -1;};



void Buoy::Lorenz()
{
    xdot = sigma*(y-x);
    ydot = x*(rho-z)-y;
    zdot = k*(x-y-beta*z)+u;
}


void Buoy::Pendulum()
{
    xdot = y;
    ydot = -sin(x);
    zdot = u;
}

void Buoy::StateEq()
{
    xdot = sin(0.001*(y+0.9*z));
    ydot = -sin(0.001*(x+z));
    zdot = u;
}

void Buoy::Clock()  // The model is described in "L. Jaulin Modélisation et commande d'un bateau à voile, CIFA2004, Douz (Tunisie)"
{   


    Pendulum();
    x = x+dt*xdot;
    y = y+dt*ydot;
    z = z+dt*zdot;
    
}
