#ifndef _DRAWINGS_H
#define _DRAWINGS_H

#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#include "Planet.h"
#include "Moon.h"

void drawSolidSphere(double radius, int stacks, int columns);

GLuint loadTexture(const char* arquivo);

void drawCorpse(Planet* p, double time);
void drawCorpse(Moon* p, double time);

//void configuraTextures();

#endif