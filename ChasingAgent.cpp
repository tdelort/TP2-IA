#include "ChasingAgent.h"
#include "ParamLoader.h"
#include "SteeringBehaviors.h"
#include "GameWorld.h"
#include "misc/cgdi.h"

ChasingAgent::ChasingAgent(GameWorld* world, Vector2D position, double rotation, Vehicle* target, Vector2D offset)
	: Vehicle(world, position, rotation, Vector2D(0,0), Prm.VehicleMass, Prm.MaxSteeringForce, Prm.MaxSpeed, Prm.MaxTurnRatePerSecond, Prm.VehicleScale),
	  m_offset{offset},
	  m_target{target}
{
	Steering()->OffsetPursuitOn(m_target, m_offset);
}

ChasingAgent::~ChasingAgent()
{

}

void ChasingAgent::Update(double time_elapsed)
{
	// If another vehicle is closer than m_offset, activate Separation
	bool separate = false;
	for (BaseGameEntity* pV = World()->CellSpace()->begin(); !World()->CellSpace()->end(); pV = World()->CellSpace()->next())
	{    
	  if(pV != this)
	  {
	    Vector2D ToAgent = Pos() - pV->Pos();
		separate = separate || ToAgent.LengthSq() < m_offset.LengthSq();
	  }
	}

	if (separate)
	{
		Steering()->SeparationOn();
	}
	else
	{
		Steering()->SeparationOff();
	}

	Vehicle::Update(time_elapsed);
}

