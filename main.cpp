#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sstream>

#include "world.h"
#include "config.h"
#include "unity-api/unityapi.h"
//#include "serverToBuoys.h"

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

    DisplayAPI display("localhost", 13000);

    while (boucle()==EXIT_SUCCESS)
    {

        // Server init
        //ServerToBuoys();
//        GraphInterface(ADRESS,PORT)
        //listen TODO

        //Fait avancer la simulation
        env.clock();

        // Send to Unity
        
        for (int i = 0; i < env.vec_sailboat.size(); ++i)
        {
            std::ostringstream nameStream;
            nameStream << "Auv" << i;
            display.sendSailBoatState(nameStream.str(), env.vec_sailboat[i].x, env.vec_sailboat[i].y, env.vec_sailboat[i].theta);
        }

        //Formate les donnes par JSON TODO

        //Envoie les infos par la socket TODO

        //Temps interne
        env.simuTime += dt;
        usleep(50000);
        printf("\ntime : %f \n",env.simuTime);
    }

    return 0;
}





