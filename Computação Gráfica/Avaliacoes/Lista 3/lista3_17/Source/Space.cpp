#include "../Header/Space.h"
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"

void Space::drawAndMove(double time)
{
    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação
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

void Space::initializePlanets() // fazer engine que calcule essas velocidades em unidades glut a partir do raio, periodo e distância do planeta, e estatem influenciados por um alpha
{
    this->estrelas = Planet::createPlanetTemplate(texturesId[8],0,0,40,0,2,0);
    this->sol = Planet::createPlanetTemplate(texturesId[9],0,0,2,0,0,0);

    planetas.push_back(Planet::createPlanetTemplate(texturesId[0], 1, 0, 0.4, 2.5, 0, 30));
    planetas.push_back(Planet::createPlanetTemplate(texturesId[1], 1, 1, 0.4, 4.5, 0, 30));
    planetas.push_back(Planet::createPlanetTemplate(texturesId[2], 1, 1, 0.4, 6.5, 0, 30));
    planetas.push_back(Planet::createPlanetTemplate(texturesId[3], 1, 2, 0.4, 8.5, 0, 30));
    planetas.push_back(Planet::createPlanetTemplate(texturesId[4], 1, 3, 0.4, 10.5, 0, 30));
    planetas.push_back(Planet::createPlanetTemplate(texturesId[5], 1, 3, 0.4, 12.5, 0, 30));
    planetas.push_back(Planet::createPlanetTemplate(texturesId[6], 1, 3, 0.4, 14.5, 0, 30));    
    planetas.push_back(Planet::createPlanetTemplate(texturesId[7], 1, 3, 0.4, 16.5, 0, 30));
}