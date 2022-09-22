#include <cmath>
#include <stdio.h>
#include <GL/freeglut.h>

float posX = 0.01, posY = -0.1, posZ = 0;

void circ() {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 300; i++) {
        angle = 2 * PI * i / 300;
        x = cos(angle) / 20;
        y = sin(angle) / 20;
        glVertex2d(x, y);
    }
    glEnd();
}


void display() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    circ();
    glPopMatrix();

    glutSwapBuffers();
}

**float move_unit = 0.02f;
void keyboardown(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        posX += move_unit;
        break;
    case GLUT_KEY_LEFT:
        posX -= move_unit;
        break;
    case GLUT_KEY_UP:
        posY += move_unit;
        break;
    case GLUT_KEY_DOWN:
        posY -= move_unit;
        break;
    default:
        break;
    }
glutPostRedisplay();
}**



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Example");
    glutDisplayFunc(display);
    glutSpecialFunc(keyboardown);
    glutMainLoop();
}