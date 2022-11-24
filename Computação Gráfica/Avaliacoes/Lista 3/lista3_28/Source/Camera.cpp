#include "../Header/Camera.h"
#include "../Header/globalParameters.h"
#include <cmath>

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

Camera::Camera()
{
    /*
    midPoint.x = 0;
    midPoint.y = 3;
    midPoint.z = 5;
    */


    midPoint.x = -33.57;
    midPoint.y = 19.86;
    midPoint.z = 3.67;

    
    look.x = 0.76;
    look.y = -0.63;
    look.z = 0.14;
    

    speedLook.x = 0.1;
    speedLook.y = 0.1;
    speedLook.z = 0.1;

    sensibilidade = 0.007;

    fi = 3.9;
    theta = 21.89;
    //printf("aaaaLook: (%.2f,%.2f,%.2f)   mid: (%.2f,%.2f,%.2f)\n",look.x,look.y,look.z,midPoint.x,midPoint.y,midPoint.z);

}

void Camera::move()
{
    float offset_x = (xMouse - previousPosition.x) * sensibilidade;
    float offset_y = (yMouse - previousPosition.y) * sensibilidade;

    previousPosition.x = xMouse;
    previousPosition.y = yMouse;

    theta+=offset_x;
    fi+=offset_y;

    if(tempo > 0.5)
    {
        if(fi<1.46)
            fi = 1.46;
        if(fi > 4.46)
            fi = 4.46;
    }


        look.x = cos(theta)*cos(fi);
        look.y = sin(fi);
        look.z = sin(theta)*cos(fi);

    //printf("Valor: %.2f\n",asin(-0.63));

    midPoint.x += speedLook.x * ((keys->w - keys->s) * look.x + (keys->d - keys->a) * (-look.z)); 
    midPoint.y += speedLook.y * ( keys->w - keys->s) * look.y ; 
    midPoint.z += speedLook.z * ((keys->w - keys->s) * look.z + (keys->d - keys->a) * (look.x)); // + vetor normal a direta dele (keyboard.d-keyboard.a)*speed                     

    //printf("Midpoint: (%.2f,%.2f,%.2f)     Look: (%.2f,%.2f,%.2f)\n",midPoint.x,midPoint.y,midPoint.z,look.x,look.y,look.z);]
    //printf("Theta: %.2f    Fi: %.2f\n",theta,fi);
}

void Camera::setupCamera()
{
    gluLookAt(midPoint.x         , midPoint.y         , midPoint.z         ,
              midPoint.x + look.x, midPoint.y + look.y, midPoint.z + look.z,
              0, 1, 0);
}