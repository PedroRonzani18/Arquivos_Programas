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

    speedLook.x = 0.1;
    speedLook.y = 0.1;
    speedLook.z = 0.1;

    sensibilidade = 0.01;

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
    float offset_x = (xMouse - previousPosition.x) * sensibilidade;
    float offset_y = (yMouse - previousPosition.y) * sensibilidade;

    previousPosition.x = xMouse;
    previousPosition.y = yMouse;

    theta+=offset_x;
    fi+=offset_y;

    if(fi>89)
        fi = 89;
    if(fi < -89)
        fi = -89;

    look.x = cos(theta)*cos(fi);
    look.y = sin(fi);
    look.z = sin(theta)*cos(fi);


    midPoint.x +=(keys.w-keys.s) * speedLook.x * look.x ; // + vetor normal a direta dele
    midPoint.y +=(keys.w-keys.s) * speedLook.y * look.y ; // + vetor normal a direta dele
    midPoint.z +=(keys.w-keys.s) * speedLook.z * look.z ; // + vetor normal a direta dele (keyboard.d-keyboard.a)*speed



/*
    midPoint.x += (keys.d - keys.a) * 0.1;
    midPoint.y += (keys.space - keys.f) * 0.1;
    midPoint.z += (keys.s - keys.w) * 0.1;

    focus.x += (keys.d - keys.a) * 0.1;
    focus.y += (keys.space - keys.f) * 0.1;
    focus.z += (keys.s - keys.w) * 0.1;
*/
                     
}

void Camera::setupCamera()
{
    //printf("Focus: (%.2f,%.2f,%.2f)\nMidpoint: (%.2f,%.2f,%.2f)\n\n",focus.x,focus.y,focus.z,midPoint.x,midPoint.y,midPoint.z);
    /*
    gluLookAt(focus.x   , focus.y   , focus.z,
              midPoint.x, midPoint.y, midPoint.z,
              upVec.x   , upVec.y   , upVec.z);*/
/*
    gluLookAt(1*(xMouse-larguraJanela/2)/(larguraJanela/16), -1*(yMouse-alturaJanela/2)/(alturaJanela/16) + 3, 5,
            0, 0, 0,
            0, 1, 0);*/

        gluLookAt(midPoint.x,midPoint.y,midPoint.z,
                  look.x+midPoint.x,look.y+midPoint.y, look.z+midPoint.z,
                  0, 1, 0);
}