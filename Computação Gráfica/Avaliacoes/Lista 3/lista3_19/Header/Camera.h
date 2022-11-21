#ifndef _CAMERA_H
#define _CAMERA_H

#include "Coord.h"

class Camera{
    private:
        Coord midPoint;
        Coord focus;
        Coord upVec;
        float theta;
        float fi;
        float ro;
        Coord angle;
        int fiStatus; // indica se teoricamente 0   < fi < 180 (fistatus = 0)
                      //                        180 < fi < 360 (fistatus = 1)

    public:
        Camera();

        Coord getCoordinates(){return this->midPoint;}
        void setCoordinates(Coord midPoint){this->midPoint = midPoint;}

        Coord getAngle(){return this->angle;}
        void setAngle(Coord angle){this->angle = angle;}

        void move();
        float calcudlateRo();
        void setupCamera();
};

#endif