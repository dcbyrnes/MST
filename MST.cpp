#include "MST.h"

/* 
	Kruskal's algorithm to find minimum spanning tree. Uses a disjoint-set
	data structure (supports union and find operations) to prevent cycles in MST. 
*/

Edge * KruskalMST(Graph * graph) {
	int vertices = graph->v;
	Edge * MST = new Edge[vertices];
	int e = 0, i = 0;
	
	// sort edges by weights
	// selection of edges occurs via greedy algorithm
	qsort(graph->edge, graph->e, sizeof(graph->edge[0]), comp);

	Subset * subsets = (Subset * ) malloc(vertices * sizeof (Subset) );
	for(int v = 0; v < vertices; v++) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < vertices - 1) {
		Edge current_edge = graph->edge[i++];
		
		int x = find(subsets, current_edge.source);
		int y = find(subsets, current_edge.destination);

		if (x != y) {
			MST[e++] = current_edge;
			Union(subsets, x, y);
		}
	}

	for(int i = 0; i < e; i++) {
		printf("%d -- %d == %f \n", MST[i].source, MST[i].destination, MST[i].weight);
	}

	return MST;
}

int find(Subset * subsets, int index) {
	if (subsets[index].parent != index) {
		subsets[index].parent = find(subsets, subsets[index].parent);
	}
	return subsets[index].parent;
}

void Union(Subset subsets[], int x, int y) {
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if(subsets[xroot].rank < subsets[yroot].rank) {
		subsets[xroot].parent = yroot;
	}
	else if(subsets[xroot].rank > subsets[yroot].rank) {
		subsets[yroot].parent = xroot;
	}
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}
























