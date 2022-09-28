#include <GL/freeglut.h>
#include <stdio.h>

float aspectRatio = 1;
GLuint thePlane;
int keys[256];

float move_x = 1, move_y = 1;
double posi_x = 0, posi_y = 0;

static void plane2(void){
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);
        //cabeça
        glVertex2f(-20, -10);
        glVertex2f(-15,  0);
        glVertex2f(-10, -5);
        //corpo baixo
        glVertex2f(-10, -5);
        glVertex2f( 15, 20);
        glVertex2f(7.5,22.5);
        //corpo cima
        glVertex2f(-10, -5);
        glVertex2f(7.5,22.5);
        glVertex2f(-15,  0);
        //asa esquerda - esq
        glVertex2f(-5, 5);
        glVertex2f(-14.3,12.5);
        glVertex2f(-10, 17);
        //asa esquerda - dir
        glVertex2f(-5, 5);
        glVertex2f(0,15);
        glVertex2f(-10, 17);
        //asa direita - cima
        glVertex2f(10,15);
        glVertex2f(20,13);
        glVertex2f(2.5,7.5);
        //asa direita - baixo
        glVertex2f(17.5,10);
        glVertex2f(20,13);
        glVertex2f(2.5,7.5);
        //calda direita - baixo
        glVertex2f(12.5,17.5);
        glVertex2f(15,20);
        glVertex2f(20,17.5);
        //calda direita - cima
        glVertex2f(22.5,20);
        glVertex2f(15,20);
        glVertex2f(20,17.5);
        //calda esquerda - baixo
        glVertex2f(7.5,22.5);
        glVertex2f(5,20);
        glVertex2f(2.5,27.5);
        //calda esquerda - alto
        glVertex2f(0,25);
        glVertex2f(5,20);
        glVertex2f(2.5,27.5);
    glEnd();

    glColor3f(0,0,1);

    glBegin(GL_TRIANGLES);
        //cabine cima
        glVertex2f(-10, 0);
        glVertex2f(-5,14);
        glVertex2f( 0, 12.5);
        //cabine baixo
        glVertex2f(-10, 0);
        glVertex2f(-5,14);
        glVertex2f(-9,7.5);
    glEnd();
}

static void plane1(void){
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLES);
        //corpo baixo
        glVertex2f(-30, -5);
        glVertex2f(-20,  0);
        glVertex2f( 35, 10);
        //corpo meio
        glVertex2f(-20,  0);
        glVertex2f(-15,  5);
        glVertex2f( 35, 10);
        //corpo cima
        glVertex2f(-15,  5);
        glVertex2f( 35, 10);
        glVertex2f( 25, 15);
        //calda meio
        glVertex2f(-20,  0);
        glVertex2f(-15,  5);
        glVertex2f(-30, 15);
        //calda cima
        glVertex2f(-30, 15);
        glVertex2f(-25,17.5);
        glVertex2f(-15, 5);
        //asa cima-meio
        glVertex2f( 12, 11.5);
        glVertex2f( -5, 15);
        glVertex2f(  0, 8);
        //asa cima-cima
        glVertex2f(-10,12.5);
        glVertex2f( -5, 15);
        glVertex2f(  0, 8);
        //asa baixo esquerda
        glVertex2f(  0,  5);
        glVertex2f( -5,-11.5);
        glVertex2f( -10,-9);
        //asa baixo direita
        glVertex2f(  -5, -11.5);
        glVertex2f( 0, 5);
        glVertex2f( 15, 7.5);
    glEnd();

    glColor3f(0, 0, 1);
    //janela
    glBegin(GL_TRIANGLES);
        glVertex2f( 25, 15);
        glVertex2f( 30,12.5);
        glVertex2f( 18, 13.2);
    glEnd();

    glColor3f(0,0,0); //desenhar linhas pretas

    glBegin(GL_LINE_STRIP); 
        //asa baixo 
        glVertex2f( 0, 5);
        glVertex2f(-10,-9);
        glVertex2f( -5,-11.5);
        glVertex2f(15, 7.5);
    glEnd();
    glBegin(GL_LINE_STRIP); 
        //asa cima
        glVertex2f( 25, 15);
        glVertex2f( 30,12.5);
        glVertex2f( 18, 13.2);
    glEnd();
}

static void plane(void)
{
    glColor3f(0.5, 0.5, 0.5); //cinza
    
    glBegin(GL_TRIANGLES);
        // ponta
        glVertex3f(0, 25, 0);
        glVertex3f(-5, 15, 0);
        glVertex3f(5, 15, 0);
        // tronco
        glVertex3f( -5, 15,  0);
        glVertex3f(  5, 15,  0);
        glVertex3f( -5, -20, 0);
        glVertex3f(  5, 15,  0);
        glVertex3f( -5, -20, 0);
        glVertex3f(  5, -20, 0);
        // caldae
        glVertex3f( -5, -20, 0);
        glVertex3f(-15, -30, 0);
        glVertex3f( -5, -15, 0);
        // caldad
        glVertex3f(  5,-20, 0);
        glVertex3f( 15,-30, 0);
        glVertex3f(  5,-15, 0);
        // asa_d
        glVertex3f(  5,  5, 0);
        glVertex3f(  5,  0, 0);
        glVertex3f( 20,-10, 0);
        // asa_e
        glVertex3f( -5,  0, 0);
        glVertex3f(-20,-10, 0);
        glVertex3f( -5,  5, 0);
    glEnd();

    glColor3f(0, 0, 1); // azul

    glBegin(GL_TRIANGLES);
        //asa_d
        glVertex3f(  5,  0, 0);
        glVertex3f( 20,-10, 0);
        glVertex3f(  5, -5, 0);
        //asa_e
        glVertex3f( -5,  0, 0);
        glVertex3f(-20,-10, 0);
        glVertex3f( -5, -5, 0);
        //calda_d
        glVertex3f(  0,-20, 0);
        glVertex3f( 15,-30, 0);
        glVertex3f(  0,-15, 0);
        //calda_e
        glVertex3f(  0,-20, 0);
        glVertex3f(-15,-30, 0);
        glVertex3f(  0,-15, 0);
    glEnd();
}

void inicializar(void) 
{
    thePlane = glGenLists(1);
    glNewList(thePlane, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "thePlane"
        plane();
    glEndList();
    glClearColor(0.60, 0.847, 0.93, 6); // preparo para a lista ser executada
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(posi_x, posi_y, 0);
        glCallList(thePlane); // executa a lista
    glPopMatrix();

    glPushMatrix();
        glTranslatef(40, 60, 0);
        plane1();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-70,-65, 0);
        plane2();
    glPopMatrix();

    if (keys['a'])
        posi_x -= move_x;
    if (keys['d'])
        posi_x += move_x;
    if (keys['s'])
        posi_y -= move_y;
    if (keys['w'])
        posi_y += move_y;

    glutSwapBuffers();

}

void reshape(int w, int h)
{
    aspectRatio = (float)w / (float)h;
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100 * aspectRatio, 100* aspectRatio, -100, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}                               

void keyboard(unsigned char key, int x, int y)
{
    switch (key){
        case 27: 
            exit(0); 
            break;
            
        case 'w': // w
            if(posi_y <= 75){
            keys['w'] = 1;
            glutPostRedisplay();
            }
            break;

        case 's': // s
            if(posi_y >= -70){
            keys['s'] = 1;
            glutPostRedisplay();
            }
            break;

        case 'd': // d
            if(posi_x <= 100 * aspectRatio - 20){
            keys['d'] = 1;
            glutPostRedisplay();
            }
            break;

        case  'a': // a
            if(posi_x >= -100 * aspectRatio + 20){
                keys['a'] = 1;
                glutPostRedisplay();
            }
            break;
    }
}

void keyboardUp(unsigned char key, int x, int y)
{
    keys[key] = 0;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lista 2");

    inicializar();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);

    glutMainLoop();
    return 0;
}