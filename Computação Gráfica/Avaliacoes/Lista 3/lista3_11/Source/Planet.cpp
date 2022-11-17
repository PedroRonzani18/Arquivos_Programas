#include "../Header/Planet.h"

Planet::Planet(GLuint texture, double coreRadius, double rotationRadius, double angularSpeed){
            this->angle = 0;
            this->coreRadius = coreRadius;
            this->rotationRadius = rotationRadius;
            this->angularSpeed = angularSpeed;
        }

Planet Planet::createPlanetTemplate(GLuint texture, double coreRadius, double rotationRadius, double angularSpeed)
{
    Planet p;
    p.setTexture(texture);
    p.setCoreRadius(coreRadius);
    p.setRotationRadius(rotationRadius);
    p.setAngularSpeed(angularSpeed);
    return p;
}