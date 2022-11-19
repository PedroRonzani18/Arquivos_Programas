#include "../Header/lighting.h"
#include "../Header/globalParameters.h"

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
    for(int i=0; i<3; i++)
        lightDif0[i] = d;

    for(int i=0; i<3; i++)
        lightSpec0[i] = e;

    lightPos0[3] = p;
    lightPos0[2] = z;

    for(int i=0; i<3; i++)
        globAmb[i] = m;
}