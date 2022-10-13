#include "StageManager.h"

int StageManager::colisionManager()
{
    return 0;
}


int StageManager::getState(){

return this->state;

};

void StageManager::setState(int state){

this->state = state;

};

int StageManager::gameOverVerify(){return 0;}

void StageManager::gameInit()
{
    Player p;
    this->currentStage.addEntity(&p);
}