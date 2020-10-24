CC=g++
CFLAGS=-std=c++14 -pedantic
OUTPUT=oop_exercise_02

all:
	$(CC) $(CFLAGS) Complex.h Complex.cpp main.cpp -o $(OUTPUT)
run:
	./$(OUTPUT)