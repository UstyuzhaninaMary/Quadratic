CC = gcc

build:
	$(CC) -o quadratic.out quadratic.cpp main.cpp quadroUnitTest.cpp -Wall -Wextra

run: build
	./quadratic.out