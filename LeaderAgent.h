#pragma once
#include "Vehicle.h"

class LeaderAgent : public Vehicle
{
	LeaderAgent(GameWorld* world, Vector2D position, double rotation, Vehicle* target, Vector2D offset);
	~LeaderAgent();
	
	void Update(double time_elapsed) override; 
};

