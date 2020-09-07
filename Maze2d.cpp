#include "Maze2d.h"

Position::Position() :_x(0), _y(0) {}
Position::Position(int x, int y) : _x(x), _y(y) {}
Position::Position(const Position& m) :_x(m._x), _y(m._y) {}
int Position::getX() const { return _x; }
int Position::getY() const { return _y; }
void Position::setX(int x) {
	if (x < SIZE && x >= 0 && this != nullptr)
		_x = x;
}
void Position::setY(int y) {
	if (y < SIZE && y >= 0 && this != nullptr)
		_y = y;
}
ostream& operator<<(ostream& os, const Position& p)
{
	cout << "(" << p.getX() << ", " << p.getY() << ")" << endl;
	return os;

}

bool operator!=(const Position& p1, const Position& p2)
{
	if (p1.getX() != p2.getX() || p1.getY() != p2.getY())
		return true;
	return false;
}

bool operator==(const Position& p1, const Position& p2)
{
	if (p1.getX() == p2.getX() && p1.getY() == p2.getY())
		return true;
	return false;
}


Cell::Cell() : visited(false), top_wall(true), bot_wall(true), left_wall(true), right_wall(true), display(' ') {}


bool Cell::operator==(const Cell& c1)const {

	if (this->p.getX() == c1.p.getX() && this->p.getY() == c1.p.getY()) {
		return true;
	}
	else
		return false;


}

Cell& Cell::operator=(const Cell& other) {
	p.setX(other.p.getX());
	p.setY(other.p.getY());
	visited = other.visited;
	bot_wall = other.bot_wall;
	top_wall = other.top_wall;
	left_wall = other.left_wall;
	right_wall = other.right_wall;
	display = other.display;
	return *this;
}

	Maze2d::Maze2d() : _start(NULL), _end(NULL) {}
	Maze2d::Maze2d(vector<char>& vec) {
		initMaze();
		int p = 0;
		_start = new Cell();
		_end = new Cell();
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {

				Board[i][j].display = vec[p];
				if (Board[i][j].display == 'S') {
					_start = &Board[i][j];
				}
				if (Board[i][j].display == 'E') {
					_end = &Board[i][j];
				}
				p++;
			}

		}
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (i % 2 != 0 && j % 2 != 0) {


					if (Board[i][j].display == ' ') {
						if (i > 1) {
							if (Board[i - 2][j].display == ' ')
							{
								Board[i][j].top_wall = false;
								Board[i - 2][j].bot_wall = false;
							}
						}
						if (i < SIZE - 2) {
							if (Board[i + 2][j].display == ' ')
							{
								Board[i][j].bot_wall = false;
								Board[i + 2][j].top_wall = false;
							}

						}
						if (j > 1) {
							if (Board[i][j - 2].display == ' ')
							{
								Board[i][j].left_wall = false;
								Board[i][j - 2].right_wall = false;
							}
						}
						if (j < SIZE - 2) {
							if (Board[i][j + 2].display == ' ')
							{
								Board[i][j].right_wall = false;
								Board[i][j + 2].left_wall = false;
							}
						}
					}

				}


			}

		}


		Redraw();

	}

	Maze2d::Maze2d(vector<vector<char>> vec)
	{
		initMaze();
		_start = new Cell();
		_end = new Cell();
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {

				Board[i][j].display = vec[i][j];
				if (Board[i][j].display == 'S') {
					_start = &Board[i][j];
				}
				if (Board[i][j].display == 'E') {
					_end = &Board[i][j];
				}
			}

		}
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (i % 2 != 0 && j % 2 != 0) {


					if (Board[i][j].display == ' ') {
						if (i > 1) {
							if (Board[i - 2][j].display == ' ')
							{
								Board[i][j].top_wall = false;
								Board[i - 2][j].bot_wall = false;
							}
						}
						if (i < SIZE - 2) {
							if (Board[i + 2][j].display == ' ')
							{
								Board[i][j].bot_wall = false;
								Board[i + 2][j].top_wall = false;
							}

						}
						if (j > 1) {
							if (Board[i][j - 2].display == ' ')
							{
								Board[i][j].left_wall = false;
								Board[i][j - 2].right_wall = false;
							}
						}
						if (j < SIZE - 2) {
							if (Board[i][j + 2].display == ' ')
							{
								Board[i][j].right_wall = false;
								Board[i][j + 2].left_wall = false;
							}
						}
					}

				}


			}

		}


		Redraw();
	}


	Maze2d& Maze2d::operator=(const Maze2d& m) {
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++) {
				Board[i][j] = m.Board[i][j];
			}
		}
		_start = new Cell();
		*_start = *m._start;
		_end = new Cell();
		*_end = *m._end;
		return *this;
	}

	void Maze2d::Redraw() {
		for (int i = 0; i < SIZE; i++) {
			cout << endl;
			for (int j = 0; j < SIZE; j++)
				cout << " " << Board[i][j].display;
		}
	}
	bool Maze2d::Isvalid(int NextX, int Nexty) {
		if (((Board[Nexty - 2][NextX].visited == false) && (Board[Nexty][NextX].top_wall == true && Board[Nexty - 2][NextX].bot_wall == true)) ||
			((Board[Nexty + 2][NextX].visited == false) && (Board[Nexty][NextX].bot_wall == true && Board[Nexty + 2][NextX].top_wall == true)) ||
			((Board[Nexty][NextX - 2].visited == false) && (Board[Nexty][NextX].left_wall == true && Board[Nexty][NextX - 2].right_wall == true)) ||
			((Board[Nexty][NextX + 2].visited == false) && (Board[Nexty][NextX].right_wall == true && Board[Nexty][NextX + 2].left_wall == true)))
		{

			return true;
		}
		else {

			return false;

		}
	}

	void Maze2d::Setdisplay(int x, int y, string str) {
		if (str == "start") {
			Board[y][x].display = 'S';
		}
		else {
			Board[y][x].display = 'E';
			Board[y][x].visited = true;
		}
	}
	void Maze2d::SetStartPosition(int x, int y) {
		Board[y][x].display = 'S';                      // Set S as the start cell
		Board[y][x].visited = true;
		_start = &Board[y][x];

	}

	Position Maze2d::getStartPosition() {
		int x = _start->p.getX();
		int y = _start->p.getY();
		Position p(x, y);
		return p;
	}
	Position Maze2d::getGoalPosition() {
		int x = _end->p.getX();
		int y = _end->p.getY();
		Position p(x, y);
		return p;
	}


	bool Maze2d::IsVisited(int x, int y) {
		if (Board[y][x].visited == true)
			return true;
		else
			return false;
	}
	void Maze2d::Setvisited(int x, int y) { Board[y][x].visited = true;  Board[y][x].display = ' '; }
	void Maze2d::SetWall(int x, int y, char c) {
		if (c == 'u')
			Board[y][x].top_wall = false;
		if (c == 'd')
			Board[y][x].bot_wall = false;
		if (c == 'l')
			Board[y][x].left_wall = false;
		if (c == 'r')
			Board[y][x].right_wall = false;
	}
	void Maze2d::SetEndPosition(int x, int y) {
		Board[y][x].display = 'E';                      // Set S as the start cell
		_end = &Board[y][x];

	}

	string* Maze2d::getPossibleMoves(Position p) {
		int x = p.getX();
		int y = p.getY();
		static string res[4];
		string left = "left";
		string right = "right";
		string up = "up";
		string down = "down";
		int i = 0;
		if (Board[y][x].left_wall == false && Board[y][x - 1].display != '*') {
			res[i] = left;
			i++;
		}

		if (Board[y][x].right_wall == false && Board[y][x + 1].display != '*') {
			res[i] = right;
			i++;
		}

		if (Board[y][x].top_wall == false && Board[y - 1][x].display != '*') {
			res[i] = up;
			i++;
		}

		if (Board[y][x].bot_wall == false && Board[y + 1][x].display != '*') {
			res[i] = down;
			i++;
		}


		return res;
	}

	void Maze2d::initMaze() {

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				Board[i][j].p.setX(j);
				Board[i][j].p.setY(i);
				Board[i][j].display = '*';
				Board[i][j].visited = false;
				Board[i][j].top_wall = true;
				Board[i][j].bot_wall = true;
				Board[i][j].left_wall = true;
				Board[i][j].right_wall = true;
			}
		}
		for (int i = 1; i < SIZE - 1; i++) {
			for (int j = 1; j < SIZE - 1; j++) {
				// Border Cells have fewer accessible walls
				Board[1][j].top_wall = false;
				Board[SIZE - 2][j].bot_wall = false;
				Board[i][1].left_wall = false;
				Board[i][SIZE - 2].right_wall = false;
			}
		}
		_start = new Cell();
		_end = new Cell();

	}
	void Maze2d::displaySolve(int x, int y) {
		Board[y][x].display = '^';

	}

	vector<char> Maze2d::getdata() {
		vector<char> data;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				data.push_back(this->Board[i][j].display);
			}

		}
		return data;
	}

	//Position* Maze2d::getStartState() {
	//	return &this->getStartPosition();

	//}

	//Position* Maze2d::getGoalState() {
	//	Position* p;
	//	p = &getGoalPosition();

	//	return p;
	//}


	std::vector<State<Position>> Maze2d::CalculateStates(State<Position>* st)
	{
		std::vector<State<Position>> vec;
		int xCurr = st->getState().getX();
		int yCurr = st->getState().getY();
		string* moves;
		moves = getPossibleMoves(st->getState());
		string left = "left";
		string right = "right";
		string up = "up";
		string down = "down";
		int i = 0;

		if (moves[i].compare(left) == 0)
		{
			Position p(xCurr - 1, yCurr);
			State<Position> s(p);
			vec.push_back(s);
			i++;
		}

		if (moves[i].compare(right) == 0)
		{
			Position p(xCurr + 1, yCurr);
			State<Position> s(p);
			vec.push_back(s);
			i++;
		}
		if (moves[i].compare(up) == 0)
		{
			Position p(xCurr, yCurr - 1);
			State<Position> s(p);
			vec.push_back(s);
			i++;
		}

		if (moves[i].compare(down) == 0)
		{
			Position p(xCurr, yCurr + 1);
			State<Position> s(p);
			vec.push_back(s);
			i++;
		}



		return vec;
	}

	Cell Maze2d::getStart() { return *_start; }
	Cell Maze2d::getEnd() { return *_end; }


	Cell& Maze2d::getCell(int x, int y) {
		return Board[y][x];
	}
	Cell* Maze2d::getCellpointer(int x, int y) {
		Cell* p = new Cell();
		*p = Board[y][x];

		return p;
	}

	//friend ostream& operator<<(ostream& os, const Maze2d& maze);



ostream& operator<<(ostream& os, const Maze2d& maze)
{
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; j++)
		{
			cout << maze.Board[j][i].display << " ";
		}
		cout << endl;
	}
	return os;

}