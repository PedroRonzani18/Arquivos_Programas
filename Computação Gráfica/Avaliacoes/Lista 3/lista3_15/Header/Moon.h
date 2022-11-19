#ifndef _MOON_H
#define _MOON_H

#include <GL/freeglut.h>
#include <vector>

class Moon{
    private:
        GLuint texture;
        double coreRadius; // raio do planeta
        double rotationRadius; // radio do movimento de rotação
        double angle; // angulo inicial do movimento de rotação
        double angularSpeed; // velocidade angular do movimento de rotação
        double orbitSpeed;

    public:
        Moon(){}
        Moon(GLuint texture, double coreRadius, double rotationRadius, double angularSpeed);

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

        static Moon createPlanetTemplate(double angle, double coreRadius, double rotationRadius, double angularSpeed);
};

#endif