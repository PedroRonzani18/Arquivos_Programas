#include <GL/freeglut.h>  

void desenhaMinhaCena();
void redimensionada(int width, int height);
void teclaPressionada(unsigned char key, int x, int y);

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE); //perfil o mais compativel possivel

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("INCREMENTADO");

    glutReshapeFunc(redimensionada);  //redimencionar a janela da glut
    glutKeyboardFunc(teclaPressionada);

    glutDisplayFunc(desenhaMinhaCena);
    glutMainLoop();
    return 0;
}

void desenhaMinhaCena() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);

    glBegin(GL_POLYGON);//desenha uma forma
        glVertex3f(20, 20, 0);
        glVertex3f(80, 20, 0);
        glVertex3f(80, 80, 0);
        glVertex3f(20, 80, 0);
    glEnd();

    glBegin(GL_POLYGON);//desenha outra forma
        glVertex3f(0, 0, 0);
        glVertex3f(20, 0, 0);
        glVertex3f(20, 10, 0);
        glVertex3f(0, 20, 0);
    glEnd();

    glFlush();//coloca tudo dentro da janela
}

void redimensionada(int width, int height) {
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100, 100, -100, 100, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void teclaPressionada(unsigned char key, int x, int y) {
    switch(key) {
    case 27: exit(0); break;
    default: break;
    }
}
