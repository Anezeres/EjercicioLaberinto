CXX=g++

all: build

build:
	$(CXX) -std=c++11 -o main main.cpp Avatar.cpp Tablero.cpp

run:
	@./main