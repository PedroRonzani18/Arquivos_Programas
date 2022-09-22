#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>

float aspectRatio = 1;
double move_x = 1, move_y = 1;
int contador=2;

GLuint aviaoDisplayList, aviaoDisplayList1, aviaoDisplayList2;

// Vetor que idntifica se as teclass 'w | s | d | a' ou as
// setas 'cima | baixo | direita | esquerda' estão ligadas
GLboolean on_off[4] = {0,0,0,0};

typedef struct ENTIDADE{   
    double x_max, x_min;
    double y_max, y_min;
    double ponto_c_x, ponto_c_y;
    double raio;
    int lado;
    GLboolean onScreen;
}entidade;

entidade entityList[6];

//coloca structs dos desenhos dentro de um vetor
void listaStructs()
{
    entidade player ={
        .x_max = 20, .x_min = -20,
        .y_max = 25, .y_min = -30,
        .onScreen = GL_TRUE
    };

    player.ponto_c_x = (player.x_max + player.x_min)/2;
    player.ponto_c_y = (player.y_max + player.y_min)/2;

    entityList[0] = player;
    entityList[1] = player;

    entidade aviao1Struct = {
        .x_max = 35, .x_min = -30,
        .y_max = 17.5, .y_min = -11.5,
        .onScreen = GL_TRUE, .lado = -1
    };

    aviao1Struct.ponto_c_x = (aviao1Struct.x_max + aviao1Struct.x_min)/2;
    aviao1Struct.ponto_c_y = (aviao1Struct.y_max + aviao1Struct.y_min)/2;

    entityList[2] = aviao1Struct;
    entityList[3] = aviao1Struct;

    entidade aviao2Struct = {
        .x_max = 22, .x_min = -20,
        .y_max = 22.5, .y_min = -10,
        .onScreen = GL_TRUE, .lado = 1
    };

    aviao2Struct.ponto_c_x = (aviao2Struct.x_max + aviao2Struct.x_min)/2;
    aviao2Struct.ponto_c_y = (aviao2Struct.y_max + aviao2Struct.y_min)/2;

    entityList[4] = aviao2Struct;
    entityList[5] = aviao2Struct;
}

//desenha o aviao do jogador
void desenhaPlayer()
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

//desenha o 1 aviao extra
void desenhaAviao1(){
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

//desenha o 2 aviao extra
void desenhaAviao2(){
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

void inicializar() 
{
    listaStructs();

    aviaoDisplayList = glGenLists(1);
    aviaoDisplayList1 = glGenLists(2);
    aviaoDisplayList2 = glGenLists(3);

    glNewList(aviaoDisplayList, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList"
        desenhaPlayer();
    glEndList();

    glNewList(aviaoDisplayList1, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList1"
        desenhaAviao1();
    glEndList();

    glNewList(aviaoDisplayList2, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList2"
        desenhaAviao2();
    glEndList();

    glClearColor(0.60, 0.847, 0.93, 6); // preparo para a lista ser executada
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //desenha avião principal e translada de acordo com as teclas pressionadas
    glPushMatrix();
        glTranslatef(entityList[0].ponto_c_x , entityList[0].ponto_c_y, 0);
        glCallList(aviaoDisplayList); // executa a lista
    glPopMatrix();

    //desenha aviao1 no canto superior direito da tela
    /*if(contador== 1)
    {   
        glPushMatrix();
            glTranslatef(40 * aspectRatio, 70, 0);
            entityList[2].ponto_c_x += 40 * aspectRatio;
            entityList[2].ponto_c_y += 70;
            glCallList(aviaoDisplayList1); // executa a lista
        glPopMatrix();

            //desenha aviao2 no canto inferior esquerdo da tela
        glPushMatrix();
            glTranslatef(-70 * aspectRatio,-65, 0);
            entityList[4].ponto_c_x += -70 * aspectRatio;
            entityList[4].ponto_c_y += -65;
            glCallList(aviaoDisplayList2); // executa a lista
        glPopMatrix();

        contador++;
    }*/

    if(contador > 1)
    {
        glPushMatrix();
            glTranslatef(entityList[2].ponto_c_x, 70, 0);
            glCallList(aviaoDisplayList1); // executa a lista
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-70 * aspectRatio, entityList[4].ponto_c_y, 0);
            glCallList(aviaoDisplayList2); // executa a lista
        glPopMatrix();
    }

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

void movimentacaoJogador()
{
    //aumenta ou diminui a posição do jogador dependendo das teclas pressionadas
    entityList[0].ponto_c_x += (on_off[2] - on_off[3]) * move_x;
    entityList[0].ponto_c_y += (on_off[0] - on_off[1]) * move_y;
}

void movimentaAviao1_1()
{
    //movimenta o aviao1
    //printf("Pontox: %f | lado: %d | condi: %f\n",entityList[2].ponto_c_x -20 * aspectRatio,entityList[2].lado, -85 * aspectRatio);

    if(entityList[2].lado == -1)
        entityList[2].ponto_c_x -= 1;

    if(entityList[2].lado ==  1)
        entityList[2].ponto_c_x += 1;


    if(entityList[2].ponto_c_x < -100 * aspectRatio + 30)
    {
        entityList[2].lado = 1;
        entityList[2].ponto_c_x += 1;
    }

    if(entityList[2].ponto_c_x > 100 * aspectRatio - 35)
    {
        entityList[2].lado = -1;
        entityList[2].ponto_c_x -= 1;
    }
}

void movimentaAviao2_1(){

    //movimenta o aviao2
    //printf("Pontox: %f | lado: %d\n",entityList[4].ponto_c_y,entityList[4].lado);

    if(entityList[4].lado == -1)
        entityList[4].ponto_c_y -= 1;

    if(entityList[4].lado ==  1)
        entityList[4].ponto_c_y += 1;


    if(entityList[4].ponto_c_y < -91.25)
    {
        entityList[4].lado = 1;
        entityList[4].ponto_c_y += 1;
    }

    if(entityList[4].ponto_c_y > 72.5)
    {
        entityList[4].lado = -1;
        entityList[4].ponto_c_y -= 1;
    }

}

void dentroTela()
{
    //garante que avião não escape da caixa de visão
    if(entityList[0].ponto_c_y > 75)
        entityList[0].ponto_c_y = 75;

    if(entityList[0].ponto_c_y < -70)
        entityList[0].ponto_c_y = -70;

    if(entityList[0].ponto_c_x > 100 * aspectRatio - 20)
        entityList[0].ponto_c_x = 100 * aspectRatio - 20;
    
    if(entityList[0].ponto_c_x < -100 * aspectRatio + 20)
        entityList[0].ponto_c_x = -100 * aspectRatio + 20;
}

void maiorRaio()
{   
    for(int i=0; i<6; i++) 
        entityList[i].raio = sqrt(pow((entityList[i].x_max * aspectRatio - entityList[i].x_min),2 * aspectRatio) + pow((entityList[i].y_max - entityList[i].y_min),2))/2 ;
}

void timer(int t)
{
    //função que movimenta o jogador
    movimentacaoJogador();

    movimentaAviao1_1();

    movimentaAviao2_1();

    //função que garante que player fique na tela
    dentroTela();

    //função que calcula a todo momento o raio de colisão de cada objeto
    maiorRaio();

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
    glutTimerFunc(16, timer, 16);

    glutMainLoop();
    return 0;
}