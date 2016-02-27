#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


#include "geom.h"

struct Subset {
	int parent, rank;
};

Edge * KruskalMST(Graph * graph);
int find(Subset * subsets, int index);
void Union(Subset subsets[], int x, int y);



