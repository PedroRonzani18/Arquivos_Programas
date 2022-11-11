#include <GL/freeglut.h>
#include <stdio.h>
#include <SOIL/SOIL.h>
#include <SDL2/SDL_mixer.h>

#include "drawings.h"
#include "globalParameters.h"

void configuraProjecao() // determina se é p ou o e muda para ortho ou frustrum
{
    float razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-razaoAspecto, razaoAspecto, -1.0, 1.0, 2, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void desenha()
{
    configuraProjecao();

    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

    double a = t*10.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslated(0,0,-10);
        //drawBackground(-10);
    glPopMatrix();

    glPushMatrix();

        drawSun(a);

        glPushMatrix();

            drawEarth(a);

            glPushMatrix();
                drawMoon(a);
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void timer(int t)
{
    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

void redimensiona(int width, int height)
{
    glViewport(0, 0, width, height);

    razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-razaoAspecto, razaoAspecto, -1.0, 1.0, 2, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :     // Tecla 'ESC
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;

        case 'l':
            angle+=2;
            break;


        case '1':
            if(!Mix_PlayingMusic())
                Mix_PlayMusic(music1,-1);
            else if(Mix_PausedMusic())
                Mix_ResumeMusic();
            else
                Mix_PauseMusic();

    }

    glutPostRedisplay();
}

void enables()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHT0); // "liga" a possivel fonte de luz 0
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
}

void initializeTextures()
{
    sol = loadTexture("imagens/2k_sun.jpg");
    terra = loadTexture("imagens/2k_earth_daymap.jpg");
    lua = loadTexture("imagens/2k_moon.jpg");
    estrelas = loadTexture("imagens/2k_stars_milky_way.jpg");
}

void init()
{
    glClearColor(1,1,1,1);

    enables();
    initializeTextures();

    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    music1 = Mix_LoadMUS("background.mp3");
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Lista 3");
    init();

    glutReshapeFunc(redimensiona);
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    glutTimerFunc(8, timer, 8);

    glutMainLoop();

    return EXIT_SUCCESS;
}