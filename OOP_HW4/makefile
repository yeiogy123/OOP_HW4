all:main.o ConvexHull.o Line.o Point.o
	g++ -g main.o ConvexHull.o Line.o Point.o -o main
main.o:
	g++ -c main.cpp -o main.o
ConvexHull.o:ConvexHull.h
	g++ -c ConvexHull.cpp -o ConvexHull.o
Line.o:Line.h
	g++ -c Line.cpp -o Line.o
Point.o:Point.h
	g++ -c Point.cpp -o Point.o
clean:
	rm -f Point.o Line.o ConvexHull.o main.o main
