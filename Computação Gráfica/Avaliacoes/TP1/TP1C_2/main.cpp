#include "OrderedPair.h"
#include "Entity.h"
#include "MovableEntity.h"

#include <stdio.h>

using namespace std;

int main()
{
    MovableEntity e;
    e.setAngle(1);

    e.getMidPoint().setX(3);
    e.getMidPoint().setY(55);

    printf("Ag: %f, %f com \t%p\n",e.getAngle(),e.getMidPoint().getX(),e.getMidPoint().getEnd());    

}