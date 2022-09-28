#include <GL/freeglut.h>
#include <stdio.h>

float aspectRatio = 1;
GLuint theAviao;

/*void aviao(int numc, int numt){

}*/

void inicializar(void){
    /*theAviao = glGenLists (1);
    glNewList(theAviao,GL_COMPILE);
    aviao(8,25);
    glEndList();
    
   glShadeModel(GL_FLAT);*/
    glClearColor(0, 0, 0, 0);
}

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);
        //ponta
        glVertex3f(0, 25, 0);
        glVertex3f(-5, 15, 0);
        glVertex3f(5 , 15, 0);
        //tronco
        glVertex3f(-5 , 15, 0);
        glVertex3f( 5, 15, 0);
        glVertex3f(-5, -20, 0);
        glVertex3f( 5, 15, 0);
        glVertex3f(-5, -20, 0);
        glVertex3f( 5, -20, 0);
        //caldae
        glVertex3f( 0,-20, 0);
        glVertex3f(-15,-30, 0);
        glVertex3f(-5,-15, 0);
        //caldad
        glVertex3f( 0,-20, 0);
        glVertex3f( 15,-30, 0);
        glVertex3f( 5,-15, 0);
        //asa_d
        glVertex3f( 5,  5, 0);
        glVertex3f( 5,  0, 0);
        glVertex3f(20,-10, 0);
        //asa_e
        glVertex3f( -5,  0, 0);
        glVertex3f(-20,-10, 0);
        glVertex3f( -5,  5, 0);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_TRIANGLES);
        glVertex3f(  5, 0, 0);
        glVertex3f(20,-10, 0);
        glVertex3f( 5, -5, 0);

        glVertex3f(-5, 0, 0);
        glVertex3f(-20, -10, 0);
        glVertex3f(-5, -5, 0);
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    aspectRatio = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100 * aspectRatio, 100 * aspectRatio, -100, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
   switch(key) {
        case 27: exit(0); break;
        case 119: 
        glutPostRedisplay();
        break;

        case 115: 
            glutPostRedisplay();
            break;

        case 97:
            glutPostRedisplay();
            break;

        case 100: 
            glutPostRedisplay();
            break;
   }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lista 2");

    inicializar();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}