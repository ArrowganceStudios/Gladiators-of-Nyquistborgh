#pragma once
#include "SFML\System.hpp"

class PhysicsComponent
{
public:
	void SetTarget(sf::Vector2f target, float vel);
	void UpdatePosition(const sf::Time& timeStep, sf::Vector2f& position);
private:
	bool moving;
	float velocity;
	sf::Vector2f targetPos;
};