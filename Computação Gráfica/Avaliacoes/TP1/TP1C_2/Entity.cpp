#include "Entity.h"

#include <stdio.h>

int Entity::Entity::getDisplayListModel(){return this->displayListModel;}
void Entity::setDisplayListModel(int displayListModel){this->displayListModel = displayListModel;}

double Entity::getHp(){return this->hp;}
void Entity::setHp(double hp){this->hp = hp;}

GLboolean Entity::getOnScreen(){return this->onScreen;}
void Entity::setOnScreen(GLboolean onScreen){this->onScreen = onScreen;}

OrderedPair Entity::getMidPoint(){
    //printf("Entrei getMidPoint\n");
    return this->midPoint;}

void Entity::setMidPoint(OrderedPair midPoint){
        //printf("added setMidPoint\n");

    this->midPoint = midPoint;}

OrderedPair Entity::getMax(){return this->max;}
void Entity::setMax(OrderedPair max){this->max = max;}

OrderedPair Entity::getMin(){return this->min;}
void Entity::setMin(OrderedPair min){this->min = min;}

OrderedPair* Entity::getHitbox(){return this->hitbox;}
void Entity::setHitbox(OrderedPair* hitbox){
    for(int i=0; i < sizeof(this->hitbox) / sizeof(OrderedPair); i++)
        this->hitbox[i] = hitbox[i];
}