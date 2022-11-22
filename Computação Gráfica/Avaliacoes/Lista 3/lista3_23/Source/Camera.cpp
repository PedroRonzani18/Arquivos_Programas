#include "../Header/Camera.h"
#include "../Header/globalParameters.h"
#include <cmath>

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

Camera::Camera()
{
    midPoint.x = -1.6;
    midPoint.y = 0.4;
    midPoint.z = 0.5;

    upVec.x = 0;
    upVec.y = 1;
    upVec.z = 0;

    focus.x = -1.6;
    focus.y = 3.4;
    focus.z = 5.5;

    fi = 0;
    fiStatus = 0;
    theta = 0;
    ro = calcudlateRo();
}

float Camera::calcudlateRo()
{
    return sqrt(pow(midPoint.x-focus.x,2) + 
                pow(midPoint.y-focus.y,2) + 
                pow(midPoint.z-focus.z,2));
}

void Camera::move()
{
    
    midPoint.x += (keys.d - keys.a) * 0.1;
    midPoint.y += (keys.space - keys.f) * 0.1;
    midPoint.z += (keys.s - keys.w) * 0.1;

    focus.x += (keys.d - keys.a) * 0.1;
    focus.y += (keys.space - keys.f) * 0.1;
    focus.z += (keys.s - keys.w) * 0.1;
                         
}

void Camera::setupCamera()
{
    //printf("Focus: (%.2f,%.2f,%.2f)\nMidpoint: (%.2f,%.2f,%.2f)\n\n",focus.x,focus.y,focus.z,midPoint.x,midPoint.y,midPoint.z);
    gluLookAt(focus.x   , focus.y   , focus.z,
              midPoint.x, midPoint.y, midPoint.z,
              upVec.x   , upVec.y   , upVec.z);
}