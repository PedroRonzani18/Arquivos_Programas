#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Defs the animation time to 16ms or 60Hz
#define TICK_TIME 16

//#define DEBUG

typedef struct Triangle
{
    float x;
    float y;
    float angle;
    float lado;
    float normal[2];
} Triangle_t;

Triangle_t plane = {
    .x = 0,
    .y = 0,
    .angle = 0,
    .lado = 20,
    .normal[0] = 0,
    .normal[1] = 1};

float mouse_x = 0, mouse_y = 0, razaoAspecto = 0;

int key_status[4] = {0, 0, 0, 0};

GLuint m_list;

// Callback para redimensionamento
void reshapeFct(int width, int height)
{
    /*#ifdef DEBUG
        printf("Reshape Callback [%s] : Width [%d] | Height [%d] \n", __func__, width, height);
    #endif*/

    // Redimensiona o desenho do open_gl
    razaoAspecto = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100 * razaoAspecto, 100 * razaoAspecto, -100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Callback para pressionamento do teclado
void keyboardFct(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        if (key_status[0])
            key_status[0] = 0;
        else
            key_status[0] = 1;
        break;
    case 'a':
        if (key_status[1])
            key_status[1] = 0;
        else
            key_status[1] = 1;
        break;
    case 's':
        if (key_status[2])
            key_status[2] = 0;
        else
            key_status[2] = 1;
        break;
    case 'd':
        if (key_status[3])
            key_status[3] = 0;
        else
            key_status[3] = 1;
        break;
    case 0x27:
        exit(0);
        break;
    }
}

void timerFct(int time)
{
    // Verifica o movimento de acordo com as teclas
    float x_movement = key_status[0] - key_status[2];
    float y_movement = key_status[1] - key_status[3];
   /* plane.angle += y_movement * 5;

    printf("%f %f %f \n", x_movement, y_movement, plane.angle);

    if (plane.angle < 0)
        plane.angle = 360;
    else if (plane.angle > 360)
        plane.angle = 0;*/  

    /*plane.normal[0] = cos(plane.angle * M_PI / 180.0f);
    plane.normal[1] = sin(plane.angle * M_PI / 180.0f);
    printf("Normal = {%0.2f,%0.2f} \n", plane.normal[0], plane.normal[1]);*/

    if (x_movement)
    {
        // Movimenta a nave de acordo com a direção apontada
        plane.x += x_movement * plane.normal[0];
        plane.y += x_movement * plane.normal[1];
    }
    glutPostRedisplay();
    // Restarts the timer
    glutTimerFunc(time, timerFct, time);
}

void myInit()
{
    // Gera uma list para renderizar o quadrado
    m_list = glGenLists(1);
    glNewList(m_list, GL_COMPILE);
    glBegin(GL_TRIANGLES);
    glVertex2f(plane.lado / 2, 0);
    glVertex2f(-plane.lado / 2, plane.lado / 2);
    glVertex2f(-plane.lado / 2, -plane.lado / 2);
    glEnd();
    glEndList();

    // Ignora repetições de teclas e verifica apenas o pressionamento e qnd soltar
    glutIgnoreKeyRepeat(1);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 255, 255);

    glPushMatrix();
        glTranslatef(plane.x, plane.y, 0);
        glRotatef(plane.angle, 0, 0, 1);
        glCallList(m_list);
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    srand(time(0));

    // Configura a glut e a janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Questao 6");

    // Alloc a list of squares in the memory
    // sqr_objects = malloc(sizeof(Square_t) * 10);

    myInit();

    // Glut Callbacks
    glutDisplayFunc(Draw);
    glutReshapeFunc(reshapeFct);
    glutKeyboardFunc(keyboardFct);
    glutKeyboardUpFunc(keyboardFct);
    glutTimerFunc(33, timerFct, 33);

    glutMainLoop();

    // free(sqr_objects);
    return 0;
}