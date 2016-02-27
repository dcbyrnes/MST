#include "geom.h"

Graph * createGraph(int V, int E) {

	Graph * graph = (Graph*) malloc( sizeof(Graph) );
	graph->v = V;
	graph->e = E;
	graph->edge = (Edge*) malloc( graph->e * sizeof(Edge) );

	return graph;
}

int comp(const void * a, const void * b) {
	Edge * v = (Edge * ) a;
	Edge * w = (Edge * ) b;

	if (v->weight > w->weight) return 1;
	else if (v->weight < w->weight) return -1;
	return 0;
}

double computeSlope(Point2D a, Point2D b) {
	if ( fabs(a.x - b.x) < DELTA) {
		std::cout << a.x << " " << b.x << std::endl;
		return DBL_MAX;
	}
	if ( fabs(a.y - b.y) < DELTA ) {
		return 0;
	}

	return (b.y - a.y)/(b.x - a.x);

}

double computeDistance(Point2D a, Point2D b) {
	return sqrt ( pow((b.x - a.x), 2) + pow((b.y - a.y), 2) );
}