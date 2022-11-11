#include "drawings.h"
#include "globalParameters.h"

#include<stdio.h>

void drawSolidSphere(double radius, int stacks, int columns)
{
    GLUquadric* quadObj = gluNewQuadric(); // cira uma quadrica 
    gluQuadricDrawStyle(quadObj, GLU_FILL); // estilo preenchido
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    gluQuadricTexture(quadObj, GL_TRUE); // chama 01 glTexCoord por vértice
    gluSphere(quadObj, radius, stacks, columns); // cria os vértices de uma esfera
    gluDeleteQuadric(quadObj);
}

void drawSun(double angle)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sol);

    glTranslated(0,0,-6);// coloca ele mais para tras na tela
    glRotated(-60,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação
    glRotated(angle,0,0,1); // rotaciona no proprio eixo 
    //glutSolidSphere(1,slices,stacks);
    drawSolidSphere(1,slices,stacks);
}

void drawEarth(double angle)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, terra);

    glRotated(angle,0,0,1); 
    glTranslated(-1.8,0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
    //glutSolidSphere(0.4,slices,stacks);
    drawSolidSphere(0.4,slices,stacks);
}

void drawMoon(double angle)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, lua);

    glRotated(angle*2,0,0,1);
    glTranslated(-0.6,0, 0); 
    //glutSolidSphere(0.17,slices,stacks);
    drawSolidSphere(0.15,slices,stacks);
}

void drawBackground(double z)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, estrelas);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);

    double x = razaoAspecto * 10;
    double y = 10;

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