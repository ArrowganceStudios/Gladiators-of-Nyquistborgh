#include "GraphicComponent.h"

GraphicComponent::GraphicComponent(GraphicEngine & graphicEngine, GraphicEngine::GraphicID gid)
	: graphics(graphicEngine), graphicID(gid)
{
}

void GraphicComponent::SetPosition(sf::Vector2f pos)
{
	graphics.SetPosition(spriteID, pos);
}

void GraphicComponent::SetScale(float factor)
{
	graphics.SetScale(spriteID, factor);
}

void GraphicComponent::SetRotation(float angle)
{
	graphics.SetRotation(spriteID, angle);
}

void GraphicComponent::SetOrigin(sf::Vector2f orig)
{
	graphics.SetOrigin(spriteID, orig);
}

void GraphicComponent::RequestTileset(uint8 depth, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles)
{
	spriteID = graphics.RequestTileset(graphicID, depth, tileWidth, tileHeight, numOfTiles);
}

void GraphicComponent::RequestSprite(uint8 depth)
{
	spriteID = graphics.RequestSprite(graphicID, depth);
}

void GraphicComponent::ChangeTile(uint8 tileNum)
{
	graphics.ChangeTile(spriteID, tileNum);
}

void GraphicComponent::SetTexture(GraphicEngine::GraphicID gid)
{
	graphics.SetTexture(spriteID, gid);
	graphicID = gid;
}

void GraphicComponent::SetAlpha(float alpha)
{
	graphics.SetAlpha(spriteID, alpha);
}
