#include "../Header/lighting.h"
#include "../Header/globalParameters.h"
#include "../Header/Coord.h"

long font = (long)GLUT_BITMAP_8_BY_13;

void configuraMateriais()
{
    // Propriedades do material da esfera
    float matAmbAndDif[] = {1.0, 1.0, 1.0, 1.0};    // cor ambiente e difusa: branca (ambiente = cor | )
    float matSpec[] = { 1.0, 1.0, 1,0, 1.0};       // cor especular: branca
    //float matEmiss[] = { 1, 1, 1, 1};         // faz com que todos os materiais emitam luz

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

void informacoesIluminacao(float m, float d, float e,float s, Coord c)
{
    char theStringBuffer[10];        

    glDisable(GL_LIGHTING);

    glRasterPos3f(c.x-4.5, c.y + 1.6, c.z -2.3);
    escreveTextoNaTela((void*)font, (char*)"Luz ambiente global: ");
    
    glRasterPos3f(c.x-4.5, c.y + 1.4, c.z -2);
    escreveTextoNaTela((void*)font, (char*)"  - Intensidade (Z/X): ");
    floatParaString(theStringBuffer, 4, m);
    escreveTextoNaTela((void*)font, theStringBuffer);

    glRasterPos3f(c.x-5.55, c.y + 0.35, c.z -3.5);
    escreveTextoNaTela((void*)font, (char*)"Luz branca: ");

    glRasterPos3f(c.x-5.8, c.y, c.z -3.5);
    escreveTextoNaTela((void*)font, (char*)"  - Intensidade difusa (C/V): ");
    floatParaString(theStringBuffer, 4, d);
    escreveTextoNaTela((void*)font, theStringBuffer);

    glRasterPos3f(c.x-5.9, c.y-0.3, c.z -3.5);
    escreveTextoNaTela((void*)font, (char*)"  - Intensidade especular (B/N): ");
    floatParaString(theStringBuffer, 4, e);
    escreveTextoNaTela((void*)font, theStringBuffer);

    glRasterPos3f(c.x-6.3, c.y-1.3, c.z -4);
    escreveTextoNaTela((void*)font, (char*)"Material: ");

    glRasterPos3f(c.x-6.7, c.y-1.7, c.z -4);
    escreveTextoNaTela((void*)font, (char*)"  - Expoente shineness (W/A): ");
    floatParaString(theStringBuffer, 5, s);
    escreveTextoNaTela((void*)font, theStringBuffer);

    glEnable(GL_LIGHTING);

}

void atualizaCaracteristicaLuz()
{
    /* Propriedades da fonte de luz LIGHT0 */
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb); // rgb da luz ambiente
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif0);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec0);    
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);


    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);        // Luz ambiente global
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, localViewer);// Enable local viewpoint

    matShine = 128; // tem que variarcmom pressionamento de tela
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, matShine);

}

void onOffFonteLuz()
{
    /* Ativa fonte de luz branca */
        if(light0Ligada) 
            glEnable(GL_LIGHT0);
        else glDisable(GL_LIGHT0);
}

void atualizaPropriedadesLuz()
{
    if(0 < m) m += -keys[9] * 0.05;
    if(m < 1) m +=  keys[8] * 0.05;

    if(0 < d) d += -keys[11] * 0.05;
    if(d < 1) d +=  keys[10] * 0.05;

    if(0 < e) e += -keys[13] * 0.05;
    if(e < 1) e +=  keys[12] * 0.05;

    for(int i=0; i<3; i++)
        lightDif0[i] = d;

    for(int i=0; i<3; i++)
        lightSpec0[i] = e;

    for(int i=0; i<3; i++)
        globAmb[i] = m;
}