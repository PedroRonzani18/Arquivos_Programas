#include "../Header/Space.h"
#include "../Header/drawings.h"

void Space::drawAndMove(double t)
{
    glDisable(GL_LIGHTING);
    drawCorpse(&estrelas,t);
    glEnable(GL_LIGHTING);

    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        glDisable(GL_LIGHTING);
        drawCorpse(&planetas[0],t);
        glEnable(GL_LIGHTING);

        glPushMatrix();

            drawCorpse(&planetas[1],t);

            glPushMatrix();
                drawCorpse(&planetas[2],t);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
    
}