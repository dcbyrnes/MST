CC = g++ -Wall $(INCLUDEPATH)
CFLAGS = -g
LDFLAGS = -m64 -framework OpenGL -framework GLUT

PROGS = render

default: $(PROGS)

render: Render.o MST.o geom.o
	$(CC) -o $@ Render.o MST.o geom.o $(LDFLAGS)

Render.o: Render.cpp Render.h MST.h geom.h
	$(CC) -c $(INCLUDEPATH) Render.cpp -o $@

MST.o: MST.cpp MST.h geom.h
	$(CC) -c $(INCLUDEPATH) MST.cpp -o $@

geom.o: geom.cpp geom.h
	$(CC) -c $(INCLUDEPATH) geom.cpp -o $@

clean:: 
	rm *.o
	rm render