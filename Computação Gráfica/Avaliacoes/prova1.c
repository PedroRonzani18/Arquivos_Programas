#include <GL/freeglut.h>
#include <stdio.h>

struct ponto{
    int x,y;
};

struct ponto mouse;

void cena(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void redimensionar(int width, int height){
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100, 100, -100, 100, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void tecla(unsigned char key, int x, int y){
    switch(key) {
    case 27: exit(0); break;
    default: break;
    }
}

void posicao(int x, int y){
    mouse.x = x;
    mouse.y = y;
}

void atualizaCena(int periodo){
    glutPostRedisplay();
    glutTimerFunc(periodo, atualizaCena, periodo);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitContextVersion(1,1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE); 
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);

    glutCreateWindow("Tarefa1");

    glutDisplayFunc(cena);
    glutReshapeFunc(redimensionar);
    glutKeyboardFunc(tecla);
    glutPassiveMotionFunc(posicao);
    glutTimerFunc(0, atualizaCena, 33);

    glutMainLoop();
    return 0;
}