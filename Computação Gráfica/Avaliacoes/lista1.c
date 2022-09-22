#include <GL/freeglut.h>
#include <stdio.h>

void desenhaCena() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void redimensiona(int w, int h) {
   glViewport(0, 0, w, h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 10, 0, 10, -1, 1);

   glMatrixMode(GL_MODELVIEW);

   //printf("Resolução: %d x %d\n",glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
   printf("Res: %d x %d\n",w,h);

   glLoadIdentity();
}

void teclado(unsigned char key, int x, int y) {
   switch(key) {
      case 27: exit(0); break;
      default: break;
   }
   printf("Tecla: %c pressionada em [%d,%d]\n",key,x,y);
}

void mouseClicar(int botao, int estado, int x, int y){
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
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Lista 1");

    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);

    glutPassiveMotionFunc(mouseSemPressionar); 
    glutMotionFunc(mousePressionado);
    glutMouseFunc(mouseClicar);

    glutMainLoop();
    return 0;
}