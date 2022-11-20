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

void initialize()
{
    glClearColor(0,0,0,0);

    enables();
    configuraMateriais();
    glShadeModel(GL_PHONG_HINT_WIN);
    configureMusic();
    createTextures();
    space.initializePlanets();
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

            case 'F':
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

            case 'Z':
                if(keys[8]) keys[8] = 0;
                else        keys[8] = 1;
                break;

            case 'X':
                if(keys[9]) keys[9] = 0;
                else        keys[9] = 1;
                break;

            case 'C':
                if(keys[10]) keys[10] = 0;
                else         keys[10] = 1;
                break;

            case 'V':
                if(keys[11]) keys[11] = 0;
                else         keys[11] = 1;
                break;

            case 'B':
                if(keys[12]) keys[12] = 0;
                else         keys[12] = 1;
                break;
                
            case 'N':
                if(keys[13]) keys[13] = 0;
                else         keys[13] = 1;
                break;

/*
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
*/
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