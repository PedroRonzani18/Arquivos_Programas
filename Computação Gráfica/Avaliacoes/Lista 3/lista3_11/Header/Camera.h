#ifndef _CAMERA_H
#define _CAMERA_H

#include "Coord.h"

class Camera{
    private:
        Coord midPoint;
        Coord focus;
        float theta;
        float fi;
        Coord angle;

    public:
        Camera();

        Coord getCoordinates(){return this->midPoint;}
        void setCoordinates(Coord midPoint){this->midPoint = midPoint;}

        Coord getAngle(){return this->angle;}
        void setAngle(Coord angle){this->angle = angle;}

        void move();
};

#endif