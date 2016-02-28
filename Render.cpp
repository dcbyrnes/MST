#include "Render.h"


void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// draw vertices 
	glPointSize(10);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
		glColor3f(0.9,0.8,0.2);
		for (int i = 0; i < points->size(); i ++) {
			glVertex2f( points->at(i).x/WINDOW_WIDTH, points->at(i).y/WINDOW_HEIGHT );
		}
	glEnd();

	// draw edges
	int start, end;
	glColor3f(0.0,1.0,0.0);
	glLineWidth(0.5);
	glLineStipple(2, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	for (int k = 0; k < G->e; k++) {
		start = G->edge[k].source;
		end = G->edge[k].destination;

		glBegin(GL_LINES);
			glVertex2f(points->at(start).x/WINDOW_WIDTH, points->at(start).y/WINDOW_WIDTH);
			glVertex2f(points->at(end).x/WINDOW_WIDTH, points->at(end).y/WINDOW_WIDTH);
		glEnd();
	}
	glDisable(GL_LINE_STIPPLE);
	glFlush();

	// // draw MST 
	for (int j = 0; j < points->size() - 1; j++) { // size of MST array is always #points - 1 
		usleep(1000000); // sleep 1 second to slow down display 
		drawEdge(j);
	}
}

void drawEdge(int index) {
	// draw MST edges
	glColor3f(1.0,0.0,0.0);
	int start = MST[index].source;
	int end = MST[index].destination;
	glLineWidth(2.0);
	glBegin(GL_LINES);
		glVertex2f(points->at(start).x/WINDOW_WIDTH, points->at(start).y/WINDOW_WIDTH);
		glVertex2f(points->at(end).x/WINDOW_WIDTH, points->at(end).y/WINDOW_WIDTH);
	glEnd();
	glFlush();
}

int main(int argc, char ** argv) {

	int vertices = 5;
	int edges = 7;
	initGraphStructure(vertices, edges); // create graph 

	MST = KruskalMST(G); // compute MST 

	// init window for rendering 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Render");
	glClearColor(0.0,0.0,0.0,0.0);
	glutDisplayFunc(Display); 
	glutMainLoop();
}

void initGraphStructure(int V, int E) {

	// graph to draw
	// 0 --> {100, 90}
	// 1 --> {200, 350}
	// 2 --> {-500, 150}
	// 3 --> {80, -400}
	// 4 --> {14, 170}

	points = new std::vector<Point2D>;

	points->push_back(Point2D(-100, 400)); 
	points->push_back(Point2D(-200, 400));
	points->push_back(Point2D(-200, -50));
	points->push_back(Point2D(400, -50));
	points->push_back(Point2D(600, -50));

	G = createGraph(V, E); // consider changing this to adjacency matrix

	G->edge[0].source = 0;
	G->edge[0].destination = 1;

	G->edge[1].source = 1;
	G->edge[1].destination = 2;

	G->edge[2].source = 0;
	G->edge[2].destination = 2;

	G->edge[3].source = 0;
	G->edge[3].destination = 3;

	G->edge[4].source = 0;
	G->edge[4].destination = 4;

	G->edge[5].source = 2;
	G->edge[5].destination = 3;

	G->edge[6].source = 3;
	G->edge[6].destination = 4;

	for (int i = 0; i < E; i++) {
		G->edge[i].weight = computeDistance(points->at(G->edge[i].source), points->at(G->edge[i].destination));
		std::cout << G->edge[i].weight << std::endl;
 	}

}






