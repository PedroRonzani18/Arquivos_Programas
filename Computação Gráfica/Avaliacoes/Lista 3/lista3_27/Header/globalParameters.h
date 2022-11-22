#ifndef _GLOBALPARAMETERS_H
#define _GLOBALPARAMETERS_H

#include <GL/freeglut.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include "Keyboard.h"

extern int slices, stacks; // slices e stacks das esferas
extern float razaoAspecto;
extern double tempo;
extern Keyboard* keys;
extern std::vector<GLuint> texturesId;
extern int xMouse, yMouse; 
extern int larguraJanela, alturaJanela;

#endif