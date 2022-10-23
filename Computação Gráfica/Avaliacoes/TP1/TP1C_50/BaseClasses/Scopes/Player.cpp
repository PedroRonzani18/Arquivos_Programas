#include "../Header/Player.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include <stdio.h>
#include "../../GeneralFiles/Header/drawings.h"
#include "../../GeneralFiles/Header/colisionManager.h"

Player::Player() : MovableEntity(), Ballistic()
{
    this->type = 0;
    this->alteredFireRate = 1;
    this->angle = 0;
    this->angularSpeed = 0;
    this->currentProjectile = Projectile(2);
    this->typeTiroManager = 2;
    this->displayListModel = textures[14];
    this->numberOfShots = 3;
    this->onScreen = GL_TRUE;
    this->imortality = 0;
    this->hp = 3;
    this->fireRatePeriod = 0;

    this->setMax(20,20);
    this->setMin(-20,-20);
    this->setResize(0.5);
    this->setHitbox();
    this->setMidPoint();
    this->setVelocity(1.7,1.7);   
}

void Player::move()
{
    this->setMidPoint(this->midPoint.getX() + (keys[2] - keys[3]) * (this->velocity.getX()),
                      this->midPoint.getY() + (keys[0] - keys[1]) * (this->velocity.getY()));
    mantainInsideScreen(*this);
    generalHitBoxMovement();
}

void Player::scaleMove(const double& scale){}

// Projectile Player::createProject(double xPlus, double yPlus, int xVel, int yVel, Projectile* auxP)
// {
//     auxP->setMidPoint(this->midPoint.getX() + xPlus,this->midPoint.getY() + yPlus);
//     auxP->setVelocity(this->velocity.getX() * xVel, this->velocity.getY() * yVel);
//     return *auxP;
// }

Projectile Player::createProject(Projectile* auxP, double angle)
{
    auxP->setMidPoint(this->max.getX() * cos(this->angle +  angle) + this->midPoint.getX(),
                      this->max.getY() * sin(this->angle +  angle) + this->midPoint.getY());
    return *auxP;
}

std::vector<Projectile> Player::fire()
{
    Projectile projectile1 = this->currentProjectile;

    projectile1.setOwner(1);

    std::vector<Projectile> vec;

    switch (this->typeTiroManager)
    {
        case 0: // tiro reto
            switch(numberOfShots)
            {
                case 3:
                    //projectile1.setMidPoint(this->midPoint.getX(),this->midPoint.getY() + this->max.getY());
                    //vec.push_back(projectile1);
                    //vec.push_back(createProject(0,max.getY(), 1, 1, &projectile1));
                    vec.push_back(createProject(&projectile1, M_PI/2));
                    
                case 2:
                    //projectile1.setMidPoint(12 * cos(this->angle +  M_PI/4) + this->midPoint.getX(),
                    //                        12 * sin(this->angle +  M_PI/4) + this->midPoint.getY());
                    //vec.push_back(projectile1);
                    //projectile1.setMidPoint(12 * cos(this->angle + M_PI/2 + M_PI/4) + this->midPoint.getX(),
                    //                        12 * sin(this->angle + M_PI/2 + M_PI/4) + this->midPoint.getY());
                    //vec.push_back(projectile1);
                    //vec.push_back(createProject(12 * cos(this->angle +   M_PI/4),12 * sin(this->angle +   M_PI/4), 1, 1, &projectile1));
                    //vec.push_back(createProject(12 * cos(this->angle + 3*M_PI/4),12 * sin(this->angle + 3*M_PI/4), 1, 1, &projectile1));
                    vec.push_back(createProject(&projectile1, M_PI/4));
                    vec.push_back(createProject(&projectile1, 3*M_PI/4));
                    
                    break;

                case 1:
                    //projectile1.setMidPoint(this->midPoint.getX(),this->midPoint.getY() + this->max.getY());
                    //vec.push_back(projectile1);
                    //vec.push_back(createProject(0,max.getY(), 1, 1, &projectile1));
                    vec.push_back(createProject(&projectile1, M_PI/2));
                    break;
                
            }
            break;
        
        case 1: // tiro que bate nas paredes
            switch(numberOfShots)
            {
                case 1:
                    projectile1.setHp(2);
                    break;
                case 2:
                    projectile1.setHp(3);
                    break;
                case 3:
                    projectile1.setHp(4);
                    break;
            }
            //projectile1.setMidPoint(12 * cos(this->angle +  M_PI/4) + this->midPoint.getX(),
            //                        12 * sin(this->angle +  M_PI/4) + this->midPoint.getY());
            
            //vec.push_back(projectile1);
            //vec.push_back(createProject(12 * cos(this->angle +   M_PI/4), 12 * sin(this->angle +   M_PI/4),1,1, &projectile1));
            vec.push_back(createProject(&projectile1, M_PI/4));

            //projectile1.getVelocity().setX(-projectile1.getVelocity().getX());
            
            //projectile1.setMidPoint(12 * cos(this->angle + M_PI/2 + M_PI/4) + this->midPoint.getX(),
            //                        12 * sin(this->angle + M_PI/2 + M_PI/4) + this->midPoint.getY());
            //vec.push_back(projectile1);
            //vec.push_back(createProject(12 * cos(this->angle + 3*M_PI/4), 12 * sin(this->angle + 3*M_PI/4),-1,1, &projectile1));

            projectile1.getVelocity().setX(-projectile1.getVelocity().getX());
            vec.push_back(createProject(&projectile1, 3*M_PI/4));

            break;
        
        case 2: // tiro que segue
            switch (numberOfShots)
            {
            case 1:
                // projectile1.setMidPoint(this->midPoint.getX(),this->midPoint.getY() + this->max.getY());
                // vec.push_back(projectile1);
                vec.push_back(createProject(&projectile1, M_PI/2));
                break;
            case 2:
                // projectile1.setMidPoint(12 * cos(this->angle) + this->midPoint.getX(),
                //                         12 * sin(this->angle) + this->midPoint.getY());
                // vec.push_back(projectile1);
                vec.push_back(createProject(&projectile1, M_PI/4));
                
                // projectile1.setMidPoint(12 * cos(this->angle + M_PI) + this->midPoint.getX(),
                //                         12 * sin(this->angle + M_PI) + this->midPoint.getY());
                // vec.push_back(projectile1);
                vec.push_back(createProject(&projectile1, 3*M_PI/4));
                break;
            case 3:
                //projectile1.setMidPoint(this->midPoint.getX(),this->midPoint.getY() + this->max.getY());
                //vec.push_back(projectile1);
                vec.push_back(createProject(&projectile1, M_PI/2));


                //projectile1.setMidPoint(12 * cos(this->angle) + this->midPoint.getX(),
                //                       12 * sin(this->angle) + this->midPoint.getY());
            
                //vec.push_back(projectile1);
                vec.push_back(createProject(&projectile1, 0));


                //projectile1.setMidPoint(12 * cos(this->angle + M_PI) + this->midPoint.getX(),
                //                        12 * sin(this->angle + M_PI) + this->midPoint.getY());
                //vec.push_back(projectile1);
                vec.push_back(createProject(&projectile1, M_PI));

                break;
            }
            break;
    }

    this->fireRatePeriod = this->currentProjectile.getDefaultFireRate() * this->alteredFireRate;
    return vec;
}



void Player::upgradeManager(int upgradeType)
{
    Projectile* u;
    switch (upgradeType)
    {
        case 1: //type 1: aumenta o tanto de tiro 
            if(this->numberOfShots < 3)
                this->numberOfShots += 1;
            printf("numero de tiros: %d\n", this->numberOfShots);
            break;
        
        case 2: //type 2: aumeta o fireRate
            this->alteredFireRate /= 1.17;
            printf("fireRate: %f\n", this->alteredFireRate);
            break;

        case 3: //type 3: troca de projetil
            this->typeTiroManager ++;
            if(this->typeTiroManager == 3)
                this->typeTiroManager = 0;
            u = new Projectile(typeTiroManager);
            this->currentProjectile = *u;
            printf("troca de tiro: %d\n", this->currentProjectile.getType());
            break;

        case 4: //type 4: aumenta vida
            if(this->hp < 3)
                this->hp ++;
            printf("HP: %f\n", this->hp);
            break;

        case 5:  //type 5: aumenta o dano
            this->currentProjectile.setDamage(this->currentProjectile.getDamage() + 5);
            printf("aumenta dano: %f\n", this->currentProjectile.getDamage());
            break;
    }
}
