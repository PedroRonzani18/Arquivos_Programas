#include <GL/freeglut.h>
#include <stdio.h>
#include <SOIL/SOIL.h>
#include <SDL2/SDL_mixer.h>

#include "drawings.h"
#include "globalParameters.h"
#include "Planet.h"
#include "Space.h"

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

void desenha()
{
    configuraProjecao();

    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

    double a = t*10.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    space.drawAndMove(t);

    /*
    glPushMatrix();
        glTranslated(0,0,-10);
        //drawBackground(-10);
    glPopMatrix();
    */

   /*
    glPushMatrix();
        glTranslated(0,0,-6);// coloca ele mais para tras na tela
        glRotated(-60,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        //drawCorpse(sun,t);
        drawCorpse(&space.getPlaneta(0),t);

        glPushMatrix();

            drawCorpse(&space.getPlaneta(1),t);

            glPushMatrix();
                drawCorpse(&space.getPlaneta(2),t);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
    */

    /*
    glPushMatrix();

        drawSun(a);

        glPushMatrix();

            drawEarth(a);

            glPushMatrix();
                drawMoon(a);
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
    */

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

Planet createPlanetTemplate(GLuint texture, double coreRadius, double rotationRadius, double angularSpeed)
{
    Planet p;
    p.setTexture(texture);
    p.setCoreRadius(coreRadius);
    p.setRotationRadius(rotationRadius);
    p.setAngularSpeed(angularSpeed);
    return p;
}

void initPlanets()
{
    //Planet sun(sol,1,0,1);
    Planet sun = createPlanetTemplate(sol,1,0,10);
    space.addPlaneta(sun);

    Planet earth = createPlanetTemplate(terra,0.4,1.8,20);
    space.addPlaneta(earth);

    Planet moon = createPlanetTemplate(lua,0.15,0.6,50);
    space.addPlaneta(moon);
}

void init()
{
    glClearColor(1,1,1,1);

    enables();
    initializeTextures();

    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    music1 = Mix_LoadMUS("audio/background.mp3");

    initPlanets();
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