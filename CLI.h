#pragma once
#include "view.h"
#include "Observable.h"
#include "historyMazes.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

class CLI : public view, public Observable {
public:
	CLI(istream& in, ostream& out, historyMazes* h) : _in(in), _out(out), history(h)
	{
	}

	virtual void doCommand(Command* com)
	{
		com->execute();
	}

	virtual void start(istream& in)
	{
		string str = "";
		while (str.compare("exit"))
		{
			cout << "enter command>> " << endl;
			getline(in, str);
			if (map.count(str))
				doCommand(map[str]);
			else
				cout << "this command is not found!" << endl;
		}



	}

	void ShowAllFiles()
	{
		DIR* dr;
		struct dirent* en;
		dr = opendir("."); //open all directory
		if (dr) {
			while ((en = readdir(dr)) != NULL) {
				cout << " \n" << en->d_name; //print all directory name
			}
			closedir(dr); //close all directory
		}
		cout << endl;
	}

	void display()
	{
		string name;
		do {
			cout << "entar maze name: ";
			cin >> name;
		} while (history->getAllMaze()[name] == nullptr);
		cout << *history->getAllMaze()[name]->getMaze();
	}

	void MazeSize()
	{
		string name;
		cout << "entar maze name: ";
		cin >> name;
		int size = sizeof(history->getAllMaze()[name]);
		cout << "the size of " << name << " in the memory is " << size << " bytes" << endl;
	}

	void FileSize()
	{
		string name;
		cout << "entar maze name: ";
		cin >> name;
		MazeCompression mc;
		ofstream output_file("example.txt");
		vector<int> shrink = mc.Shrink(history->getAllMaze()[name], output_file);
		cout << "the size of " << name << " in file is " << sizeof(output_file) << " bytes" << endl;
	}

	void displaySolution()
	{
		string name;
		cout << "entar maze name: ";
		cin >> name;
		string Algorithm;
		cin.get();
		cout << "entar algorithm (BFS/ Astar Manhattan / Astar Airline): ";
		getline(cin, Algorithm);
		string s = name + " " + Algorithm;
		cout << history->getAllMazeSol()[s] << endl;
	}
	void addTomap(string s, Command* c) { map[s] = c; }
	map<string, Command*> getMap() const { return map; }



private:
	istream& _in;
	ostream& _out;
	map<string, Command*> map;
	historyMazes* history;
};
