#ifndef _SPACE_H
#define _SPACE_H

#include "Planet.h"
#include <vector>

class Space{
    private:
        std::vector<Planet> planetas;

    public:
        void addPlaneta(Planet p){planetas.push_back(p);}
        Planet getPlaneta(int i){return planetas[i];}

        void drawAndMove(double t);

};

#endif