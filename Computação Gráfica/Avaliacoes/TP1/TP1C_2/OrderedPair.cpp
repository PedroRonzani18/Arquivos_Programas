#include "OrderedPair.h"

#include <stdio.h>

double OrderedPair::getX(){
    printf("Entrei getX: %f, \t\t%p\n",this->x,&this->x);
    return this->x;}



void OrderedPair::setX(double x){
    printf("Entrei setX com x=%f e \t%p\n",this->x,&this->x);
    this->x = x;
    printf("After: %f com end: \t%p\n",this->x,&this->x);}

void* OrderedPair::getEnd(){return &this->x;z}



double OrderedPair::getY(){return this->y;}
void OrderedPair::setY(double y){this->y = y;}