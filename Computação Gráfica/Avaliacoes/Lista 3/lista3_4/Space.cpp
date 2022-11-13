#include "Space.h"
#include "drawings.h"

void Space::drawAndMove(double t)
{
    glPushMatrix();
        //glTranslated(0,0,-6);// coloca ele mais para tras na tela
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        //drawCorpse(sun,t);
        drawCorpse(&planetas[0],t);

        glPushMatrix();

            drawCorpse(&planetas[1],t);

            glPushMatrix();
                drawCorpse(&planetas[2],t);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
    
}