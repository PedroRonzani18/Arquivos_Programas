#include "BaseClasses/Header/OrderedPair.h"
#include "BaseClasses/Header/Entity.h"
#include "BaseClasses/Header/MovableEntity.h"
#include "BaseClasses/Header/Enemy.h"
#include "BaseClasses/Header/Player.h"

#include "GeneralFiles/Header/globalParameters.h"
#include "GeneralFiles/Header/drawings.h"

#include "Stages/Header/StageManager.h"

#include <string>
#include <GL/freeglut.h>

using namespace std;

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

StageManager stageManager;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    stageManager.movements();

    glutSwapBuffers();
}

void redimensionada(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, -1, 1);

    float aspectRatio = ((float)width)/height;    
    float worldAspectRatio = ((float) right)/ top;
    
    if (aspectRatio < worldAspectRatio) 
    {
        float h = width / worldAspectRatio;

        float y = (height - h)/2;

        glViewport(0, y, width, h);
    }
    
    else if (aspectRatio > worldAspectRatio) {
        float w = ((float)height) * worldAspectRatio;
        float x = (width - w)/2;
        glViewport(x, 0, w, height);
    } else {
        glViewport(0, 0, width, height);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Callback do evento de pressionamento de tecla (sem ser setas)
void keyboard(unsigned char key, int x, int y)
{
    /*Dependendo da tecla pressionada, um vetor sinaliza
    0 mostrando que uma tecla foi desligada, ou
    1 mostrando que uma tecla foi ligada*/
    switch (key)
    {
        case 27: //ESC
            exit(0); 
            break;
            
        case 'w': //Anda para frente
        case 'W':
            keys[0] = !keys[0];
            
            auxKeys[0] = 1;
            break;

        case 's': //Anda para trás
        case 'S':
            keys[1] = !keys[1];
            auxKeys[1] = 1;
            break;

        case 'd': // Anda para direita
        case 'D':
            keys[2] = !keys[2];
            break;

        case 'a': // Anda para esquerda
        case 'A':
            keys[3] = !keys[3];
            break;

        case ' ': // Atira 
            keys[4] = !keys[4];
            auxKeys[2] = 1;
            break;
    }
}

void timer(int t)
{
    stageManager.keyboardOfStage();
    stageManager.colision();
    stageManager.callWave();
    stageManager.timer();

    tempo += 1;
    if(tempo > 2000000000)
    {
        tempo=0;
    }

    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(900, 1000);
    glutInitWindowPosition(540,0);
    glutCreateWindow("C.T.C.");

    // função de inicializção do jogo
    stageManager.gameInit();

    glutIgnoreKeyRepeat(1); 

    // Registra callbacks para alguns eventos
    glutDisplayFunc(display);
    glutReshapeFunc(redimensionada);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);    
    glutTimerFunc(frames, timer, frames);

    glutMainLoop();
    return 0;
}