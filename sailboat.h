#ifndef sailboat_H
#define sailboat_H

#include <math.h>

/**
 * Classe bu bateau
 */
class Sailboat
{    public:
            double x,y,theta,v,omega,phi,phiPoint; // state variables
            double beta, Jz, rg, rv, alphag, alphav, alphaf, alphatheta, l,m, Jx; //parameters
            double a,psi;  //wind
            double fg,fv,gamma,deltav,deltag,deltavmax;  //link variables
            double eta;//viscosite
            double hv; // hauteur de centre de pousse

            int q;
            double cx,cy;// centre du triangle
            int iseg;// numero du segment

            void clock();
            void controller();
            explicit Sailboat();
        ~Sailboat();
 };

#endif // sailboat_H
