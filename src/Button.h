#pragma once
#include <functional>
#include "ForwardDeclarations.h"
#include "GraphicEngine.h"
#include <SFML\System.hpp>

class Button
{
public:
	//Button() = default;
	Button(GraphicEngine& graphics, GraphicEngine::GraphicID gid, std::function<void()> action)
		: graphics(graphics), action(action), gid(gid)
	{
	}

	void SetPosition(sf::Vector2f pos);

	void Init();
	void Update();
	void InterpretInput();

	void SetInput(sf::Event event) { input = event; }

private:
	GraphicEngine& graphics;
	sf::Vector2f topLeft;
	sf::Vector2f botRight;
	sf::Event input;
	uint8 sid; //sprite id
	GraphicEngine::GraphicID gid;
	std::function<void()> action;
};