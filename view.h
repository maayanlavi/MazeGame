#pragma once
#include <istream>
#include <ostream>
#include <map>
#include "MazeCompression.h"
#include "Command.h"

using namespace std;

class view {
public:

	virtual void doCommand(Command* com) = 0;
	virtual void start(istream& in) = 0;

};
