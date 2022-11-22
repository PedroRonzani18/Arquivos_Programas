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
    
    midPoint.x += (keys[3] - keys[1]) * 0.1;
    midPoint.y += (keys[4] - keys[5]) * 0.1;
    midPoint.z += (keys[2] - keys[0]) * 0.1;

    focus.x += (keys[3] - keys[1]) * 0.1;
    focus.y += (keys[4] - keys[5]) * 0.1;
    focus.z += (keys[2] - keys[0]) * 0.1;
    
    /*
    fi += (keys[6] - keys[7]) * 2;


    if(fi == 180 + 2)
    {
        printf("AAAAAAAAAAAAAAAAAAAAAAAAA %.2f\n",fi);
        theta += 180;
        printf("Theta: %f\n",theta);
    }

    if(fi == 360 + 2)
    {
        printf("BBBBBBBBBBBBBBBBBAA %.2f\n",fi);
        theta += 180;
        fi = 2;
        printf("Theta: %f\n",theta);
    }
    
    if(theta == 360)
        theta = 0;
    */

/*
    printf("Theta: %f   %f\n",fi ,fic);

    if(fi > 180 && fic <= 180) // passou do estado de olhar para o chao
    {
        printf("entrei\n");
        fiStatus = 1;
        theta += 180;
    } 

    if(fi < 180 && fic >= 180) 
    {
        fiStatus = 1;
        theta -= 180;
    }
*/

/*
    midPoint.z = sin(grRad(fi)) * cos(grRad(theta)); 
    midPoint.x = sin(grRad(fi)) * sin(grRad(theta)); 
    midPoint.y = cos(grRad(fi)); 
*/

/*
    focus.z = ro * sin(grRad(fi)) * cos(grRad(theta)); 
    focus.x = ro * sin(grRad(fi)) * sin(grRad(theta)); 
    focus.y = ro * cos(grRad(fi));
    */                         
}

void Camera::setupCamera()
{
    //printf("Focus: (%.2f,%.2f,%.2f)\nMidpoint: (%.2f,%.2f,%.2f)\n\n",focus.x,focus.y,focus.z,midPoint.x,midPoint.y,midPoint.z);
    gluLookAt(focus.x   , focus.y   , focus.z,
              midPoint.x, midPoint.y, midPoint.z,
              upVec.x   , upVec.y   , upVec.z);
}