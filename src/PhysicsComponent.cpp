#include "PhysicsComponent.h"

static inline float Magnitude(const sf::Vector2f& vector)
{
	return sqrtf(pow(vector.x, 2) + pow(vector.y, 2));
}

void PhysicsComponent::SetTarget(const sf::Vector2f target, const float vel)
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
	float diffLength = Magnitude(diff);
	sf::Vector2f direction = diff / diffLength; 
	sf::Vector2f incr = leap * direction; 
	///////////////////////////////////
	if (diffLength > leap)
	{
		position += incr;
	}
	else
	{
		position = targetPos;
		moving = false;
	}
}
