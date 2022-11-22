#include "../Header/globalParameters.h"

int slices = 200, stacks = 200;
float razaoAspecto;
bool usarTextura = true;

bool light0Ligada = true;   // Luz branca ligada?
float d = 1.0;           // Intensidade da cor difusa da luz branca
float e = 1.0;           // Intensidade da cor especular da luz branca
float m = 0.2;           // Intensidade da luz ambiente global
bool localViewer = false;
bool isLightingOn = true;     // (x,y) do ponteiro do mouse
float larguraJanela, alturaJanela;       // (w,h) da janela
int matShine = 50;

/* Propriedades das fontes de luz */
    float lightAmb[] = {0,0,0,1}; // ??

    float lightDif0[] = {d,d,d,1}; // intensidade da difusa do branco
    float lightSpec0[] = {e,e,e,1}; // intensidade da especular do branco
    float lightPos0[] = {0,0,0,1}; // posicionada no centro e é posicional ??

    float globAmb[] = { m, m, m, 1};

double tempo;

int keys[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

std::vector<GLuint> texturesId;