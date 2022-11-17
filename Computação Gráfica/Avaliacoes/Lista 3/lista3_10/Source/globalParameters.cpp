#include "../Header/globalParameters.h"

int slices = 200, stacks = 200;
int angle=60;
GLuint sol, terra, lua, estrelas;
float razaoAspecto;
Mix_Music* music1;
bool usarTextura = true;

bool light0Ligada = true;   // Luz branca ligada?
float d = 1.0;           // Intensidade da cor difusa da luz branca
float e = 1.0;           // Intensidade da cor especular da luz branca
float m = 0.2;           // Intensidade da luz ambiente global
float p = 1.0;           // A luz branca é posicional?
float s = 50.0;          // Expoente especular do material (shininess)
bool localViewer = false;
bool isLightingOn = true;     // (x,y) do ponteiro do mouse
float larguraJanela, alturaJanela;       // (w,h) da janela
int matShine = s;
float z=0;

/* Propriedades das fontes de luz */
    float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 }; // ??

    float lightDif0[] = { d, d, d, 1.0 }; // intensidade da difusa do branco
    float lightSpec0[] = { e, e, e, 1.0 }; // intensidade da especular do branco
    float lightPos0[] = { 0.0, 0.0, z, p }; // posição ?? da liz
                                            // p altera fonte direcional ou posicional (0 ou 1);
                                            // p=1 atravessa textura, mas menor
                                            // p=0 não atra\vessa mas é maior

    float globAmb[] = { m, m, m, 1.0 };

double tempo;