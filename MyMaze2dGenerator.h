#pragma once
#include "MazeGame.h"
#include <stack>
#include <conio.h>
#include <stdlib.h> 
#include <time.h>  
#include <thread>
#include <chrono>
#include <random>
#include <algorithm> 

class MyMaze2dGenerator :public MazeGame {
private:
	stack <Cell> stackMoves;

public:
	MyMaze2dGenerator();
	virtual void ClearDS();
	virtual Maze2d* generate();

};