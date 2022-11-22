#ifndef _PLANET_H
#define _PLANET_H

#include <vector>
#include "CelestialBody.h"
#include "Moon.h"

class Planet : public CelestialBody
{
    private:
        std::vector<Moon> moons;

    public:
        Planet(){}

        std::vector<Moon> getMoons(){return this->moons;}
        void addMoon(Moon moon){this->moons.push_back(moon);}

//        static Planet createPlanetTemplate(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed);
          static Planet createPlanetTemplate(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod);

};

#endif