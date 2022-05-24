#pragma once
#include "Vehicle.h"
#include "GameWorld.h"

class LeaderAgent : public Vehicle
{
	Vector2D m_target;
public:
	LeaderAgent(GameWorld* world, Vector2D position, double rotation);
	~LeaderAgent();
	

	void SetScenario(const GameWorld::Scenario scenario);
	void SetTarget(const Vector2D target);
};

