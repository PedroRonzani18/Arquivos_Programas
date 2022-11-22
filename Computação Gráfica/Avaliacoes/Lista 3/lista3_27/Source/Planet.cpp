#include "../Header/Planet.h"
#include "../Header/drawings.h"
#include <stdio.h>

Planet::Planet(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod)
{
    this->texture = texture;
    this->dependsOnLight = dependsOnLight;
    this->coreRadius = coreRadius;
    this->rotationRadius = rotationRadius;
    this->translationPeriod = rotationPeriod;
    this->rotationPeriod = rotationPeriod;

    double translationSpeed, angularSpeed;

    if(translationPeriod != 0)
        translationSpeed = 30600.0 / translationPeriod;
    else
        translationSpeed = 0;

    this->translationAngularSpeed = translationSpeed;

    if(rotationPeriod == 0)
        angularSpeed = 0;

    this->rotationAngularSpeed = angularSpeed;

     std::shared_ptr<Moon> moon = std::make_shared<Moon>(0, 0.15, 0.6, 20, 50);

    switch(numberOfMoons)
    {
        case 3:
            moon->setAngle(240);
            addMooon(moon);
        case 2:
            moon->setAngle(360/numberOfMoons);
            addMooon(moon);
        case 1:
            moon->setAngle(0);
            addMooon(moon);
            break;
    }
}