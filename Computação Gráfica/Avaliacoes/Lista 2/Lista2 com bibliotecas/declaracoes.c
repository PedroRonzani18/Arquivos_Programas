#include "declaracoes.h"

// Vetor que idntifica se as teclass 'w | s | d | a' ou as
// setas 'cima | baixo | direita | esquerda' estão ligadas
GLboolean on_off[4] = {0,0,0,0};

// EG = 1: game over.
GLint endGame = 0;

// Variável que ativa ou desativa o desenho da 'hitbox' de cada entidade.
GLboolean hitBox = false;

// Desenha o aviao do jogador
void desenhaPlayer()
{
    glColor3f(0.5, 0.5, 0.5); //cinza
    
    glBegin(GL_TRIANGLE_FAN); //ponta e tronco
        glVertex2f(0,0);
        glVertex2f(0,25);
        glVertex2f(5,15);
        glVertex2f(5,-20);
        glVertex2f(-5,-20);
        glVertex2f(-5,15);
        glVertex2f(0,25);
    glEnd();

    glBegin(GL_TRIANGLES);
        // calda esquerda
        glVertex3f( -5, -20, 0);
        glVertex3f(-15, -30, 0);
        glVertex3f( -5, -15, 0);
        // calda direita
        glVertex3f(  5,-20, 0);
        glVertex3f( 15,-30, 0);
        glVertex3f(  5,-15, 0);
        // asa direita
        glVertex3f(  5,  5, 0);
        glVertex3f(  5,  0, 0);
        glVertex3f( 20,-10, 0);
        // asa esquerda
        glVertex3f( -5,  0, 0);
        glVertex3f(-20,-10, 0);
        glVertex3f( -5,  5, 0);

    glColor3f(1, 0.25, 0.25); // vermelho

        //asa direita
        glVertex3f(  5,  0, 0);
        glVertex3f( 20,-10, 0);
        glVertex3f(  5, -5, 0);
        //asa esquerda
        glVertex3f( -5,  0, 0);
        glVertex3f(-20,-10, 0);
        glVertex3f( -5, -5, 0);

    glColor3f(0, 0, 1); // azul

        //calda direita
        glVertex3f(  0,-20, 0);
        glVertex3f( 15,-30, 0);
        glVertex3f(  0,-15, 0);
        //calda esquerda
        glVertex3f(  0,-20, 0);
        glVertex3f(-15,-30, 0);
        glVertex3f(  0,-15, 0);
    glEnd();

    glColor3f(1,0,0); // desenha Hitbox

    if(hitBox)// Desenha a hitbox da entidade
    {
        glBegin(GL_LINE_STRIP);
            glVertex2f(20, 25);
            glVertex2f(-20, 25);
            glVertex2f(-20, -30);
            glVertex2f(20, -30);
            glVertex2f(20, 25);
        glEnd();
    }
}

