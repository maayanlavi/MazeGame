#pragma once
#include "AStar.h"
#include <math.h> 

class AstarAirLine :public Astar<Position> {
public:
	AstarAirLine() :Astar<Position>() {}

	virtual double Cost(State<Position> state, State<Position> goal) {
		double Gx, Sx, Gy, Sy;
		Gx = double(goal.getState().getX());
		Sx = double(state.getState().getX());
		Gy = double(goal.getState().getY());
		Sy = double(state.getState().getY());
		double x = Gx - Sx;
		double x2 = pow(x, 2);
		double y = Gy - Sy;
		double y2 = pow(y, 2);
		double res = sqrt(x2 + y2);
		return res;

	}




};