#pragma once
#include "Maze2d.h"
#include <fstream>
#include <iterator>
#include <string>
using namespace std;

class MazeCompression {
public:
	MazeCompression() {}

	vector<int> Shrink(MazeGame* mg, ofstream& output_file)
	{
		Maze2d maze = *(mg->generate());
		vector<char> mazeData = maze.getdata();
		vector<int> newData;
		int counter = 1;
		int curr;
		if (mazeData.at(0) == ' ')
			curr = 0;
		if (mazeData.at(0) == '*')
			curr = 1;
		if (mazeData.at(0) == 'S')
			curr = -1;
		if (mazeData.at(0) == 'E')
			curr = -2;

		newData.push_back(curr);

		int size = mazeData.size();
		for (int i = 1; i < size; i++) {
			if (mazeData.at(i) == mazeData.at(i - 1))
				counter++;
			else {
				newData.push_back(counter);
				counter = 1;

				if (mazeData.at(i) == ' ')
					curr = 0;
				if (mazeData.at(i) == '*')
					curr = 1;
				if (mazeData.at(i) == 'S')
					curr = -1;
				if (mazeData.at(i) == 'E')
					curr = -2;

				newData.push_back(curr);
			}

		}
		newData.push_back(counter);
		//ofstream output_file("./Shrink.txt");
		ostream_iterator<string> output_iterator(output_file, "\n");
		int size2 = newData.size();
		for (int i = 0; i < size2; i++)
		{
			output_file << newData.at(i) << endl;
		}


		return newData;

	}


	vector<vector<char>> Restore(vector<int> data) {

		vector<vector<char>> theMaze;
		vector<char> tmp;
		int sum;
		char curr;
		vector<int> even;
		vector<int> odd;
		int size = data.size();
		for (int i = 0; i < size; ++i)
		{
			if (i % 2 == 0)
				even.push_back(data.at(i));
			else
				odd.push_back(data.at(i));
		}
		int size2 = odd.size();

		for (int i = 0; i < size2; ++i)
		{
			sum = odd.at(i);
			if (even.at(i) == 1)
				curr = '*';
			if (even.at(i) == 0)
				curr = ' ';
			if (even.at(i) == -1)
				curr = 'S';
			if (even.at(i) == -2)
				curr = 'E';
			for (int j = 0; j < sum; ++j)
			{
				tmp.push_back(curr);
			}
		}

		theMaze.resize(SIZE);
		for (int i = 0; i < SIZE; ++i)
			theMaze[i].resize(SIZE);
		int size3 = tmp.size();
		for (int i = 0; i < size3; ++i)
		{
			int row = i / SIZE;
			int col = i % SIZE;
			theMaze[row][col] = tmp[i];

		}

		return theMaze;

	}

};
