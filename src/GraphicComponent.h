#pragma once
#include "GraphicEngine.h"

class AnimationComponent;

class GraphicComponent
{
	friend class AnimationComponent;

public:
	GraphicComponent(GraphicEngine& graphicEngine, GraphicEngine::GraphicID gid);
	void RequestTileset(uint8 depth, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles);
	void RequestSprite(uint8 depth);

	void SetPosition(sf::Vector2f pos);
	void SetScale(float factor);
	void SetRotation(float angle);
	void SetOrigin(sf::Vector2f orig);
	void SetTexture(GraphicEngine::GraphicID gid); //do we rly need this anymore?
	void SetAlpha(float alpha);
	void ChangeTile(uint8 tileNum);

	

private:
	GraphicEngine& graphics;
	GraphicEngine::GraphicID graphicID;
	uint8 spriteID;
};