#pragma once
#include <functional>
#include "ForwardDeclarations.h"
#include "GraphicEngine.h"
#include "GraphicComponent.h"

class Button
{
public:
	//Button() = default;
	Button(GraphicEngine& graphics, GraphicEngine::GraphicID gid, std::function<void()> action)
		: graphicComponent(graphics, gid), action(action)
	{
	}

	void SetPosition(sf::Vector2f pos);

	void Init();
	void Update();
	void InterpretInput();

	void SetInput(sf::Event event) { input = event; }

private:
	GraphicComponent graphicComponent;
	sf::Vector2f topLeft;
	sf::Vector2f botRight;
	sf::Event input;
	std::function<void()> action;
};