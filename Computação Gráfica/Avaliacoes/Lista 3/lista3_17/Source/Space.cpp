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
    this->estrelas = Planet::createPlanetTemplate(texturesId[8],0,40,0,2,0);
    this->sol = Planet::createPlanetTemplate(texturesId[9],0,2,0,0,0);

    Planet mercurio = Planet::createPlanetTemplate(texturesId[0], 1, 0.4, 2.5, 328.7, 30);

    Planet venus = Planet::createPlanetTemplate(texturesId[1], 1, 0.4, 4.5, 149.7, 30);

    Planet terra = Planet::createPlanetTemplate(texturesId[2], 1, 0.4, 6.5, 92.28, 30);
        terra.addMoon(Moon::createPlanetTemplate(0, 0.15, 0.6, 20, 50));

    Planet marte = Planet::createPlanetTemplate(texturesId[3], 1, 0.4, 8.5, 49.1, 30);
        marte.addMoon(Moon::createPlanetTemplate(0, 0.15, 0.6, 20, 50));
        marte.addMoon(Moon::createPlanetTemplate(180, 0.15, 0.6, 20, 50));

    Planet jupiter = Planet::createPlanetTemplate(texturesId[4], 1, 0.4, 10.5, 7.78, 30);
        jupiter.addMoon(Moon::createPlanetTemplate(0  , 0.15, 0.6, 20, 50));
        jupiter.addMoon(Moon::createPlanetTemplate(120, 0.15, 0.6, 20, 50));
        jupiter.addMoon(Moon::createPlanetTemplate(240, 0.15, 0.6, 20, 50));

    Planet saturno = Planet::createPlanetTemplate(texturesId[5], 1, 0.4, 12.5, 3.14 , 30);
        saturno.addMoon(Moon::createPlanetTemplate(0  , 0.15, 0.6, 20, 50));
        saturno.addMoon(Moon::createPlanetTemplate(120, 0.15, 0.6, 20, 50));
        saturno.addMoon(Moon::createPlanetTemplate(240, 0.15, 0.6, 20, 50));

    Planet urano = Planet::createPlanetTemplate(texturesId[6], 1, 0.4, 14.5, 1.1, 30);
        urano.addMoon(Moon::createPlanetTemplate(0  , 0.15, 0.6, 20, 50));
        urano.addMoon(Moon::createPlanetTemplate(120, 0.15, 0.6, 20, 50));
        urano.addMoon(Moon::createPlanetTemplate(240, 0.15, 0.6, 20, 50));
    
    Planet netuno = Planet::createPlanetTemplate(texturesId[7], 1, 0.4, 16.5, 0.56, 30);
        netuno.addMoon(Moon::createPlanetTemplate(0  , 0.15, 0.6, 20, 50));
        netuno.addMoon(Moon::createPlanetTemplate(120, 0.15, 0.6, 20, 50));
        netuno.addMoon(Moon::createPlanetTemplate(240, 0.15, 0.6, 20, 50));

    planetas.push_back(mercurio);
    planetas.push_back(venus);
    planetas.push_back(terra);
    planetas.push_back(marte);
    planetas.push_back(jupiter);
    planetas.push_back(saturno);
    planetas.push_back(urano);
    planetas.push_back(netuno);
}