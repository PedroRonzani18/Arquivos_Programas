#include "../Header/Planet.h"
#include "../Header/drawings.h"

Planet::Planet(GLuint texture, double coreRadius, double rotationRadius, double translationAngularSpeed)
{
    this->angle = 0;
    this->coreRadius = coreRadius;
    this->rotationRadius = rotationRadius;
    this->translationAngularSpeed = translationAngularSpeed;
}

Planet Planet::createPlanetTemplate(const char* texture, bool dependsOnLight, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed)
{
    Planet planet;
    planet.setTexture(loadTexture(texture));
    planet.setDependsOnLight(dependsOnLight);
    planet.setCoreRadius(coreRadius);
    planet.setRotationRadius(rotationRadius);
    planet.setTranslationAngularSpeed(translationAngularSpeed);   
    planet.setRotationAngularSpeed(rotationAngularSpeed);
    return planet;
}