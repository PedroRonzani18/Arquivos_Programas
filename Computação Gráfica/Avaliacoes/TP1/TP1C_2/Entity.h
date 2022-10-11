#ifndef _ENTITY_H
#define _ENTITY_H

#include <GL/freeglut.h>
#include <stdbool.h>
#include "OrderedPair.h"

class Entity{
    private:
        int displayListModel;
        double aspectRatio;
        double hp;
        
        GLboolean onscreen;

        OrderedPair midPoint;
        OrderedPair max;
        OrderedPair min;
        OrderedPair hitbox[4];
        OrderedPair alteredHitbox[4];
};


#endif