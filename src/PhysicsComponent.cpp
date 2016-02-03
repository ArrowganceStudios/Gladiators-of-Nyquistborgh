#include "PhysicsComponent.h"

void PhysicsComponent::SetTarget(sf::Vector2f target, float vel)
{
	moving = true;
	targetPos = target;
	velocity = vel;
}

void PhysicsComponent::UpdatePosition(const sf::Time & timeStep, sf::Vector2f & position)
{
	if (!moving) return;
	float leap = timeStep.asSeconds() * velocity;
	///// This hurts my very soul /////
	sf::Vector2f diff = targetPos - position;
	float diffLength = sqrt((diff.x * diff.x) + (diff.y * diff.y));
	sf::Vector2f normDiff = { diff.x / diffLength, diff.y / diffLength };
	sf::Vector2f incr = { leap * normDiff.x, leap * normDiff.y };
	float incrLength = sqrt((incr.x * incr.x) + (incr.y * incr.y));
	///////////////////////////////////
	if (diffLength > incrLength)
	{
		position += incr;
	}
	else
	{
		position = targetPos;
		moving = false;
	}
}
