#include "../Header/globalParameters.h"
#include "../Header/Keyboard.h"

int slices = 200, stacks = 200;
float razaoAspecto;

float d = 1.0;           // Intensidade da cor difusa da luz branca
float e = 1.0;           // Intensidade da cor especular da luz branca
float m = 0.2;           // Intensidade da luz ambiente global
float s = 50;
int matShine = s;

/* Propriedades das fontes de luz */
    float lightAmb[] = {0,0,0,1}; // ??

    float lightDif0[] = {d,d,d,1}; // intensidade da difusa do branco
    float lightSpec0[] = {e,e,e,1}; // intensidade da especular do branco
    float lightPos0[] = {0,0,0,1}; // posicionada no centro e é posicional ??

    float globAmb[] = { m, m, m, 1};

double tempo;

//int keys[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Keyboard keys;

std::vector<GLuint> texturesId;