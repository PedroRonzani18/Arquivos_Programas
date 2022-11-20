#ifndef _GLOBALPARAMETERS_H
#define _GLOBALPARAMETERS_H

#include <GL/freeglut.h>
#include <SDL2/SDL_mixer.h>
#include <vector>

extern int slices, stacks; // sclices e stacks dos
extern float razaoAspecto;

extern Mix_Music* music1; //Musica de fundo


extern float d, // Intensidade da cor difusa da luz branca
             e, // Intensidade da cor especular da luz branca
             m; // Intensidade da luz ambiente global

extern bool localViewer,
            isLightingOn, // iluminação opengl ligada?
            usarTextura,  // textura ligada?
            light0Ligada; // Luz sol ligada?

extern float larguraJanela, alturaJanela;       // (w,h) da janela
extern int matShine;

/* Propriedades das fontes de luz */
extern float lightAmb[];    // ??
extern float lightDif0[];  // intensidade da difusa do branco
extern float lightSpec0[]; // intensidade da especular do branco
extern float lightPos0[];  // posição ?? da luz
extern float globAmb[];

extern double tempo;
extern int keys[];

extern std::vector<GLuint> texturesId;


#endif