all:
	g++ *.cpp -static -O3 -pedantic -Wall
debug:
	g++ *.cpp -g
t0:
	./a.out < /ins/1.meio