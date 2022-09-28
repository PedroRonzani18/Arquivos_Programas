#ifndef _DECLARACOES_H
#define _DECLARACOES_F

#include <GL/freeglut.h>
#include <stdbool.h>

// Vetor que idntifica se as teclass 'w | s | d | a' ou as
// setas 'cima | baixo | direita | esquerda' estão ligadas
GLboolean on_off[4];

// ID das displaylists de desenho
GLint aviaoDisplayList, aviaoDisplayList1, aviaoDisplayList2;

// Variavel da razão aspecto da tela.
GLfloat aspectRatio;

// EG = 1: game over.
GLint endGame;

// Variável que ativa ou desativa o desenho da 'hitbox' de cada entidade.
GLboolean hitBox;

// Struct que contém os dados das entidades.
typedef struct ENTIDADE
{
    double x_max, x_min; // Valores maximos e minimos que x e y podem alcançar 
    double y_max, y_min; // baseados nas coordenadas extremas do desenho.
    double x_resize, y_resize; // Escalas de redimensionamento das coordenadas.
    double ponto_c_x, ponto_c_y; // Coordenadas do ponto central.
    double x_move, y_move; // Unidade de movimento nos eixos x e y ("velocidade" da entidade).
    int ladoHorizontal, ladoVertical; // LH = 1: anda na horizontal. 
                                      // LV = 1: anda na vertical.
    GLboolean onScreen; // Objeto se econtra dentro da caixa de visualização ou não.
    GLuint model; // ID da displayList de desenho.
}
entidade;

// Array que armazena as Structs das entidades
entidade entityList[6];

void desenhaPlayer();

#endif