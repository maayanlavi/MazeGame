#pragma once
#include "MazeGame.h"
#include <stack>
#include <conio.h>
#include <stdlib.h> 
#include <time.h>  
#include <thread>
#include <chrono>
#include <random>


class SimpleMaze2dGenerator :public MazeGame {
private:
	vector<Cell> vecPoint;

public:
	SimpleMaze2dGenerator();
	virtual void ClearDS();
	virtual Maze2d* generate();

};