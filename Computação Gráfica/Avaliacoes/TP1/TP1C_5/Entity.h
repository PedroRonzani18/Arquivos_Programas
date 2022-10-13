#ifndef _ENTITY_H
#define _ENTITY_H

#include <GL/freeglut.h>
#include <stdbool.h>
#include <vector>
#include "OrderedPair.h"

class Entity{
    private:
        int displayListModel;
        GLboolean onScreen;
        OrderedPair midPoint;
        OrderedPair max;
        OrderedPair min;
        std::vector<OrderedPair> hitbox;

    public:
        Entity(int displayListModel, 
        OrderedPair max, OrderedPair min);

        virtual int getDisplayListModel();
        virtual void setDisplayListModel(const int& displayListModel);

        virtual GLboolean getOnScreen();
        virtual void setOnScreen(const GLboolean& onScreen);

        virtual OrderedPair& getMidPoint();
        virtual void setMidPoint(const OrderedPair& midpoint);
        virtual void Entity::setMidPoint();

        virtual OrderedPair& getMax();
        virtual void setMax(const OrderedPair& max);

        virtual OrderedPair& getMin();
        virtual void setMin(const OrderedPair& min);

        virtual std::vector<OrderedPair>& getHitbox();
        virtual void setHitbox(const std::vector<OrderedPair> &hitbox);

        virtual void push_backHitbox(const OrderedPair& pair);
};


#endif