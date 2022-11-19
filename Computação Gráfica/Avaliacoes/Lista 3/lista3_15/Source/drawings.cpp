#include "../Header/globalParameters.h"
#include "../Header/Planet.h"

#include <stdio.h>
#include <SOIL/SOIL.h>

void drawSolidSphere(double radius, int stacks, int columns)
{
    GLUquadric* quadObj = gluNewQuadric(); // cira uma quadrica 
    gluQuadricDrawStyle(quadObj, GLU_FILL); // estilo preenchido
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    gluQuadricTexture(quadObj, GL_TRUE); // chama 01 glTexCoord por vértice
    gluSphere(quadObj, radius, stacks, columns); // cria os vértices de uma esfera
    gluDeleteQuadric(quadObj);
}

void drawCorpse(Planet* planet, double time)
{
    if(usarTextura){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, planet->getTexture());
    }
        glRotated(time * planet->getAngularSpeed(),0,0,1); // rotaciona no proprio eixo 
        glTranslated(-planet->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
        drawSolidSphere(planet->getCoreRadius(),slices,stacks);   

    if(usarTextura)
        glDisable(GL_TEXTURE_2D);
    
}

void drawCorpse(Moon* moon, double time)
{
    if(usarTextura){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, moon->getTexture());
    }
        glRotated(time * moon->getAngularSpeed() + moon->getAngle(),0,0,1); // rotaciona no proprio eixo 
        glTranslated(-moon->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
        drawSolidSphere(moon->getCoreRadius(),slices,stacks);   

    if(usarTextura)
        glDisable(GL_TEXTURE_2D);
    
}

void drawBackground(double z)
{
    glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, estrelas);
            glBegin(GL_TRIANGLE_FAN);

            double x = razaoAspecto * 10;
            double y = 14.5;

            glBegin(GL_TRIANGLE_FAN);
                glTexCoord2f(0,0); 
                glVertex3f (-x,-y,z);

                glTexCoord2f(1,0);
                glVertex3f (x,-y,z);

                glTexCoord2f(1,1);
                glVertex3f (x,y,z);

                glTexCoord2f(0,1);
                glVertex3f(-x,y,z);
            glEnd();
        glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
}

GLuint loadTexture(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(
        arquivo,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    if (idTextura == 0) {
        printf("Erro do SOIL: '%s' + %s\n", SOIL_last_result(),arquivo);
    }

    return idTextura;
}
