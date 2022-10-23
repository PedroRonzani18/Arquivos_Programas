#include <SOIL/SOIL.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

GLuint idTexturaMario;
float cont=0.9;

GLuint carregaTextura(const char* arquivo) {
    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

void inicializa() {
    glClearColor(1, 1, 1, 1);

    // habilita mesclagem de cores, para termos suporte a texturas
    // com transparência
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaMario = carregaTextura("explosionSprites2.png");
}


void templateRetangulo(double x, double y, GLuint64 id)
{
    glClear(GL_COLOR_BUFFER_BIT);
        glColor3f (1, 1, 1);

        // Habilita o uso de texturas
        glEnable(GL_TEXTURE_2D);

        // Começa a usar a textura que criamos
        glBindTexture(GL_TEXTURE_2D, id);
        glBegin(GL_TRIANGLE_FAN);
            // Associamos um canto da textura para cada vértice
            // alterar texture coord para pegar parcialmente a textura
        /*
            glTexCoord2f(0, 0.9);
            glVertex3f(-1, -1,  0);

            glTexCoord2f(0.11, 0.9);
            glVertex3f( 1, -1,  0);

            glTexCoord2f(0.11, 1);
            glVertex3f( 1,  1,  0);

            glTexCoord2f(0, 1);
            glVertex3f(-1,  1,  0);
        */

            glTexCoord2f(0, cont);
            glVertex3f(-1, -1,  0);

            glTexCoord2f(0.11, cont);
            glVertex3f( 1, -1,  0);

            glTexCoord2f(0.11, cont + 0.1);
            glVertex3f( 1,  1,  0);

            glTexCoord2f(0, cont + 0.1);
            glVertex3f(-1,  1,  0);
        glEnd();
    glDisable(GL_TEXTURE_2D);
}

void desenha() {
    
    templateRetangulo(0.11,cont,idTexturaMario);
    printf("Cont: %f\n",cont);
    /*
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1, 1, 1);

    // Habilita o uso de texturas
    glEnable(GL_TEXTURE_2D);

    // Começa a usar a textura que criamos
    glBindTexture(GL_TEXTURE_2D, idTexturaMario);
    glBegin(GL_TRIANGLE_FAN);
        // Associamos um canto da textura para cada vértice
        glTexCoord2f(0.05, 0);
        glVertex3f(-1, -1,  0);

        glTexCoord2f(0.15, 0);
        glVertex3f( 1, -1,  0);

        glTexCoord2f(0.15, 1);
        glVertex3f( 1,  1,  0);

        glTexCoord2f(0.05, 1);
        glVertex3f(-1,  1,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    */

    glutSwapBuffers();
}

void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
    }
}

void timer(int t)
{
    cont -= 0.1;
    if(cont <= 0)
        cont = 0.9;
    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

void atualiza() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Carregando textura com SOIL");

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutDisplayFunc(desenha);
    //glutIdleFunc(atualiza);
    glutTimerFunc(400,timer,400);

    inicializa();

    glutMainLoop();

    return 0;
}