#include "../Header/Camera.h"
#include "../Header/globalParameters.h"
#include <cmath>
#include "ogldev_math_3d.h"

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

Camera::Camera()
{
    position.x = 0;
    position.y = 0;
    position.z = 0;

    upVec.x = 0;
    upVec.y = 1;
    upVec.z = 0;

    viewDirection.x = 0;
    viewDirection.y = 0;
    viewDirection.z = -1;

    calculaVetorDiretor();
}

void Camera::mouseUpdate(Coord newMousePosition)
{
    Coord mosueDelta;
    mosueDelta.x = newMousePosition.x - oldMousePosition.x;
    mosueDelta.y = newMousePosition.y - oldMousePosition.y;

    

    oldMousePosition = newMousePosition;
}


void Camera::move()
{
    // outra possibilidade: moder o ponto central de acordo com o vetor que liga foco com centro ( p + v = p')

/*
    fi += (keys[6] - keys[7]) * 2;

    focus.z = ro * sin(grRad(fi)) * cos(grRad(theta)); 
    focus.x = ro * sin(grRad(fi)) * sin(grRad(theta)); 
    focus.y = ro * cos(grRad(fi));

    calculaVetorDiretor();

    position.z += (keys[0] - keys[2]) * viewDirection.z * 0.1;
    position.y += (keys[0] - keys[2]) * viewDirection.y* 0.1;
    position.x += (keys[0] - keys[2]) * viewDirection.x* 0.1;

    focus.z += (keys[0] - keys[2]) * viewDirection.z* 0.1;
    focus.y += (keys[0] - keys[2]) * viewDirection.y* 0.1;
    focus.x += (keys[0] - keys[2]) * viewDirection.x* 0.1;

    printf("position: (%.2f,%.2f,%.2f)   Focus: (%.2f,%.2f,%.2f)   Vetor: (%.2f,%.2f,%.2f)\n",position.x,position.y,position.z,focus.x,focus.y,focus.z,viewDirection.x,viewDirection.y,viewDirection.z);
*/

/*
    position.x += (keys[3] - keys[1]) * 0.1;
    position.y += (keys[4] - keys[5]) * 0.1;
    position.z += (keys[2] - keys[0]) * 0.1;
    
    focus.x += (keys[3] - keys[1]) * 0.1;
    focus.y += (keys[4] - keys[5]) * 0.1;
    focus.z += (keys[2] - keys[0]) * 0.1;
*/
    
    /*
    position.z += (keys[3] - keys[1]) * sin(grRad(fi)) * cos(grRad(theta)); 
    position.x += (keys[4] - keys[5]) * sin(grRad(fi)) * sin(grRad(theta)); 
    position.y += (keys[2] - keys[0]) * cos(grRad(fi)); 
    */
    
/*
    position.z = sin(grRad(fi)) * cos(grRad(theta)); 
    position.x = sin(grRad(fi)) * sin(grRad(theta)); 
    position.y = cos(grRad(fi)); 
*/

/*
    focus.z = ro * sin(grRad(fi)) * cos(grRad(theta)); 
    focus.x = ro * sin(grRad(fi)) * sin(grRad(theta)); 
    focus.y = ro * cos(grRad(fi));
    */                         
}

void Camera::setupCamera()
{
    /*
    gluLookAt(focus.x   , focus.y   , focus.z,
              position.x, position.y, position.z,
              upVec.x   , upVec.y   , upVec.z);
              */

    gluLookAt(position.x                  , position.y                  , position.z,
              position.x + viewDirection.x, position.y + viewDirection.y, position.z + viewDirection.z,
              upVec.x,upVec.y,upVec.z);
}