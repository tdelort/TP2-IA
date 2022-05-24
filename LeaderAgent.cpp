#include "LeaderAgent.h"
#include "ParamLoader.h"
#include "SteeringBehaviors.h"
#include "GameWorld.h"

LeaderAgent::LeaderAgent(GameWorld* world, Vector2D position, double rotation)
	: Vehicle(world, position, rotation, Vector2D(0,0), Prm.VehicleMass, Prm.MaxSteeringForce, Prm.MaxSpeed / 2, Prm.MaxTurnRatePerSecond, 10)
{
	SetScenario(GameWorld::Scenario::Wander);
}

LeaderAgent::~LeaderAgent()
{

}

void LeaderAgent::SetScenario(const GameWorld::Scenario scenario)
{
	SteeringBehavior* sb = Steering();
	sb->ArriveOff();
	sb->WanderOff();

	switch (scenario)
	{
	case GameWorld::Scenario::Wander:
		sb->WanderOn();
		break;
	case GameWorld::Scenario::UserControl:
		sb->ArriveOn();
		sb->SetTarget(m_target);
		break;
	}
}

void LeaderAgent::SetTarget(const Vector2D target)
{
	m_target = target;
	Steering()->SetTarget(m_target);
}
