#ifndef _MENU_H
#define _MENU_H

#include "Stage.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include "../../BaseClasses/Header/Button.h"

class Menu: public Stage {

    private:
        void drawButtons();

    public:
        Menu();
        
        void drawAndMove() override;
        int stageKeyboard() override;
        void colider()override{}
        void callWaves() override {}
        void remover() override{}

};

#endif