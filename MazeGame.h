#pragma once
#include "Maze2dGenerator.h"
#include <iostream>
#include <chrono>

class MazeGame : public Maze2dGenerator {
public:
    MazeGame();
    Maze2d* getMaze();
    void ClearScreen() const;
    void setMaze2d(Maze2d* m);
    virtual Maze2d* generate() = 0;
    virtual string measureAlgorithmTime();
};


