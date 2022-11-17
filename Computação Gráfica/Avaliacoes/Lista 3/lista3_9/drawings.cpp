#include "drawings.h"
#include "globalParameters.h"
#include "Planet.h"

#include <stdio.h>

void drawSolidSphere(double radius, int stacks, int columns)
{
    GLUquadric* quadObj = gluNewQuadric(); // cira uma quadrica 
    gluQuadricDrawStyle(quadObj, GLU_FILL); // estilo preenchido
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    gluQuadricTexture(quadObj, GL_TRUE); // chama 01 glTexCoord por vértice
    gluSphere(quadObj, radius, stacks, columns); // cria os vértices de uma esfera
    gluDeleteQuadric(quadObj);
}

void drawCorpse(Planet* p, double time)
{
    if(usarTextura){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, p->getTexture());
    }
        glRotated(time * p->getAngularSpeed(),0,0,1); // rotaciona no proprio eixo 
        glTranslated(-p->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
        drawSolidSphere(p->getCoreRadius(),slices,stacks);   

    if(usarTextura)
        glDisable(GL_TEXTURE_2D);
    
}

void drawBackground(double z)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, estrelas);
    glColor3f(1,1,1);
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