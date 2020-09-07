#pragma once
#include "AStar.h"


//template <class T>
class AStarManhattan :public Astar<Position> {
public:
	AStarManhattan() :Astar<Position>() {
	}

	virtual double Cost(State<Position> state, State<Position> goal) {
		double Gx, Sx, Gy, Sy;
		Gx = double(goal.getState().getX());
		Sx = double(state.getState().getX());
		Gy = double(goal.getState().getY());
		Sy = double(state.getState().getY());
		double res;
		res = double((Gx - Sx) + (Gy - Sy));
		return res;
	}



};