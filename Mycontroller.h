#pragma once
#include <typeinfo>
#include "controller.h"
#include "MyModel.h"
#include "Observer.h"
#include "AllFiles.h"
#include "GenerateMaze.h"
#include "displayMaze.h"
#include "saveMaze.h"
#include "loadMaze.h"
#include "MazeSize.h"
#include "FileSize.h"
#include "solve.h"
#include "displaySolution.h"
#include "exit.h"

using namespace std;

class Mycontroller : public Controller, public Observer
{
public:
	Mycontroller(MyModel* model, CLI* view) : Controller(), m_model(model), m_view(view)
	{
		view->addTomap("dir", new AllFiles(view));
		view->addTomap("generate maze", new GenerateMaze(model));
		view->addTomap("display", new displayMaze(view));
		view->addTomap("save maze", new saveMaze(model));
		view->addTomap("load maze", new loadMaze(model));
		view->addTomap("maze size", new MazeSize(view));
		view->addTomap("file size", new FileSize(view));
		view->addTomap("solve", new solve(model));
		view->addTomap("display solution", new displaySolution(view));
		view->addTomap("exit", new Exit(model));

	}
	~Mycontroller() {}


public:
	virtual Command* get(const string& command)
	{
		auto it = m_view->getMap().find(command);
		if (it == m_view->getMap().end())
			return nullptr;


		return it->second;
	}

	virtual void update(Observable& o) {
		{
			cout << "My controller notification - " << o.getAction() << endl;
		}

	}


private:
	MyModel* m_model;
	CLI* m_view;
	//map<string, Command*> m_commands;
};

