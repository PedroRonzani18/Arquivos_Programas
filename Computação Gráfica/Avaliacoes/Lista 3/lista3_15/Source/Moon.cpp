#include "../Header/Moon.h"
#include "../Header/drawings.h"

Moon Moon::createPlanetTemplate(double angle, double coreRadius, double rotationRadius, double angularSpeed)
{
    Moon moon;
    moon.setAngle(angle);
    moon.setTexture(loadTexture("imagens/2k_moon.jpg"));
    moon.setCoreRadius(coreRadius);
    moon.setRotationRadius(rotationRadius);
    moon.setAngularSpeed(angularSpeed);
    return moon;
}