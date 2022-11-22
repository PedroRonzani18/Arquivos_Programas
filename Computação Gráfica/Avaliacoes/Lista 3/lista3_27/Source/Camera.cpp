#include "../Header/Camera.h"
#include "../Header/globalParameters.h"
#include <cmath>

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

Camera::Camera()
{
    midPoint.x = 0;
    midPoint.y = 3;
    midPoint.z = 5;

    look.x = -0.5;
    look.y = -1;
    look.z = 0;

    speedLook.x = 0.1;
    speedLook.y = 0.1;
    speedLook.z = 0.1;

    sensibilidade = 0.01;

    fi = 3;
    theta = 0;
}

void Camera::move()
{
    float offset_x = (xMouse - previousPosition.x) * sensibilidade;
    float offset_y = (yMouse - previousPosition.y) * sensibilidade;

    previousPosition.x = xMouse;
    previousPosition.y = yMouse;

    theta+=offset_x;
    fi+=offset_y;

    if(tempo > 3)
    {
        if(fi<1.46)
            fi = 1.46;
        if(fi > 4.46)
            fi = 4.46;
    }

    look.x = cos(theta)*cos(fi);
    look.y = sin(fi);
    look.z = sin(theta)*cos(fi);

    midPoint.x +=(keys->w-keys->s) * speedLook.x * look.x ; // + vetor normal a direta dele
    midPoint.y +=(keys->w-keys->s) * speedLook.y * look.y ; // + vetor normal a direta dele
    midPoint.z +=(keys->w-keys->s) * speedLook.z * look.z ; // + vetor normal a direta dele (keyboard.d-keyboard.a)*speed                     
}

void Camera::setupCamera()
{
    gluLookAt(midPoint.x         , midPoint.y         , midPoint.z         ,
              midPoint.x + look.x, midPoint.y + look.y, midPoint.z + look.z,
              0, 1, 0);
}