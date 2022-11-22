#include "../Header/Moon.h"
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"

Moon::Moon(double angle, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed)
{
    this->angle = angle;
    this->texture = texturesId[10];
    this->coreRadius = coreRadius;
    this->rotationRadius = rotationRadius;
    this->translationAngularSpeed = translationAngularSpeed;
}

Moon Moon::createPlanetTemplate(double angle, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed)
{
    Moon moon;
    moon.setAngle(angle);
    moon.setTexture(texturesId[10]);
    moon.setCoreRadius(coreRadius);
    moon.setRotationRadius(rotationRadius);
    moon.setTranslationAngularSpeed(translationAngularSpeed);   
    moon.setRotationAngularSpeed(rotationAngularSpeed);
    return moon;
}