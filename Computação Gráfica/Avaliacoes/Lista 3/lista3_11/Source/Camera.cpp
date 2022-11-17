#include "../Header/Camera.h"
#include "../Header/globalParameters.h"

Camera::Camera()
{
    midPoint.x = 0;
    midPoint.y = 0;
    midPoint.z = 0;
}

void Camera::move()
{
    
    midPoint.x += (keys[3] - keys[1]) * 0.1;
    midPoint.y += (keys[4] - keys[5]) * 0.1;
    midPoint.z += (keys[2] - keys[0]) * 0.1;
}