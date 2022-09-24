//falta ent[1] mover, colisao gerar game over

#include <GL/freeglut.h>
#include <stdio.h>
#include <string.h>

// Vetor que idntifica se as teclass 'w | s | d | a' ou as
// setas 'cima | baixo | direita | esquerda' estão ligadas
GLboolean on_off[4] = {0,0,0,0};
GLint aviaoDisplayList, aviaoDisplayList1, aviaoDisplayList2;
GLfloat aspectRatio = 1;
GLint endGame = 0;

//struct que contém os dados do player e NPC 
typedef struct ENTIDADE{
    double x_max, x_min; // Valores maximos e minimos que x e y podem alcançar 
    double y_max, y_min; // baseados nas coordenadas extremas do desenho.
    double ponto_c_x, ponto_c_y; // Coordenadas do ponto central
    double x_move, y_move; // Unidade de movimento nos eixos x e y
    int ladoHorizontal, ladoVertical; // LH = 1: anda na horizontal 
                                      // LV = 1: anda na vertical
    GLboolean onScreen; // Objeto se econtra dentro da caixa de visualização ou não
    GLuint model; // ID da displayList de desenho 
}entidade;

// Lista das entidades
entidade entityList[6];

// Determina os parâmetros iniciais de cada entidade e as armazena dentro de um vetor
void listaStructs()
{
    entidade player ={
        .x_max = 20, .x_min = -20,
        .y_max = 25, .y_min = -30,
        .onScreen = GL_TRUE, 
        .model = aviaoDisplayList,
        .x_move = 1, .y_move = 1
    };

    entityList[0] = player;
    entityList[1] = player;

    entityList[1].ladoHorizontal = 1;
    entityList[1].ladoVertical = 1;
    entityList[1].x_move = 1;
    entityList[1].y_move = 0;

    entidade aviao1Struct = {
        .x_max = 35, .x_min = -30,
        .y_max = 17.5, .y_min = -11.5,
        .x_move = 1, .y_move = 1,
        .onScreen = GL_TRUE, 
        .ladoHorizontal = -1, .ladoVertical = 0,
        .model = aviaoDisplayList1
    };

    entityList[2] = aviao1Struct;
    entityList[3] = aviao1Struct;

    entidade aviao2Struct = {
        .x_max = 22, .x_min = -20,
        .y_max = 22.5, .y_min = -10,
        .x_move = 1, .y_move = 1,
        .onScreen = GL_TRUE, 
        .ladoVertical = 1, .ladoHorizontal = 0,
        .model = aviaoDisplayList2
    };

    entityList[4] = aviao2Struct;
    entityList[5] = aviao2Struct;
}

// Desenha o aviao do jogador
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

    glColor3f(1,0,0);

    glBegin(GL_LINE_STRIP);
        glVertex2f(20, 25);
        glVertex2f(-20, 25);
        glVertex2f(-20, -30);
        glVertex2f(20, -30);
        glVertex2f(20, 25);
    glEnd();
}

// Desenha o aviao1
void desenhaAviao1()
{
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

    glColor3f(1,0,0);

    glBegin(GL_LINE_STRIP);
        glVertex2f(35, 17.5);
        glVertex2f(-30, 17.5);
        glVertex2f(-30, -11.5);
        glVertex2f(35, -11.5);
        glVertex2f(35, 17.5);
    glEnd();
}

// Desenha o aviao2
void desenhaAviao2()
{
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

    glColor3f(1,0,0);

    glBegin(GL_LINE_STRIP);
        glVertex2f( 22, 27.5);
        glVertex2f( 22, -10);
        glVertex2f(-20, -10);
        glVertex2f(-20, 27.5);
        glVertex2f( 22, 27.5);
    glEnd();
}

// Cria displayLists de desenho de cada objeto
void inicializaDisplayLists()
{
    aviaoDisplayList = glGenLists(1);
    aviaoDisplayList1 = glGenLists(2);
    aviaoDisplayList2 = glGenLists(3);

    listaStructs();

    glNewList(aviaoDisplayList, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList"
        desenhaPlayer();
    glEndList();

    glNewList(aviaoDisplayList1, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList1"
        desenhaAviao1();
    glEndList();

    glNewList(aviaoDisplayList2, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList2"
        desenhaAviao2();
    glEndList();
}

// Define os valores das coordenadas centrais default de cada entidade
void inicializaPosicoes()
{
    for(int i=0; i<6; i++){
        entityList[i].ponto_c_x = (entityList[i].x_max + entityList[i].x_min)/2;
        entityList[i].ponto_c_y = (entityList[i].y_max + entityList[i].y_min)/2;
    }

    //aviao princilap NPC
    entityList[1].ponto_c_x +=  0;
    entityList[1].ponto_c_y += -60;

    //aviao1_1
    entityList[2].ponto_c_x += 60;
    entityList[2].ponto_c_y += 80;

    //aviao1_2
    entityList[3].ponto_c_x += -60;
    entityList[3].ponto_c_y += -80; 

    //aviao2_1
    entityList[4].ponto_c_x += -70;
    entityList[4].ponto_c_y += 65;

    //aviao2_2
    entityList[5].ponto_c_x += 70;
    entityList[5].ponto_c_y += -65;
}

// Inicialização geral de parâmetros
void inicializar()
{
    // Cria as displaylists de desenho
    inicializaDisplayLists();

    // Coloca os aviões em suas posições iniciais
    inicializaPosicoes();

    // Define a cor do fundo como 'ciano'
    glClearColor(0.60, 0.847, 0.93, 6); 
}

// Eescreve texto "Game Over" na tela
void escreveTexto(void * font, char *s, float x, float y)
{
    glPushMatrix();
        glLoadIdentity();
        glRasterPos2d(x-20,y);

        for (int i = 0; i < strlen(s); i++) 
            glutBitmapCharacter(font, s[i]);
    glPopMatrix();
}

// Detecta colisões
int colisaoGeral(int e1, int e2)
{
    // Se não ocorre colisão, retorna 0
    if(entityList[e1].x_max + entityList[e1].ponto_c_x <= entityList[e2].x_min + entityList[e2].ponto_c_x) return 0;
    if(entityList[e1].x_min + entityList[e1].ponto_c_x >= entityList[e2].x_max + entityList[e2].ponto_c_x) return 0;
    if(entityList[e1].y_max + entityList[e1].ponto_c_y <= entityList[e2].y_min + entityList[e2].ponto_c_y) return 0;
    if(entityList[e1].y_min + entityList[e1].ponto_c_y >= entityList[e2].y_max + entityList[e2].ponto_c_y) return 0;

    // Se ocorre colisão, retorna 1
    return 1;
}

// Callback da displayFunction
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Endgame = 1 significa que ocorreu colisão
    if(endGame)
    {
        glColor3f(0,0,0);
        escreveTexto(GLUT_BITMAP_HELVETICA_18, "Game Over", 0, 0);
    }

    // Se não tiver acabado o programa, executa normalmente
    else
    {
        // Desenha todas as imagens
        for(int i=0; i<6; i++){
            if(entityList[i].onScreen)
            {   
                glPushMatrix();
                    glTranslatef(entityList[i].ponto_c_x, entityList[i].ponto_c_y, 0);
                    glCallList(entityList[i].model);
                glPopMatrix();
            }
        }
    }

    //coloca esses desenhos na tela
    glutSwapBuffers();
}

// Callback da reshapeFunction
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

// Callback do evento de pressionamento de tecla (sem ser setas)
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

// Callback do evento de pressionamento de tecla (setas)
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

// Altera o valor do ponto central do aviao do jogador
void movimentacaoJogador()
{
    // Aumenta ou diminui a posição do jogador dependendo das teclas pressionadas
    entityList[0].ponto_c_x += (on_off[2] - on_off[3]) * entityList[0].x_move;
    entityList[0].ponto_c_y += (on_off[0] - on_off[1]) * entityList[0].y_move;
}

// Altera o valor do ponto central dos NPCS
void movimentaNPC(int e)
{
    // Se o NPC andar na horizontal, executa os comandos
    if(entityList[e].ladoHorizontal != 0) 
    {
        // Se a entidade estiver programada para andar para a esquerda, diminui o valor X do ponto central
        if(entityList[e].ladoHorizontal == -1)
            entityList[e].ponto_c_x -= entityList[e].x_move;

        // Se a entidade estiver programada para andar para a direita, aumenta o valor X do ponto central
        if(entityList[e].ladoHorizontal ==  1)
            entityList[e].ponto_c_x += entityList[e].x_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite esquero da caixa de visualização,
        // programa a entidade para andar para a direita. 
        if(entityList[e].ponto_c_x < -100 * aspectRatio - entityList[e].x_min)
        {
            entityList[e].ladoHorizontal = 1;
            entityList[e].ponto_c_x += entityList[e].x_move;
        }

        // Se o extremo direito da entidade ultrapassar o limite direito da caixa de visualização,
        // programa a entidade para andar para a esquerda. 
        if(entityList[e].ponto_c_x > 100 * aspectRatio - entityList[e].x_max)
        {
            entityList[e].ladoHorizontal = -1;
            entityList[e].ponto_c_x -= entityList[e].x_move;
        }
    }

    // Se o NPC andar na vetical, executa os comandos
    if(entityList[e].ladoVertical != 0)
    {
        // Se a entidade estiver programada para andar para baixo, diminui o valor Y do ponto central.
        if(entityList[e].ladoVertical == -1)
            entityList[e].ponto_c_y -= entityList[e].y_move;

        // Se a entidade estiver programada para andar para cima, aumenta o valor Y do ponto central.
        if(entityList[e].ladoVertical ==  1)
            entityList[e].ponto_c_y += entityList[e].y_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite inferior da caixa de visualização,
        // programa a entidade para andar para cima. 
        if(entityList[e].ponto_c_y < -100 - entityList[e].y_min)
        {
            entityList[e].ladoVertical = 1;
            entityList[e].ponto_c_y += entityList[e].y_move;
        }

        // Se o extremo esquerdo da entidade ultrapassar o limite superior da caixa de visualização,
        // programa a entidade para andar para baixo. 
        if(entityList[e].ponto_c_y > 100 - entityList[e].y_max)
        {
            entityList[e].ladoVertical = -1;
            entityList[e].ponto_c_y -= entityList[e].y_move;
        }
    }
}

// Garante que o player nunca saia da tela.
void dentroTela()
{
    // Se um dos extremos de cima, baixo, esqueda, direita ultrapassar seu respectivo limite da
    // caixa de visualização, sua coordenada X e/ou Y é programada para voltar para o limite,
    // fazendo que ele nunca saia da caixa de visualização.

    if(entityList[0].ponto_c_y > 100 - entityList[0].y_max)
        entityList[0].ponto_c_y = 100 - entityList[0].y_max;

    if(entityList[0].ponto_c_y < -100 - entityList[0].y_min)
        entityList[0].ponto_c_y = -100 - entityList[0].y_min;

    if(entityList[0].ponto_c_x > 100 * aspectRatio - entityList[0].x_max)
        entityList[0].ponto_c_x = 100 * aspectRatio - entityList[0].x_max;
    
    if(entityList[0].ponto_c_x < -100 * aspectRatio - entityList[0].x_min)
        entityList[0].ponto_c_x = -100 * aspectRatio - entityList[0].x_min;
}

// Callback da timerFunction.
// Usada para ficar cosntantemente verificando se alguma condição específica foi atendida.
void timer(int t)
{
    // Se ocorrer colisao, determina os valores X e Y de todas as entidades para seus valores default,
    // com o intuito de reiniciar a animação.
    if(endGame){
        endGame = 0;
        inicializaPosicoes();
    }

    // Movimenta o jogador.
    movimentacaoJogador();

    // Movimenta os NPCs.
    for(int i=1; i<6; i++)
        movimentaNPC(i);

    // Função que garante que player fique na tela.
    dentroTela();

    // Se ocorrer colisao entre o player e um dos 5 NPCs, começa o proceso def reiniciar a animação
    if(colisaoGeral(0,1) || colisaoGeral(0,2) || colisaoGeral(0,3) || colisaoGeral(0,4) || colisaoGeral(0,5)){
        endGame = 1;
        glutTimerFunc(2000, timer, 16); // Se ocorrer a colisão, o período da timer é momentaneamente definido para
                                        // 2 segundos, para a mensagem de "Game Over" aparecer na tela durante 2 segundos.
    }

    // Na proxima iteração da mainloop, a display() deve ser chamada.
    glutPostRedisplay();

    // Se não tiver acabado a animação, a timerfunc tem seu timer preservado.
    if(!endGame)
        glutTimerFunc(t, timer, t);
}

int main(int argc, char **argv)
{
    // Prepara a tela.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lista 2");

    // Inicializa as displaylists usadas para desenho.
    inicializar();

    // Cria algumas funções padrão.
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