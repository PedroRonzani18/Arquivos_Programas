#ifndef _ENEMY_H
#define _ENEMY_H

#include "MovableEntity.h"
#include "Ballistic.h"
#include "Projectile.h"
#include "../../GeneralFiles/Header/colisionManager.h"

class Enemy: public MovableEntity, public Ballistic{
    protected:
        int killValue; // valor em pontos de matar o inimigo
        int dropPercentage; //probbilidade do inimigo dropar um coletavel 
        GLboolean onscreenTestable;
        OrderedPair followPoint;
        int continueMove;

        void move1();

    public:
        Enemy(){}

        Enemy(int type);

        Projectile createProject(Projectile* auxP, double angle);

        int getKillValue(){return this->killValue;}
        void setKillValue(const int& killValue){this->killValue = killValue;}

        int getDropPercentage(){return this->dropPercentage;}
        void setDropPercentage(const int& dropPercentage){this->dropPercentage = dropPercentage;}

        GLboolean getOnscreenTestable(){return this->onscreenTestable;}
        void setOnscreenTestable(const GLboolean& onscreenTestable){this->onscreenTestable = onscreenTestable;}

        OrderedPair getFollowPoint(){return this->followPoint;}
        void setFollowPoint(const double& x, const double& y){this->followPoint.setX(x); this->followPoint.setY(y);}
        void setFollowPoint(const OrderedPair& followPoint){this->followPoint = followPoint;}

        int getContinueMove(){return this->continueMove;}

        void parabolicMoveTemplate(double a, double b, double c);
        void senoidMoveTemplate(double a, double b, double c, double d);
        void kamikazeMove();
        void move() override;
        void scaleMove(const double& scale) override;
        std::vector<Projectile> fire() override;
};  

#endif