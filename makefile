all:
	g++ *.cpp -static -O3 -pedantic -Wall
debug:
	g++ *.cpp -g
tt:
	./a.out < ins/1.meio
	./a.out < ins/2.meio
	./a.out < ins/3.meio
	./a.out < ins/4.meio
t0:
	./a.out < ins/1.meio
