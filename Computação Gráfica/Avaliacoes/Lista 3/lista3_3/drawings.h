#ifndef _DRAWINGS_H
#define _DRAWINGS_H

#include <GL/freeglut.h>
#include <SOIL/SOIL.h>

#include "Planet.h"

void drawSolidSphere(double radius, int stacks, int columns);

void drawSun(double angle);

void drawEarth(double angle);

void drawMoon(double angle);

void drawBackground(double z);

GLuint loadTexture(const char* arquivo);

void drawCorpse(Planet* p, double time);

#endif