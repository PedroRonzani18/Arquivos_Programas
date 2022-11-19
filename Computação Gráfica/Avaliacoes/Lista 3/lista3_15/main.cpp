#include <GL/freeglut.h>
#include <stdio.h>
#include <SOIL/SOIL.h>
#include <SDL2/SDL_mixer.h>

#include "Header/drawings.h"
#include "Header/globalParameters.h"
#include "Header/Planet.h"
#include "Header/Space.h"
#include "Header/lighting.h"
#include "Header/Camera.h"

Space space;
Camera camera;

void configuraProjecao() 
{
    float razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-razaoAspecto, razaoAspecto, -1, 1, 2, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void enables()
{
    // Não mostrar faces do lado de dentro
    //glEnable(GL_CULL_FACE); 
    //glCullFace(GL_BACK);

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
    space.setEstrelas(Planet::createPlanetTemplate("imagens/space.jpg",0,40,0,2,0));
    space.setSol(Planet::createPlanetTemplate("imagens/2k_sun.jpg",0,1,0,0,0));

    Planet terra = Planet::createPlanetTemplate("imagens/2k_earth_daymap.jpg",1,0.4,1.8,20,30);
    terra.addMoon(Moon::createPlanetTemplate(0,0.15,0.6,20,50));
    terra.addMoon(Moon::createPlanetTemplate(120,0.15,0.6,20,50));
    terra.addMoon(Moon::createPlanetTemplate(240,0.15,0.6,20,50));
    space.addPlaneta(terra);

    space.addPlaneta(Planet::createPlanetTemplate("imagens/2k_mars.jpg",1,0.4,3,30,20));
}

void initialize()
{
    glClearColor(0,0,0,0);

    enables();
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
    camera.setupCamera();
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

    glFrustum(-razaoAspecto, razaoAspecto, -1, 1, 2, 100);

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

            case 'W':
                if(keys[0]) keys[0] = 0;
                else        keys[0] = 1;
                break;

            case 'A':
                if(keys[1]) keys[1] = 0;
                else        keys[1] = 1;
                break;

            case 'S':
                if(keys[2]) keys[2] = 0;
                else        keys[2] = 1;
                break;

            case 'D':
                if(keys[3]) keys[3] = 0;
                else        keys[3] = 1;
                break;

            case ' ':
                if(keys[4]) keys[4] = 0;
                else        keys[4] = 1;
                break;

            case 'C':
                if(keys[5]) keys[5] = 0;
                else        keys[5] = 1;
                break;

            case '+':
            case '=':
                if(keys[6]) keys[6] = 0;
                else        keys[6] = 1;
                break;

            case '-':
                if(keys[7]) keys[7] = 0;
                else        keys[7] = 1;
                break;




            case 'G':
                d++;
                break;

            case 'H':
                d--;
                break;

            case 'L':
                isLightingOn = !isLightingOn;
                break;

            case 'Q':
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
    camera.move();

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
    glutIgnoreKeyRepeat(1); 

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);
    glutTimerFunc(8, timer, 8);

    glutMainLoop();

    return 0;
}