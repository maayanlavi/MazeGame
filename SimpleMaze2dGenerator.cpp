#include "SimpleMaze2dGenerator.h"



SimpleMaze2dGenerator::SimpleMaze2dGenerator() :MazeGame() {
	_maze = generate();
}


void SimpleMaze2dGenerator::ClearDS() {
	vecPoint.clear();
}

Maze2d* SimpleMaze2dGenerator::generate() {
	ClearDS();
	_maze->initMaze();
	int randomX = ((2 * rand()) + 1) % (SIZE - 1);                      // Generate a random odd number between 1 and SIZE
	int randomY = ((2 * rand()) + 1) % (SIZE - 1);                      // Generate a random odd number between 1 and SIZE
	_maze->SetStartPosition(randomX, randomY);
	vecPoint.push_back(_maze->getStart());
	int vistedCell = 1;

	Cell curr = _maze->getStart();

	int totalCells = ((SIZE - 1) / 2) * ((SIZE - 1) / 2);


	while (vistedCell < totalCells)
	{
		if (_maze->Isvalid(curr.p.getX(), curr.p.getY()))
		{
			int random = rand() % 4 + 1;		// Pick a random wall 1-4 to knock down

			// GO UP
			if ((random == 1) && (curr.p.getY() > 1)) {
				if (!_maze->IsVisited(curr.p.getX(), curr.p.getY() - 2)) {    // If not visited
					_maze->Setvisited(curr.p.getX(), curr.p.getY() - 1);
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'u');  // Knock down wall
					Cell nextMove = _maze->getCell(curr.p.getX(), curr.p.getY() - 2);

					vecPoint.push_back(nextMove);
					curr.p.setY(curr.p.getY() - 2);                 // Move to next cell
					_maze->Setvisited(curr.p.getX(), curr.p.getY());
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'd');
					vistedCell++;                 // Increase visitedCells counter
				}
				else
					continue;
			}

			// GO DOWN
			else if ((random == 2) && (curr.p.getY() < SIZE - 2)) {
				if (!_maze->IsVisited(curr.p.getX(), curr.p.getY() + 2)) {    // If not visited
					_maze->Setvisited(curr.p.getX(), curr.p.getY() + 1);
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'd');  // Knock down wall
					Cell nextMove = _maze->getCell(curr.p.getX(), curr.p.getY() + 2);

					vecPoint.push_back(nextMove);
					curr.p.setY(curr.p.getY() + 2);                  // Move to next cell
					_maze->Setvisited(curr.p.getX(), curr.p.getY());
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'u');
					vistedCell++;                 // Increase visitedCells counter
				}
				else
					continue;
			}

			// GO LEFT
			else if ((random == 3) && (curr.p.getX() > 1)) {
				if (!_maze->IsVisited(curr.p.getX() - 2, curr.p.getY())) {    // If not visited
					_maze->Setvisited(curr.p.getX() - 1, curr.p.getY());
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'l');  // Knock down wall
					Cell nextMove = _maze->getCell(curr.p.getX() - 2, curr.p.getY());

					vecPoint.push_back(nextMove);
					curr.p.setX(curr.p.getX() - 2);                  // Move to next cell
					_maze->Setvisited(curr.p.getX(), curr.p.getY());
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'r');
					vistedCell++;                 // Increase visitedCells counter
				}
				else
					continue;
			}



			// GO RIGHT
			else if ((random == 4) && (curr.p.getX() < SIZE - 2)) {
				if (!_maze->IsVisited(curr.p.getX() + 2, curr.p.getY())) {    // If not visited
					_maze->Setvisited(curr.p.getX() + 1, curr.p.getY());
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'r');  // Knock down wall

					Cell nextMove = _maze->getCell(curr.p.getX() + 2, curr.p.getY());

					vecPoint.push_back(nextMove);
					curr.p.setX(curr.p.getX() + 2);                   // Move to next cell
					_maze->Setvisited(curr.p.getX(), curr.p.getY());
					_maze->SetWall(curr.p.getX(), curr.p.getY(), 'l');
					vistedCell++;                 // Increase visitedCells counter
				}
				else
					continue;
			}


		}


		else {

			for (size_t i = 0; i < vecPoint.size(); i++) {
				if (vecPoint.at(i).p.getX() == curr.p.getX() && vecPoint.at(i).p.getY() == curr.p.getY()) {
					vecPoint.erase(vecPoint.begin() + i);
				}
			}

			random_shuffle(vecPoint.begin(), vecPoint.end());
			curr = vecPoint.at(vecPoint.size() - 1);

		}

		ClearScreen();
		_maze->Redraw();

	}



	_maze->SetEndPosition(curr.p.getY(), curr.p.getY());
	system("cls");
	ClearScreen();
	_maze->Redraw();
	cout << endl << "done!" << endl;
	return _maze;
}