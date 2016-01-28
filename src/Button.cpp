#include "Button.h"
#include "Constants.h"

#define BUTTON_DEFAULT 0
#define BUTTON_HOVER 1
#define BUTTON_PRESSED 2

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
	botRight = { pos.x + BUTTON_WIDTH, pos.y + BUTTON_HEIGHT}; // TODO: sort this stuff out
}

void Button::Init()
{
	sid = graphics.RequestTileset(gid, 1, BUTTON_WIDTH, BUTTON_HEIGHT - 10, 3);
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
			graphics.ChangeTile(sid, BUTTON_HOVER);
		}
		else
			graphics.ChangeTile(sid, BUTTON_DEFAULT);
	}
	else if (input.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2i cursor = { input.mouseButton.x, input.mouseButton.y };
		if (IsInsideBounds(cursor, topLeft, botRight))
		{
			graphics.ChangeTile(sid, BUTTON_PRESSED);
		}
	}
	else if (input.type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2i cursor = { input.mouseButton.x, input.mouseButton.y };
		if (IsInsideBounds(cursor, topLeft, botRight))
		{
			graphics.ChangeTile(sid, BUTTON_PRESSED);
			action();
		}
	}
	input.type = (sf::Event::EventType)NULL; //resets the input to "closed" event
}
