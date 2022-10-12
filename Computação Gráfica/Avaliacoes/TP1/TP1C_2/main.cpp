#include "OrderedPair.h"
#include "Entity.h"
#include "MovableEntity.h"
#include "Enemy.h"
#include "Player.h"

#include <stdio.h>

#include <iostream>

using namespace std;

int main()
{
    MovableEntity e;
    e.setAngle(1);
    e.setMidPoint(4,5);

    printf("(%.0f,%.0f)\n",e.getMidPoint().getX(),e.getMidPoint().getY());

    printf("\n");

    e.setMidPoint(2,e.getMidPoint().getY());

    printf("(%.0f,%.0f)\n",e.getMidPoint().getX(),e.getMidPoint().getY());

    Player p;
    Enemy en;

    p.fire();
    en.fire();
}