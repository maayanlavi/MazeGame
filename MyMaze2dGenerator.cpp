#include "MyMaze2dGenerator.h"

MyMaze2dGenerator::MyMaze2dGenerator() :MazeGame() {
	_maze = generate();

}
void MyMaze2dGenerator::ClearDS() {
	while (!stackMoves.empty()) { stackMoves.pop(); }

}
Maze2d* MyMaze2dGenerator::generate() {

	//DFS
	ClearDS();
	auto t1 = std::chrono::high_resolution_clock::now();
	_maze->initMaze();
	int randomX = ((2 * rand()) + 1) % (SIZE - 1);                      // Generate a random odd number between 1 and SIZE
	int randomY = ((2 * rand()) + 1) % (SIZE - 1);                      // Generate a random odd number between 1 and SIZE
	_maze->SetStartPosition(randomX, randomY);
	Cell curr = _maze->getStart();

	int vistedCell = 1;
	int totalCells = ((SIZE - 1) / 2) * ((SIZE - 1) / 2);

	while (vistedCell < totalCells)
	{

		if (_maze->Isvalid(curr.p.getX(), curr.p.getY()))
		{
			if ((curr.p.getY() > 1) && !_maze->IsVisited(curr.p.getX(), curr.p.getY() - 2)) {    // If not visited
				_maze->Setvisited(curr.p.getX(), curr.p.getY() - 1);
				_maze->SetWall(curr.p.getX(), curr.p.getY(), 'u');  // put wall
				stackMoves.push(curr);          // Push X for back track

				curr.p.setY(curr.p.getY() - 2);                 // Move to next cell
				_maze->Setvisited(curr.p.getX(), curr.p.getY());
				_maze->SetWall(curr.p.getX(), curr.p.getY(), 'd');
				vistedCell++;                 // Increase visitedCells counter

			}

			else {
				if ((curr.p.getX() < SIZE - 2) && !_maze->IsVisited(curr.p.getX() + 2, curr.p.getY())) {    // If not visited
					_maze->Setvisited(curr.p.getX() + 1, curr.p.getY());
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'r');  // put wall
					stackMoves.push(curr);          // Push X for back track

					curr.p.setX(curr.p.getX() + 2);               // Move to next cell
					_maze->Setvisited(curr.p.getX(), curr.p.getY());
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'l');
					vistedCell++;                 // Increase visitedCells counter
				}

				else
				{
					if ((curr.p.getY() < SIZE - 2) && !_maze->IsVisited(curr.p.getX(), curr.p.getY() + 2)) {    // If not visited
						_maze->Setvisited(curr.p.getX(), curr.p.getY() + 1);
						_maze->SetWall(curr.p.getX(), curr.p.getY(), 'd');  // put wall
						stackMoves.push(curr);          // Push X for back track

						curr.p.setY(curr.p.getY() + 2);                // Move to next cell
						_maze->Setvisited(curr.p.getX(), curr.p.getY());
						_maze->SetWall(curr.p.getX(), curr.p.getY(), 'u');
						vistedCell++;                 // Increase visitedCells counter

					}
					else {

						if ((curr.p.getX() > 1) && !_maze->IsVisited(curr.p.getX() - 2, curr.p.getY())) {    // If not visited
							_maze->Setvisited(curr.p.getX() - 1, curr.p.getY());

							curr.p.setX(curr.p.getX() - 2);                 // Move to next cell
							_maze->Setvisited(curr.p.getX(), curr.p.getY());
							_maze->SetWall(curr.p.getX(), curr.p.getY(), 'r');
							vistedCell++;                 // Increase visitedCells counter

						}

					}

				}
			}

		}

		else {
			curr = stackMoves.top();
			stackMoves.pop();



		}

		ClearScreen();
		_maze->Redraw();

	}




	_maze->SetEndPosition(curr.p.getX(), curr.p.getY());

	system("cls");
	ClearScreen();
	_maze->Redraw();
	cout << endl << "done!" << endl;


	return _maze;


}