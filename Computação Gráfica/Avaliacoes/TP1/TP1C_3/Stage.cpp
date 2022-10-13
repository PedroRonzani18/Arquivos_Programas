#include "Stage.h"

void Stage::stageKeybord()
{
    
}

int Stage::getCdStage()
{
    return this->cdStage;
}
void Stage::setCdStage(int cdStage)
{
    this-> cdStage = cdStage;

}

int Stage::getBackgound()
{
    return this->background;
}
void Stage::setBackground(int background)
{
    this->background = background;
}

void Stage::addEntity(Entity* e)
{
    this->entities.push_back(*e);
}