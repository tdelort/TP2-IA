#pragma once

#include "Vehicle.h"
#include "2d/Vector2D.h"
#include "misc/Smoother.h"

#include <vector>
#include <list>
#include <string>

class GameWorld;
class SteeringBehavior;



class ChasingAgent : public Vehicle
{
	Vector2D m_offset;
	Vehicle* m_target;

public:
	ChasingAgent(GameWorld* world, Vector2D position, double rotation, Vehicle* target, Vector2D offset);
	~ChasingAgent();
	
	void Update(double time_elapsed) override; 

	void SetOffset(const Vector2D& offset);
	Vector2D Offset() const;

	void SetTarget(Vehicle* target);
	Vehicle* Target() const;
};
