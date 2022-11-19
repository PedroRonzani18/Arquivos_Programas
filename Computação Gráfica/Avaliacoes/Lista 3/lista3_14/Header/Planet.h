#ifndef _PLANET_H
#define _PLANET_H

#include <GL/freeglut.h>
#include <vector>
#include "Moon.h"

class Planet{
    private:
        GLuint texture;
        double coreRadius; // raio do planeta
        double rotationRadius; // radio do movimento de rotação
        double angle; // angulo do movimento de rotação
        double angularSpeed; // velocidade angular do movimento de rotação
        double orbitSpeed;
        std::vector<Moon> moons;

    public:
        Planet(){}
        Planet(GLuint texture, double coreRadius, double rotationRadius, double angularSpeed);

        GLuint getTexture(){return this->texture;}
        void setTexture(GLuint texture){this->texture = texture;}

        double getCoreRadius(){return this->coreRadius;}
        void setCoreRadius(double coreRadius){this->coreRadius = coreRadius;}

        double getRotationRadius(){return this->rotationRadius;}
        void setRotationRadius(double rotationRadius){this->rotationRadius = rotationRadius;}

        double getAngle(){return this->angle;}
        void setAngle(double angle){this->angle = angle;}

        double getAngularSpeed(){return this->angularSpeed;}
        void setAngularSpeed(double angularSpeed){this->angularSpeed = angularSpeed;}

        double getOrbitSpeed(){return this->orbitSpeed;}
        void setOrbitSpeed(double orbitSpeed){this->orbitSpeed = orbitSpeed;}

        static Planet createPlanetTemplate(const char* texture, double coreRadius, double rotationRadius, double angularSpeed, double orbitSpeed);

        std::vector<Moon> getMoons(){return this->moons;}
        void addMoon(Moon moon){this->moons.push_back(moon);}

};

#endif