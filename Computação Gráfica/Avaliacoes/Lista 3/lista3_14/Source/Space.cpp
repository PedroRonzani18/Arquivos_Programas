#include "../Header/Space.h"
#include "../Header/drawings.h"

void Space::drawAndMove(double time)
{
    glDisable(GL_LIGHTING);
    drawCorpse(&estrelas,time);
    glEnable(GL_LIGHTING);

    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        glDisable(GL_LIGHTING);
            drawCorpse(&sol,time);
        glEnable(GL_LIGHTING);

        for(Planet planet: planetas)
        {
            glPushMatrix();
                drawCorpse(&planet,time);

                for(Moon moon: planet.getMoons())
                {
                    glPushMatrix();
                        drawCorpse(&moon,time);
                    glPopMatrix();
                }

            glPopMatrix();
        }
    glPopMatrix();
    
}