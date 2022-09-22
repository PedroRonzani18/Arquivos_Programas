#include <GL/freeglut.h>
#include <string.h>

void escreveTexto(void * font, char *s, float x, float y, float z) {
    int i;
    glRasterPos3f(x, y, z);

    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(font, s[i]);
    }
}

void inicializa() {
    glClearColor(0, 0, 0, 0);
}

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    escreveTexto(GLUT_BITMAP_HELVETICA_18, "TEXTASSO", 20, 40, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10, "textinho", 20, 20, 0);

    glFlush();
}

void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, w, 0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(200, 100);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Fontes usando Freeglut");

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutDisplayFunc(desenha);

    inicializa();

    glutMainLoop();
    return 0;
}