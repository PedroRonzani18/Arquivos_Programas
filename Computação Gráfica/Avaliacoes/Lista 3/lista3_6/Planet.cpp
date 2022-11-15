#include "Planet.h"

Planet::Planet(GLuint texture, double coreRadius, double rotationRadius, double angularSpeed){
            this->angle = 0;
            this->coreRadius = coreRadius;
            this->rotationRadius = rotationRadius;
            this->angularSpeed = angularSpeed;
        }