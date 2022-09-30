#include "inicializa.h"
#include "movimentos.h"

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

using namespace std;

void dentroTela()
{
    // Se um dos extremos de cima, baixo, esqueda, direita ultrapassar seu respectivo limite da
    // caixa de visualização, sua coordenada X e/ou Y é programada para voltar para o limite,
    // fazendo que ele nunca saia da caixa de visualização.

    if(entityList[0].centro.y + entityList[0].y_max > 100)
        entityList[0].centro.y = 100 - entityList[0].y_max;

    if(entityList[0].centro.y + entityList[0].y_min < -100 )
        entityList[0].centro.y = -100 - entityList[0].y_min;

    if(entityList[0].centro.x + entityList[0].x_max > 100 * aspectRatio)
        entityList[0].centro.x = 100 * aspectRatio - entityList[0].x_max;
    
    if(entityList[0].centro.x + entityList[0].x_min < -100 * aspectRatio)
        entityList[0].centro.x = -100 * aspectRatio - entityList[0].x_min;
}

void movimentacaoJogador()
{
    double aux_angle = grausParaRadianos(entityList[0].angulo);

    // Aumenta a angulação da entidade com '+' e diminui com '-'
    entityList[0].angulo += (on_off[4] - on_off[5]) * entityList[0].angularSpeed;

    // Movimenta para cima e para baixo com 'w' e 's' ou 'cima' e 'baixo'
    entityList[0].centro.x += (on_off[0] - on_off[1]) * cos(aux_angle) * entityList[0].vetorialSpeed;
    entityList[0].centro.y += (on_off[0] - on_off[1]) * sin(aux_angle) * entityList[0].vetorialSpeed;

    // Movimenta para direita e esquerda com 'd' e 'a' ou '->' e '<-'
    entityList[0].centro.x += (on_off[2] - on_off[3]) * cos(aux_angle - M_PI/2) * entityList[0].vetorialSpeed;
    entityList[0].centro.y += (on_off[2] - on_off[3]) * sin(aux_angle - M_PI/2) * entityList[0].vetorialSpeed;

    // Variáveis auxiliares
    double x,y;

    for(int i=0; i<4; i++)
    {
        // Usadas no calculo dos valores de x' e y' ao rotacionar a entidade
        x = entityList[0].hitbox[i].x;
        y = entityList[0].hitbox[i].y;

        // Altera o valor das coordenadas x e y da hitbox de acordo com as rotações
        entityList[0].alteredHitbox[i].x = x * cos(aux_angle + M_PI/2) - y * sin(aux_angle + M_PI/2);
        entityList[0].alteredHitbox[i].y = x * sin(aux_angle + M_PI/2) + y * cos(aux_angle + M_PI/2);

        // Altera o valor das coordenadas x e y da hitbox de acordo com as translações
        entityList[0].alteredHitbox[i].x += entityList[0].centro.x;
        entityList[0].alteredHitbox[i].y += entityList[0].centro.y;
    }
}

void movimentaNPC(int e)
{
    // Se o NPC andar na horizontal, executa os comandos
    if(entityList[e].ladoHorizontal != 0) 
    {
        // Se a entidade estiver programada para andar para a esquerda, diminui o valor X do ponto central
        if(entityList[e].ladoHorizontal == -1)
            entityList[e].centro.x -= entityList[e].x_move;

        // Se a entidade estiver programada para andar para a direita, aumenta o valor X do ponto central
        if(entityList[e].ladoHorizontal ==  1)
            entityList[e].centro.x += entityList[e].x_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite esquero da caixa de visualização,
        // programa a entidade para andar para a direita. 
        if(entityList[e].centro.x < -100 * aspectRatio - entityList[e].x_min)
        {
            entityList[e].ladoHorizontal = 1;
            entityList[e].centro.x += entityList[e].x_move;
        }

        // Se o extremo direito da entidade ultrapassar o limite direito da caixa de visualização,
        // programa a entidade para andar para a esquerda. 
        if(entityList[e].centro.x > 100 * aspectRatio - entityList[e].x_max)
        {
            entityList[e].ladoHorizontal = -1;
            entityList[e].centro.x -= entityList[e].x_move;
        }
    }

    // Se o NPC andar na vetical, executa os comandos
    if(entityList[e].ladoVertical != 0)
    {
        // Se a entidade estiver programada para andar para baixo, diminui o valor Y do ponto central.
        if(entityList[e].ladoVertical == -1)
            entityList[e].centro.y -= entityList[e].y_move;

        // Se a entidade estiver programada para andar para cima, aumenta o valor Y do ponto central.
        if(entityList[e].ladoVertical ==  1)
            entityList[e].centro.y += entityList[e].y_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite inferior da caixa de visualização,
        // programa a entidade para andar para cima. 
        if(entityList[e].centro.y + entityList[e].y_min < -100 )
        {
            entityList[e].ladoVertical = 1;
            entityList[e].centro.y += entityList[e].y_move;
        }

        // Se o extremo esquerdo da entidade ultrapassar o limite superior da caixa de visualização,
        // programa a entidade para andar para baixo. 
        if(entityList[e].centro.y + entityList[e].y_max > 100 )
        {
            entityList[e].ladoVertical = -1;
            entityList[e].centro.y -= entityList[e].y_move;
        }
    }

}

void shotHitbox(int e)
{
    for(int i=0; i<4; i++)
    {
        shotsList[e].alteredHitbox[i].x = shotsList[e].hitbox[i].x + shotsList[e].centro.x;
        shotsList[e].alteredHitbox[i].y = shotsList[e].hitbox[i].y + shotsList[e].centro.y;
    }
}

void enemyHitbox(int e)
{
    for(int i=0; i<4; i++)
    {
        entityList[e].alteredHitbox[i].x = entityList[e].hitbox[i].x + entityList[e].centro.x;
        entityList[e].alteredHitbox[i].y = entityList[e].hitbox[i].y + entityList[e].centro.y;
    }
}

int colisaoGeral(entidade* e1, entidade* e2)
{
    vertice iniDiag, fimDiag, iniLado, fimLado, deltaVet;
    double l=0, d1=0, d2=0;
    int overlap = 0;

    iniDiag.x = e1->centro.x;
    iniDiag.y = e1->centro.y;
    
    for(int i=0; i<4; i++)
    {
        deltaVet.x = 0;
        deltaVet.y = 0;

        fimDiag.x = e1->alteredHitbox[i].x;
        fimDiag.y = e1->alteredHitbox[i].y;

        for(int j=0, s=1; j<4; j++, s=(j+1)%4) 
        {
            iniLado = e2->alteredHitbox[j];
            fimLado = e2->alteredHitbox[s];

            l = (fimLado.x - iniLado.x) * (iniDiag.y - fimDiag.y) - (iniDiag.x - fimDiag.x) * (fimLado.y - iniLado.y);

            d1 = ((iniLado.y - fimLado.y) * (iniDiag.x - iniLado.x) + (fimLado.x - iniLado.x) * (iniDiag.y - iniLado.y)) / l;

            d2 = ((iniDiag.y - fimDiag.y) * (iniDiag.x - iniLado.x) + (fimDiag.x - iniDiag.x) * (iniDiag.y - iniLado.y)) / l;

            if((0.0 <= d1 && d1 < 1.0) && (0.0 <= d2 && d2 < 1.0))
            {
                deltaVet.x += (1.0 - d1) * (fimDiag.x - iniDiag.x);
                deltaVet.y += (1.0 - d1) * (fimDiag.y - iniDiag.y);
                overlap = 1;
            }

            //ACHO Q É ESSE O PROBLEMA
            e1->centro.x += deltaVet.x * -1;
            e1->centro.y += deltaVet.y * -1;
        }
    }
    return overlap;
}

void escreveTexto(void * font, char *s, float x, float y)
{
    glPushMatrix();
        glLoadIdentity();
        glRasterPos2d(x - 20, y);

        for (int i = 0; i < strlen(s); i++) 
            glutBitmapCharacter(font, s[i]);
    glPopMatrix();
}
