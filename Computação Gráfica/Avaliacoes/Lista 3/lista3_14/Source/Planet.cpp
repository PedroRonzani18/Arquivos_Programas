#include "../Header/Planet.h"
#include "../Header/drawings.h"

Planet::Planet(GLuint texture, double coreRadius, double rotationRadius, double angularSpeed)
{
    this->angle = 0;
    this->coreRadius = coreRadius;
    this->rotationRadius = rotationRadius;
    this->angularSpeed = angularSpeed;
}

Planet Planet::createPlanetTemplate(const char* texture, double coreRadius, double rotationRadius, double angularSpeed, double orbitSpeed)
{
    Planet planet;
    planet.setTexture(loadTexture(texture));
    planet.setCoreRadius(coreRadius);
    planet.setRotationRadius(rotationRadius);
    planet.setAngularSpeed(angularSpeed);   
    planet.setOrbitSpeed(orbitSpeed);
    return planet;
}