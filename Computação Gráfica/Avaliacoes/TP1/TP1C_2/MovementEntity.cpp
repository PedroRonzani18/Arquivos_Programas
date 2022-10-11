#include "MovementEntity.h"

OrderedPair MovementEntity::getVelocity(){return this->velocity;}
void MovementEntity::setVelocity(OrderedPair velocity){this->velocity = velocity;}

double MovementEntity::getAngle(){return this->angle;}
void MovementEntity::setAngle(double angle){this->angle = angle;}

double MovementEntity::getAngularSpeed(){return this->angularSpeed;}
void MovementEntity::setAngularSpeed(double angularSpeed){this->angularSpeed = angularSpeed;}

int MovementEntity::getMoveType(){return this->moveType;}
void MovementEntity::setMoveType(int moveType){this->moveType = moveType;}

int MovementEntity::getAngularMoveType(){return this->angularMoveType;}
void MovementEntity::setAngularMoveType(int angularMoveType){this->angularMoveType = angularMoveType;}

void MovementEntity::move(){}
void MovementEntity::angularMove(){}
void MovementEntity::scaleMove(double scale){}