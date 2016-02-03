#include "Button.h"
#include "Constants.h"

//I have a feeling that having constant size of buttons is
//going to bring us pain in the future.
#define BUTTON_WIDTH 240
#define BUTTON_HEIGHT 80

enum ButtonStates
{
	BUTTON_DEFAULT = 0,
	BUTTON_HOVER = 1,
	BUTTON_PRESSED = 2,

	BUTTON_STATES_NUM
};

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
	graphicComponent.SetPosition(pos);
	topLeft = { pos.x, pos.y };
	botRight = { pos.x + BUTTON_WIDTH, pos.y + BUTTON_HEIGHT}; // TODO: sort this stuff out
}

void Button::Init()
{
	graphicComponent.RequestTileset(1, BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_STATES_NUM);
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
			graphicComponent.ChangeTile(BUTTON_HOVER);
		}
		else
			graphicComponent.ChangeTile(BUTTON_DEFAULT);
	}
	else if (input.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2i cursor = { input.mouseButton.x, input.mouseButton.y };
		if (IsInsideBounds(cursor, topLeft, botRight))
		{
			graphicComponent.ChangeTile(BUTTON_PRESSED);
		}
	}
	else if (input.type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2i cursor = { input.mouseButton.x, input.mouseButton.y };
		if (IsInsideBounds(cursor, topLeft, botRight))
		{
			graphicComponent.ChangeTile(BUTTON_PRESSED);
			action();
		}
	}
	input.type = (sf::Event::EventType)NULL; //resets the input to "closed" event
}
