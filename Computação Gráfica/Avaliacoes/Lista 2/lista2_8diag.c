#include <GL/freeglut.h>
#include <stdio.h>

float aspectRatio = 1;
GLuint aviaoDisplayList, aviaoDisplayList1, aviaoDisplayList2;

// Vetor que idntifica se as teclass 'w | s | d | a' ou as
// setas 'cima | baixo | direita | esquerda' estão ligadas
GLboolean on_off[4] = {0,0,0,0};

float move_x = 1, move_y = 1;
double posi_x = 0, posi_y = 0;

static void aviao2(void){
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

static void aviao1(void){
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

static void aviao(void)
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
    aviaoDisplayList = glGenLists(1);
    aviaoDisplayList1 = glGenLists(2);
    aviaoDisplayList2 = glGenLists(3);

    glNewList(aviaoDisplayList, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList"
        aviao();
    glEndList();

    glNewList(aviaoDisplayList1, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList1"
        aviao1();
    glEndList();

    glNewList(aviaoDisplayList2, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList2"
        aviao2();
    glEndList();

    glClearColor(0.60, 0.847, 0.93, 6); // preparo para a lista ser executada
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //desenha avião principal e translada de acordo com as teclas pressionadas
    glPushMatrix();
        glTranslatef(posi_x , posi_y, 0);
        glCallList(aviaoDisplayList); // executa a lista
    glPopMatrix();

    //desenha aviao1 no canto superior direito da tela
    glPushMatrix();
        glTranslatef(40 * aspectRatio, 60, 0);
        glCallList(aviaoDisplayList1); // executa a lista
    glPopMatrix();

    //desenha aviao2 no canto inferior esquerdo da tela
    glPushMatrix();
        glTranslatef(-70 * aspectRatio,-65, 0);
        glCallList(aviaoDisplayList2); // executa a lista
    glPopMatrix();

    //coloca esses desenhos na tela
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
    /*Dependendo da tecla pressionada, um vetor sinaliza
    0 mostrando que uma tecla foi desligada, ou
    1 mostrando que uma tecla foi ligada*/
    switch (key){
        case 27: 
            exit(0); 
            break;
            
        case 'w': 
            if(on_off[0] == 1)
                on_off[0] = 0;
            else on_off[0] = 1;
            break;

        case 's': 
            if(on_off[1] == 1)
                on_off[1] = 0;
            else on_off[1] = 1;
            break;

        case 'd':
            if(on_off[2] == 1)
                on_off[2] = 0;
            else on_off[2] = 1;
            break;

        case  'a': // a
            if(on_off[3] == 1)
                on_off[3] = 0;
            else on_off[3] = 1;
            break;
    }
}

void setas(int key, int x, int y)
{
    switch (key){
        case 27: 
            exit(0); 
            break;
            
        case GLUT_KEY_UP: 
            if(on_off[0] == 1)
                on_off[0] = 0;
            else on_off[0] = 1;
            break;

        case GLUT_KEY_DOWN: 
            if(on_off[1] == 1)
                on_off[1] = 0;
            else on_off[1] = 1;
            break;

        case GLUT_KEY_RIGHT:
            if(on_off[2] == 1)
                on_off[2] = 0;
            else on_off[2] = 1;
            break;

        case  GLUT_KEY_LEFT: // a
            if(on_off[3] == 1)
                on_off[3] = 0;
            else on_off[3] = 1;
            break;
    }
}

void timer(int t)
{
    //aumenta ou diminui a posição do avião dependendo das teclas pressionadas
    posi_x += (on_off[2] - on_off[3]) * move_x;
    posi_y += (on_off[0] - on_off[1]) * move_y;

    //garante que avião não escape da caixa de visão
    if(posi_y > 75)
        posi_y = 75;

    if(posi_y < -70)
        posi_y = -70;

    if(posi_x > 100 * aspectRatio - 20)
        posi_x = 100 * aspectRatio - 20;
    
    if(posi_x < -100 * aspectRatio + 20)
        posi_x = -100 * aspectRatio + 20;

    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

int main(int argc, char **argv)
{
    //prepara a tela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lista 2");

    //inicializa as displaylists usadas para desenho
    inicializar();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);
    glutSpecialFunc(setas);
    glutSpecialUpFunc(setas);
    glutTimerFunc(33, timer, 33);

    glutMainLoop();
    return 0;
}