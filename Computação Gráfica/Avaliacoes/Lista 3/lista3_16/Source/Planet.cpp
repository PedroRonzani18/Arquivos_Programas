#include "../Header/Planet.h"
#include "../Header/drawings.h"

Planet Planet::createPlanetTemplate(GLuint texture, bool dependsOnLight, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed)
{
    Planet planet;
    planet.setTexture(texture);
    planet.setDependsOnLight(dependsOnLight);
    planet.setCoreRadius(coreRadius);
    planet.setRotationRadius(rotationRadius);
    planet.setTranslationAngularSpeed(translationAngularSpeed);   
    planet.setRotationAngularSpeed(rotationAngularSpeed);
    return planet;
}