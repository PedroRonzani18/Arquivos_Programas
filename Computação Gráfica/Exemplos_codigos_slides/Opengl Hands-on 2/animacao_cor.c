#include <GL/freeglut.h>

float tomCinza = .3;
float incrementoNoTom = .01f;

void desenhaCena() {
    glClearColor(1, 1, 1, 1); //cor branca para limpar tela
    glClear(GL_COLOR_BUFFER_BIT);// Limpa tela (com a cor definida por glClearColor(r,g,b)) para desenhar
    glColor3f(tomCinza, tomCinza, tomCinza); // Começa a usar a cor amarela
    glBegin(GL_TRIANGLE_FAN);// Polígono com os vértices especificados
        glVertex3f(20, 20, 0);
        glVertex3f(80, 20, 0);
        glVertex3f(80, 80, 0);
        glVertex3f(20, 80, 0);
    glEnd();
    glutSwapBuffers();
}

void redimensiona(int w, int h) { // Callback de redimensionamento
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void teclado(unsigned char key, int x, int y) { // Callback de evento de teclado
    switch(key) {
        case 27: exit(0); break;
        default: break;
    }
}

void mudaCor(int periodo) {
    tomCinza += incrementoNoTom; // altera a cor do quadrado
    if (tomCinza > .8 || tomCinza < .3) {
        incrementoNoTom = -incrementoNoTom;
    }

    glutPostRedisplay(); // Pede ao GLUT para redesenhar a tela, assim que poss�vel
    glutTimerFunc(periodo, mudaCor, periodo); // Se registra novamente, para que fique sempre sendo chamada
}

int main(int argc, char **argv) {
    // Configuração inicial da janela do GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("50 tons de cinza");

    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    
    glutTimerFunc(0, mudaCor, 33);// Registra a função "mudaCor" para executar daqui a 0 ms
                                  // 33 = tempo de execução da troca de cor

    glutMainLoop();
    return 0;
}
