#include "../Header/Space.h"
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"
#include "../Header/lighting.h"
#include <memory>

void Space::drawAndMove(double time)
{
    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação
        drawCorpse(estrelas,time);
    glPopMatrix();

    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        glPushMatrix();
            drawCorpse(sol,time);
        glPopMatrix();

        for(std::shared_ptr<Planet> planet : planets)
        {
            glPushMatrix();
                drawCorpse(planet,time);
            glPopMatrix();

            for(std::shared_ptr<Moon> moon: planet->getMoons())
            {
                glPushMatrix();
                    glRotatef(time * planet->getTranslationAngularSpeed(),0,0,1); // rotaciona ao redor do planeta
                    glTranslated(-planet->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
                    drawCorpse(moon,time);
                glPopMatrix();
            }
        }
    glPopMatrix();
}

void Space::initializePlanets() // fazer engine que calcule essas velocidades em unidades glut a partir do raio, periodo e distância do planeta, e estatem influenciados por um alpha
{

    estrelas = std::make_shared<Planet>(texturesId[8],0,0,40,0,1500,0);
    sol = std::make_shared<Planet>(texturesId[9],0,0,2,0,0,0);

    planets.push_back(std::make_shared<Planet>(texturesId[0], 1, 0, 0.4, 2.5, 88, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[1], 1, 0, 0.4, 4.5, 225, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[2], 1, 1, 0.4, 6.5, 365, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[3], 1, 2, 0.4, 8.5, 686, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[4], 1, 3, 0.4, 10.5, 4328, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[5], 1, 3, 0.4, 12.5, 10752, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[6], 1, 3, 0.4, 14.5, 30663, 30));    
    planets.push_back(std::make_shared<Planet>(texturesId[7], 1, 3, 0.4, 16.5, 601480000, 30));
    
}