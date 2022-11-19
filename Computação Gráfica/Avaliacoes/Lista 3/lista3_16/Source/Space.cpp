#include "../Header/Space.h"
#include "../Header/drawings.h"

void Space::drawAndMove(double time)
{
    glPushMatrix();
        drawCorpse(&estrelas,time);
    glPopMatrix();

    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        glPushMatrix();
            drawCorpse(&sol,time);
        glPopMatrix();

        for(Planet planet: planetas)
        {
            glPushMatrix();
                drawCorpse(&planet,time);
            glPopMatrix();

            for(Moon moon: planet.getMoons())
            {
                glPushMatrix();
                    glRotatef(time * planet.getTranslationAngularSpeed(),0,0,1); // rotaciona ao redor do planeta
                    glTranslated(-planet.getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
                    drawCorpse(&moon,time);
                glPopMatrix();
            }
        }
    glPopMatrix();

}