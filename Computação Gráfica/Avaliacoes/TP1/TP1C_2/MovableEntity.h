#ifndef _MOVABLEENTITY_H
#define _MOVABLEENTITY_H

#include "Entity.h"
#include "OrderedPair.h"

class MovableEntity: public Entity{

    private:
        OrderedPair velocity;

        double angle;
        double angularSpeed;

        int moveType;
        int angularMoveType;

    public:
        OrderedPair getVelocity();
        void setVelocity(OrderedPair Velocity);

        double getAngle();
        void setAngle(double angle);

        double getAngularSpeed();
        void setAngularSpeed(double angularSpeed);

        int getMoveType();
        void setMoveType(int moveType);

        int getAngularMoveType();
        void setAngularMoveType(int angularMoveType);

        void move(); // movimentação padrão da entidade
        void angularMove(); // movimentação angula padrão da entidade
        void scaleMove(double scale); // movimentação usando escala de uma entidade
};

#endif