#ifndef __Render_h
#define __Render_h
#include <iostream>
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#include "GLUT/glut.h"
#include "unistd.h"

#include "MST.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700

void Display();
void drawEdge(int index);
void initGraphStructure(int V, int E);

std::vector<Point2D>  * points;
Edge * MST;
Graph * G;

#endif