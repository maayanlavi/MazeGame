#pragma once

#include <iostream>
#include <fstream>
#include "Observable.h"
#include "SimpleMaze2dGenerator.h"
#include "MyMaze2dGenerator.h"
#include "MazeCompression.h"
#include "Solution.h"
#include "BFS.h"
#include "AstarAirLine.h"
#include "AStarManhattan.h"
#include "Maze2dSearchable.h"
#include "historyMazes.h"
#include <dirent.h>
#include <filesystem>


using namespace std;

class MyModel :public Observable
{
public:

	MyModel() { history = new historyMazes(); }

	historyMazes* getHistory() const { return history; }

	void generate()
	{
		string name;
		string type;


		do {
			cout << "enter maze name: ";
			cin >> name;
			cout << "enter type: random / DFS : ";
			cin >> type;

			if (type.compare("random") != 0 && type.compare("DFS") != 0)
				cout << "Invalid input" << endl;

			if (type.compare("random") == 0) {
				MazeGame* mg = new SimpleMaze2dGenerator();
				history->setInAllMaze(name, mg);

			}
			if (type.compare("DFS") == 0) {
				MyMaze2dGenerator* mg = new MyMaze2dGenerator();
				history->setInAllMaze(name, mg);
			}
			cin.get();

		} while ((type.compare("random") != 0 && type.compare("DFS") != 0));


	}


	void save()
	{
		string name;
		cout << "entar maze name: ";
		cin >> name;
		string nameFile;
		cout << "entar file name: ";
		cin >> nameFile;
		MazeCompression mc;
		ofstream output_file(nameFile);
		MazeGame* mg = history->getAllMaze()[name];
		vector<int> shrink = mc.Shrink(mg, output_file);

	}

	void load()
	{
		string name = "";
		cout << "entar maze name: ";
		cin >> name;
		string nameFile;
		cout << "entar file name: ";
		cin >> nameFile;
		MazeCompression mc;
		ifstream in(nameFile);
		vector<int> restore;
		int x;
		// Read the next line from File untill it reaches the end.
		while (in >> x)
		{
			// Line contains string of length > 0 then save it in vector
			restore.push_back(x);
		}
		cin.get();
		vector<vector<char>> restore2 = mc.Restore(restore);
		Maze2d* m = new Maze2d(restore2);
		MazeGame* mg = new SimpleMaze2dGenerator();
		mg->setMaze2d(m);
		history->setInAllMaze(name, mg);
	}


	void solve()
	{

		string name;
		cout << "enter maze name: ";
		cin >> name;
		string Algorithm;
		string airLine = "Astar Airline";
		string man = "Astar Manhattan";
		cin.get();


		do {
			Algorithm = "";
			cout << "enter algorithm (BFS/ Astar Manhattan / Astar Airline): ";
			getline(cin, Algorithm);


			if (Algorithm.compare("BFS") == 0) {
				Maze2dSearchable ms(history->getAllMaze()[name]);
				BFS<Position> bfs;
				Solution<Position> s = bfs.search(ms);
				string solution = name;
				solution += " ";
				solution += Algorithm;
				if (history->isInSol(solution))
					return;
				history->setInAllMazeSol(solution, s);
			}

			if (Algorithm.compare(man) == 0) {
				Maze2dSearchable ms(history->getAllMaze()[name]);
				AStarManhattan man;
				Solution<Position> s = man.search(ms);
				typedef map<pair<Maze2d, string>, Solution<Position>> MapType;
				string solution = name;
				solution += " ";
				solution += Algorithm;
				if (history->isInSol(solution))
					return;
				history->setInAllMazeSol(solution, s);
			}

			if (Algorithm.compare(airLine) == 0) {
				Maze2dSearchable ms(history->getAllMaze()[name]);
				AstarAirLine air;
				Solution<Position> s = air.search(ms);
				string solution = name;
				solution += " ";
				solution += Algorithm;
				if (history->isInSol(solution))
					return;
				history->setInAllMazeSol(solution, s);
			}

			if ((Algorithm.compare(airLine) != 0) && (Algorithm.compare(man) != 0) && (Algorithm.compare("BFS") != 0))
			{
				cout << "Invalid input" << endl;
			}
		} while ((Algorithm.compare("Astar Airline") != 0) && (Algorithm.compare("Astar Manhattan") != 0) && (Algorithm.compare("BFS") != 0));


	}


	void exit()
	{
		ofstream out("AllSolutions.txt");
		for (auto& sol : history->getAllMazeSol()) {
			out << sol.first;
			out << endl;
			int size = sol.second.getSol().size();
			for (int i = 0; i < size; i++)
			{
				out << sol.second.getSol().at(i) << " ";
			}

		}
		out.close();
		delete history;
		_Exit(0);
	}

private:

	historyMazes* history;
};

