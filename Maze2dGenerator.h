#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <windows.h>
#include "Maze2d.h"
using namespace std;



class Maze2dGenerator {
protected:
	Maze2d* _maze;
	string _timeAlgo;


public:

	Maze2dGenerator() {
		_maze = new Maze2d();

	}

	virtual Maze2d* generate() = 0;
	virtual string measureAlgorithmTime() = 0;

};