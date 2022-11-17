#include <GL/freeglut.h>
#include <stdio.h>
#include <SOIL/SOIL.h>
#include <SDL2/SDL_mixer.h>

#include "Header/drawings.h"
#include "Header/globalParameters.h"
#include "Header/Planet.h"
#include "Header/Space.h"
#include "Header/lighting.h"

Space space;

void configuraProjecao() // determina se é p ou o e muda para ortho ou frustrum
{
    float razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-razaoAspecto, razaoAspecto, -1.0, 1.0, 2, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void setupCamera()
{
    gluLookAt(0, 3, 5,
              0, 0, 0,
              0, 1, 0);
}

void enables()
{
    // Não mostrar faces do lado de dentro
    glEnable(GL_CULL_FACE); 
    glCullFace(GL_BACK);

    // Ativa teste Z
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);

    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHT0); // "liga" a possivel fonte de luz 0
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
}

void configureMusic()
{
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    music1 = Mix_LoadMUS("audio/background.mp3");
}

void initPlanets()
{
    Planet sun = Planet::createPlanetTemplate(sol,1,0,10);
    space.addPlaneta(sun);

    Planet earth = Planet::createPlanetTemplate(terra,0.4,1.8,20);
    space.addPlaneta(earth);

    Planet moon = Planet::createPlanetTemplate(lua,0.15,0.6,50);
    space.addPlaneta(moon);
}

void initialize()
{
    glClearColor(0,0,0,1);

    enables();
    configuraTextures();
    configuraMateriais();
    glShadeModel(GL_PHONG_HINT_WIN);
    configureMusic();
    initPlanets();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    configuraProjecao();
    atualizaPropriedadesLuz();
    onOffFonteLuz();
    setupCamera();
    atualizaCaracteristicaLuz();

    space.drawAndMove(tempo);

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    larguraJanela = width;
    alturaJanela = height;

    razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-razaoAspecto, razaoAspecto, -1.0, 1.0, 2, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    char formattedKey = (char) toupper(key);

    switch (formattedKey)
    {
        case 27 :     
            exit(0);
            break;

        case 'M':
            if(!Mix_PlayingMusic())
                Mix_PlayMusic(music1,-1);
            else if(Mix_PausedMusic())
                Mix_ResumeMusic();
            else
                Mix_PauseMusic();
            break;

        case 'D':
            d++;
            break;

        case 'F':
            d--;
            break;

        case 'L':
            isLightingOn = !isLightingOn;
            break;

        case 'W':
            if (light0Ligada) light0Ligada = false;
            else light0Ligada = true;
            break;

        case 'P':
            if (p) p = 0.0;
            else p = 1.0;
            break;

        case 'T':
            usarTextura = !usarTextura;
            break;
    }

    glutPostRedisplay();
}

void timer(int t)
{
    tempo = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Lista 3");

    initialize();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(8, timer, 8);

    glutMainLoop();

    return 0;
}