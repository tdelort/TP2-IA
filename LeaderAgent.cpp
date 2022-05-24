#include "LeaderAgent.h"
#include "ParamLoader.h"
#include "SteeringBehaviors.h"
#include "GameWorld.h"

LeaderAgent::LeaderAgent(GameWorld* world, Vector2D position, double rotation, Vehicle* target, Vector2D offset)
	: Vehicle(world, position, rotation, Vector2D(0,0), Prm.VehicleMass, Prm.VehicleMass, Prm.MaxSpeed, Prm.MaxTurnRatePerSecond, Prm.VehicleScale)
{
	Steering()->WanderOn();
}

LeaderAgent::~LeaderAgent()
{

}

void LeaderAgent::Update(double time_elapsed)
{
	// do smth ?
}
