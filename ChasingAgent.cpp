#include "ChasingAgent.h"
#include "ParamLoader.h"
#include "SteeringBehaviors.h"
#include "GameWorld.h"

ChasingAgent::ChasingAgent(GameWorld* world, Vector2D position, double rotation, Vehicle* target, Vector2D offset)
	: Vehicle(world, position, rotation, Vector2D(0,0), Prm.VehicleMass, Prm.VehicleMass, Prm.MaxSpeed, Prm.MaxTurnRatePerSecond, Prm.VehicleScale),
	  m_offset{offset},
	  m_target{target}
{
	Steering()->OffsetPursuitOn(m_target, m_offset);
	Steering()->SeparationOn();
}

ChasingAgent::~ChasingAgent()
{

}

void ChasingAgent::Update(double time_elapsed)
{
	// Do something ?
}

void ChasingAgent::SetOffset(const Vector2D& offset)
{
	m_offset = offset;
	Steering()->OffsetPursuitOn(m_target, m_offset);
}

Vector2D ChasingAgent::Offset() const
{
	m_offset;
}


void ChasingAgent::SetTarget(Vehicle* target)
{
	m_target = target;
	Steering()->OffsetPursuitOn(m_target, m_offset);
}

Vehicle* ChasingAgent::Target() const
{
	m_target;
}

