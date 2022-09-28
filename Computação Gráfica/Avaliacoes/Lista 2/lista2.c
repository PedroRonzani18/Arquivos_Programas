#include <GL/freeglut.h>
#include <stdio.h>

GLfloat xm = 0, ym = 0;
GLfloat speed = 5;
float aspectRatio = 1;

void desenhaCena() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);
        //ponta
        glVertex3f(0+xm, 25+ym, 0);
        glVertex3f(-5+xm, 15+ym, 0);
        glVertex3f(5+xm, 15+ym, 0);
        //tronco
        glVertex3f(-5+xm, 15+ym, 0);
        glVertex3f( 5+xm, 15+ym, 0);
        glVertex3f(-5+xm, -20+ym, 0);
        glVertex3f( 5+xm, 15+ym, 0);
        glVertex3f(-5+xm, -20+ym, 0);
        glVertex3f( 5+xm, -20+ym, 0);
        //caldae
        glVertex3f( 0+xm,-20+ym, 0);
        glVertex3f(-15+xm,-30+ym, 0);
        glVertex3f(-5+xm,-15+ym, 0);
        //caldad
        glVertex3f( 0+xm,-20+ym, 0);
        glVertex3f( 15+xm,-30+ym, 0);
        glVertex3f( 5+xm,-15+ym, 0);
        //asa_d
        glVertex3f( 5+xm,  5+ym, 0);
        glVertex3f( 5+xm,  0+ym, 0);
        glVertex3f(20+xm,-10+ym, 0);
        //asa_e
        glVertex3f( -5+xm,  0+ym, 0);
        glVertex3f(-20+xm,-10+ym, 0);
        glVertex3f( -5+xm,  5+ym, 0);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_TRIANGLES);
        glVertex3f(  5+xm, 0+ym, 0);
        glVertex3f(20+xm,-10+ym, 0);
        glVertex3f( 5+xm, -5+ym, 0);

        glVertex3f(-5+xm, 0+ym, 0);
        glVertex3f(-20+xm, -10+ym, 0);
        glVertex3f(-5+xm, -5+ym, 0);
    glEnd();

    glFlush();
}

void redimensionar(int w, int h) {
    aspectRatio = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100 * aspectRatio, 100 * aspectRatio, -100, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void teclaSair(unsigned char key, int x, int y) {
   switch(key) {
        case 27: exit(0); break;
        case 119: 
        ym+=speed;
        glutPostRedisplay();
        break;

        case 115: 
            ym-=speed;
            glutPostRedisplay();
            break;

        case 97:
            xm-=speed;
            glutPostRedisplay();
            break;

        case 100: 
            xm+=speed;
            glutPostRedisplay();
            break;
   }
}

/*void mouseClicar(int botao, int estado, int x, int y){
    switch(botao){
        case GLUT_LEFT_BUTTON: printf("Botao esquerdo "); break;
        case GLUT_RIGHT_BUTTON: printf ("Botao direito "); break;
        case GLUT_MIDDLE_BUTTON: printf("Scroll "); break;
    }
    if(estado == GLUT_DOWN)
        printf("pressionado em [%d,%d]\n",x,y);
    if(estado == GLUT_UP)
        printf("liberado em [%d,%d]\n",x,y);
}

void mouseSemPressionar(int x, int y) {
    printf("Posicao SEM Click: [%d,%d]\n",x,y);//posição do mouse sem estar clicando
}

void mousePressionado(int x, int y){
    printf("Posicao COM click: [%d,%d]\n",x,y);//posição do mouse clicando
}*/

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Lista 2");

    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensionar);
    glutKeyboardFunc(teclaSair);

    glutMainLoop();
    return 0;
}