#include "Button.h"

static bool IsInsideBounds(sf::Vector2i pos, sf::Vector2f topLeft, sf::Vector2f botRight)
{
	return pos.x > topLeft.x &&
		pos.x < (botRight.x) &&
		pos.y > topLeft.y &&
		pos.y < (botRight.y);
}

void Button::SetPosition(sf::Vector2f pos)
{
	//sf::Vector2u size = graphics.GetSizeOf(GraphicId::GButton);
	graphics.SetPosition(sid, pos);
	topLeft = { pos.x, pos.y };
	botRight = { pos.x + 240, pos.y + 90 }; //240 and 90 is the current size, TODO: sort this stuff out
}

void Button::Update()
{
	InterpretInput();
}

void Button::InterpretInput()
{
	if (input.type == sf::Event::MouseMoved)
	{
		sf::Vector2i cursor = { input.mouseMove.x, input.mouseMove.y };
		if (IsInsideBounds(cursor, topLeft, botRight))
		{
			ChangeTexture(GraphicEngine::GraphicID::MenuButtonNewGameHovered);
		}
		else
			ChangeTexture(GraphicEngine::GraphicID::MenuButtonNewGameStatic);
	}
	else if (input.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2i cursor = { input.mouseButton.x, input.mouseButton.y };
		if (IsInsideBounds(cursor, topLeft, botRight))
		{
			ChangeTexture(GraphicEngine::GraphicID::MenuButtonNewGamePressed);
		}
	}
	else if (input.type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2i cursor = { input.mouseButton.x, input.mouseButton.y };
		if (IsInsideBounds(cursor, topLeft, botRight))
		{
			ChangeTexture(GraphicEngine::GraphicID::MenuButtonNewGamePressed);
			action();
		}
	}
}
