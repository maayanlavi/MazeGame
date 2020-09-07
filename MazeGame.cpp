#include "MazeGame.h"

MazeGame::MazeGame() : Maze2dGenerator() {}

Maze2d* MazeGame::getMaze() { return _maze; }

void MazeGame::ClearScreen() const {
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void MazeGame::setMaze2d(Maze2d* m) { *_maze = *m; }

string MazeGame::measureAlgorithmTime() {
    string res;
    auto start = chrono::steady_clock::now();
    Maze2d* maze = new Maze2d();
    maze = generate();
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    res = "Elapsed time in microseconds : ";
    auto x = chrono::duration_cast<chrono::milliseconds>(duration).count();
    string s = to_string(x);
    res += s;
    res += " milliseconds";
    return res;

}