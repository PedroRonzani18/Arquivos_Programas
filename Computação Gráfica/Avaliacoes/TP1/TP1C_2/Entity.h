#ifndef _ENTITY_H
#define _ENTITY_H

#include <GL/freeglut.h>
#include <stdbool.h>
#include "OrderedPair.h"

class Entity{
    private:
        int displayListModel;
        double hp;
        
        GLboolean onScreen;

        OrderedPair midPoint;
        OrderedPair max;
        OrderedPair min;
        OrderedPair hitbox[4];

    public:
        virtual int getDisplayListModel();
        virtual void setDisplayListModel(int displayListModel);

        virtual double getHp();
        virtual void setHp(double hp);

        virtual GLboolean getOnScreen();
        virtual void setOnScreen(GLboolean onScreen);

        virtual OrderedPair getMidPoint();
        virtual void setMidPoint(OrderedPair midPoint);

        virtual OrderedPair getMax();
        virtual void setMax(OrderedPair max);

        virtual OrderedPair getMin();
        virtual void setMin(OrderedPair min);

        virtual OrderedPair* getHitbox();
        virtual void setHitbox(OrderedPair* hitbox);
};


#endif