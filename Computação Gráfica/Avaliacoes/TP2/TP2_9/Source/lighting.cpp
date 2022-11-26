#include "../Header/lighting.h"
#include "../Header/globalParameters.h"
#include <iostream>

long font = (long)GLUT_BITMAP_8_BY_13;

Lighting::Lighting(int alteravel, double d, double m, double e, GLenum glLightConst)
{
    this->d = d;
    this->m = m;
    this->e = e;
    this->glLightConst = glLightConst;
    
    lightLigada = 1;

    if(alteravel)
    {
        for(int i=0; i<3 ; i++)
        {
            lightAmb[i] = 0;
            lightDif[i] = d;
            lightSpec[i] = e;
            lightPos[i] = 0;
            globAmb[i] = m;
            matAmbAndDif[i] = 1;
            matSpec[i] = 1;
        }

        lightAmb[3] = 1;
        lightDif[3] = 1;
        lightSpec[3] = 1;
        lightPos[3] = 1;
        globAmb[3] = 1;
        matAmbAndDif[3] = 1;
        matSpec[3] = 1;
    }

    glEnable(glLightConst);
}

void Lighting::configuraMateriais()
{
    glEnable(GL_COLOR_MATERIAL);

    // Definindo as propriedades do material
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialf(GL_FRONT, GL_SHININESS, 0);
    //glMaterialf(GL_FRONT, GL_EMISSION, 128);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

// Escreve uma cadeia de caracteres
void escreveTextoNaTela(void *font, char *string)
{
    char *c;
    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Converte um número decimal em string
void floatParaString(char * destStr, int precision, float val)
{
    sprintf(destStr,"%f",val);
    destStr[precision] = '\0';
}

void Lighting::atualizaPropriedadesLuz()
{
    if(0 < m) m += -keys->x * 0.05;
    if(m < 1) m +=  keys->z * 0.05;

    if(0 < d) d += -keys->v * 0.05;
    if(d < 1) d +=  keys->c * 0.05;

    if(0 < e) e += -keys->n * 0.05;
    if(e < 1) e +=  keys->b * 0.05;

    for(int i=0; i<3; i++) {
        lightDif[i] = d;
        lightSpec[i] = e;
        globAmb[i] = m;
    }

    /* Propriedades da fonte de luz LIGHT0 */
    glLightfv(glLightConst, GL_AMBIENT, lightAmb); // rgb da luz ambiente
    glLightfv(glLightConst, GL_DIFFUSE, lightDif);
    glLightfv(glLightConst, GL_SPECULAR, lightSpec);    
    glLightfv(glLightConst, GL_POSITION, lightPos);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);        // Luz ambiente global
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, false);// Enable local viewpoint

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128);// teria que variarcmom pressionamento de tela

    if(buttons[0] && keys->l)
    {
        if(lightLigada) lightLigada = 0;
        else            lightLigada = 1;

        buttons[0] = 0;
/*
        if(lightLigada)
            glEnable(GL_LIGHT0);
        else 
            glDisable(GL_LIGHT0);
        */
    }

}