#ifndef _CAMERA_H
#define _CAMERA_H

#include "Coord.h"

class Camera{
    private:
        Coord position;
        Coord upVec;
        Coord viewDirection;
        Coord oldMousePosition;


        void calculaVetorDiretor();

    public:
        Camera();

        Coord getCoordinates(){return this->position;}
        void setCoordinates(Coord position){this->position = position;}

        void move();
        void mouseUpdate(Coord newMousePosition);
        void setupCamera();
};

#endif