#pragma once

#include <map>
#include <string>
#include <functional>
#include "Command.h"
#include "MyModel.h"
#include "view.h"

using namespace std;

class Controller
{
public:
	Controller() {}
	~Controller() {}

	virtual Command* get(const string& command) = 0;

};

