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
#include "Header/MusicManager.h"
#include "Header/Keyboard.h"

Space space;
Camera camera;
MusicManager musicManager;

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

void initialize()
{
    glClearColor(0,0,0,0);

    enables();
    configuraMateriais();
    glShadeModel(GL_PHONG_HINT_WIN);
    createTextures();
    musicManager.configureMusic();
    space.initializePlanets();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    configuraProjecao();
    atualizaPropriedadesLuz();
    camera.setupCamera();
    atualizaCaracteristicaLuz();
    space.drawAndMove(tempo);
    informacoesIluminacao(m,d,e,s,camera.getCoordinates());

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);

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
                    Mix_PlayMusic(musicManager.getMusic(0),-1);
                /*se if(Mix_PausedMusic())
                    Mix_ResumeMusic();
                else
                    Mix_PauseMusic();*/
                break;

            case 'W':
                if(keys.w) keys.w = 0;
                else       keys.w = 1;
                break;

            case 'A':
                if(keys.a) keys.a = 0;
                else       keys.a = 1;
                break;

            case 'S':
                if(keys.s) keys.s = 0;
                else       keys.s = 1;
                break;

            case 'D':
                if(keys.d) keys.d = 0;
                else       keys.d = 1;
                break;

            case ' ':
                if(keys.space) keys.space = 0;
                else        keys.space = 1;
                break;

            case 'F':
                if(keys.f) keys.f = 0;
                else       keys.f = 1;
                break;

            case '+':
            case '=':
                if(keys.plus) keys.plus = 0;
                else          keys.plus = 1;
                break;

            case '-':
                if(keys.minus) keys.minus = 0;
                else           keys.minus = 1;
                break;

            case 'Z':
                if(keys.z) keys.z = 0;
                else       keys.z = 1;
                break;

            case 'X':
                if(keys.x) keys.x = 0;
                else       keys.x = 1;
                break;

            case 'C':
                if(keys.c) keys.c = 0;
                else       keys.c = 1;
                break;

            case 'V':
                if(keys.v) keys.v = 0;
                else       keys.v = 1;
                break;

            case 'B':
                if(keys.b) keys.b= 0;
                else       keys.b = 1;
                break;
                
            case 'N':
                if(keys.n) keys.n = 0;
                else       keys.n = 1;
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

void glutInitialize(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1384,752);
    glutInitWindowPosition(325,125);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Lista 3");

    glutIgnoreKeyRepeat(1); 

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);
    glutTimerFunc(8, timer, 8);
}

int main(int argc, char **argv)
{
    glutInitialize(argc, argv);
    initialize();
    glutMainLoop();

    return 0;
}