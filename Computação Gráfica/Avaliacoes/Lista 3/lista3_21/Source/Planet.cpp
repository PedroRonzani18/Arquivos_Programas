#include "../Header/Planet.h"
#include "../Header/drawings.h"
#include <stdio.h>

Planet Planet::createPlanetTemplate(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod)
//Planet Planet::createPlanetTemplate(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed)
{
    Planet planet;
    planet.setTexture(texture);
    planet.setDependsOnLight(dependsOnLight);
    planet.setCoreRadius(coreRadius);
    planet.setRotationRadius(rotationRadius);

    double translationSpeed, angularSpeed;

    if(translationPeriod != 0)
        translationSpeed = 30600.0 / translationPeriod;
    else
        translationSpeed = 0;

    if(rotationPeriod == 0)
        angularSpeed = 0;

    planet.setConversionConst(33600);
    planet.setRotationPeriod(rotationPeriod);
    planet.setTranslationPeriod(translationPeriod);
    planet.setTranslationAngularSpeed(translationSpeed);   
    planet.setRotationAngularSpeed(angularSpeed);
    //planet.setTranslationAngularSpeed(translationAngularSpeed);   
    //planet.setRotationAngularSpeed(rotationAngularSpeed);

    Moon moon = Moon::createPlanetTemplate(0, 0.15, 0.6, 20, 50);

    switch(numberOfMoons)
    {
        case 3:
            moon.setAngle(240);
            planet.addMoon(moon);
        case 2:
            moon.setAngle(360/numberOfMoons);
            planet.addMoon(moon);
        case 1:
            moon.setAngle(0);
            planet.addMoon(moon);
            break;
    }

    return planet;
}