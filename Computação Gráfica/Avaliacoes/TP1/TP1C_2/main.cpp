#include "OrderedPair.h"
#include "Entity.h"
#include "MovementEntity.h"

#include <stdio.h>

using namespace std;

int main()
{
    MovementEntity e;
    e.setAngle(1);

    printf("Ag: %f",e.getAngle());
}