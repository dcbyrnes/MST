#ifndef __Geom_h
#define __Geom_h
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cfloat>
#include <math.h>

#define DELTA 0.0000000001

struct Point2D {
	float x, y;
	Point2D(int a, int b) {
		x = a;
		y = b;
	}
};

struct Edge {
	int source, destination;
	double weight;
};

// undirected, weighted graph
struct Graph {
	int v, e; // vertices and edges
	struct Edge * edge;
};


Graph * createGraph(int V, int E);
int comp(const void * a, const void * b);
double computeSlope(Point2D a, Point2D b);
double computeDistance(Point2D a, Point2D b);

#endif