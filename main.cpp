#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>

#include "world.h"
#include "config.h"

double dt = DT;

int boucle(){



    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    printf("SIMULATION STARTED\n");

    // Objects creation
    World env = World(4,5);
    env.initialize();

    while (boucle()==EXIT_SUCCESS)
    {
        //Fait avancer la simulation
        env.clock();

        //Temps interne
        env.simuTime += dt;
        usleep(50);
    }

    return 0;
}





