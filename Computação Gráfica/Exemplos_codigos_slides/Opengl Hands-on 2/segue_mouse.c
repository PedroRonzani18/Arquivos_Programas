#include <GL/freeglut.h>

struct ponto {
    float x, y;
};

struct tamanho {
    float largura, altura;
};

struct ponto posicaoQuadrado;
struct tamanho tamanhoQuadrado;

struct ponto posicaoMouse;

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0.5f); /// polígono rosa
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(posicaoQuadrado.x, posicaoQuadrado.y, 0);
        glVertex3f(posicaoQuadrado.x + tamanhoQuadrado.largura, posicaoQuadrado.y, 0);
        glVertex3f(posicaoQuadrado.x + tamanhoQuadrado.largura, posicaoQuadrado.y + tamanhoQuadrado.altura, 0);
        glVertex3f(posicaoQuadrado.x, posicaoQuadrado.y + tamanhoQuadrado.altura, 0);
    glEnd();
    glutSwapBuffers();
}

void inicializa() { // Inicia algumas variáveis de estado
    glClearColor(1, 1, 1, 1);      // limpa tela para branco
    // define o quadrado
    posicaoQuadrado.x = 0;
    posicaoQuadrado.y = 0;
    tamanhoQuadrado.largura = 50;
    tamanhoQuadrado.altura = 50;
}

// Callback de redimensionamento
void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // repare que o sistema de coordenadas do mundo foi configurado para
    // ser bem parecido com o sistema da janela: 0 a w, 0 a h, começando
    // do canto esquerdo-superior
    glOrtho(0, w, h, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void teclado(unsigned char key, int x, int y) {
   switch(key) {
      case 27: exit(0); break;
      default: break;
   }
}

// Callback de evento de movimento do mouse
void movimentoMouse(int x, int y) {
    posicaoMouse.x = x;
    posicaoMouse.y = y;
}

// Callback do evento timer
void atualizaCena(int periodo) {
    // faz o quadrado andar na direção do ponteiro
    posicaoQuadrado.x += (posicaoMouse.x - posicaoQuadrado.x)/50.0f; //vetor que liga quadrado e mouse
    posicaoQuadrado.y += (posicaoMouse.y - posicaoQuadrado.y)/50.0f;

    glutPostRedisplay(); // Pede ao GLUT para redesenhar a tela, assim que possível
    glutTimerFunc(periodo, atualizaCena, periodo); //deixa em 30 fps registrando novamente
}

int main(int argc, char **argv) {
    // Configuração inicial da janela do GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Segue Mouse com Atraso");
    inicializa();

    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutPassiveMotionFunc(movimentoMouse); // Registra a função "movimentoMouse" para executar sempre que o mouse mexer
    glutTimerFunc(0, atualizaCena, 33); // Registra a função "atualiza" para executar daqui a 0 milissegundos

    glutMainLoop();
    return 0;
}