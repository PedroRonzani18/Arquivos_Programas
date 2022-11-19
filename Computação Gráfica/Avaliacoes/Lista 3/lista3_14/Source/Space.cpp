#include "../Header/Space.h"
#include "../Header/drawings.h"

void Space::drawAndMove(double time)
{
    glPushMatrix();
        glDisable(GL_LIGHTING);
            drawCorpse(&estrelas,time);
        glEnable(GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        glDisable(GL_LIGHTING);
            drawCorpse(&sol,time);
        glEnable(GL_LIGHTING);

        for(Planet planet: planetas)
        {

        glTranslated(sol.getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
            glRotated(time * planet.getOrbitSpeed(),0,0,1);
        glTranslated(-sol.getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)

            glPushMatrix();
                drawCorpse(&planet,time);

                for(Moon moon: planet.getMoons())
                {
                    glPushMatrix();
                        drawCorpse(&moon,time);
                    glPopMatrix();
                }

            glPopMatrix();

        
            glRotated(time * planet.getOrbitSpeed(),0,0,1);
        }
    glPopMatrix();
    
}