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
        double translationAngularSpeed; // velocidade angular do movimento de rotação ao redor do sol (movimento de translação)
        double rotationAngularSpeed; // velocidade angular de rotação no proprio eixo ( movimento de rotação )
        bool dependsOnLight;
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

        double getTranslationAngularSpeed(){return this->translationAngularSpeed;}
        void setTranslationAngularSpeed(double translationAngularSpeed){this->translationAngularSpeed = translationAngularSpeed;}

        double getRotationAngularSpeed(){return this->rotationAngularSpeed;}
        void setRotationAngularSpeed(double rotationAngularSpeed){this->rotationAngularSpeed = rotationAngularSpeed;}

        bool doesDependsOnLight(){return this->dependsOnLight;}
        void setDependsOnLight(bool dependsOnLight){this->dependsOnLight = dependsOnLight;}

        static Planet createPlanetTemplate(const char* texture, bool dependsOnLight, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed);

        std::vector<Moon> getMoons(){return this->moons;}
        void addMoon(Moon moon){this->moons.push_back(moon);}

};

#endif