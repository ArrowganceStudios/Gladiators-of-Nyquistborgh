#pragma once
#include "GraphicEngine.h"
#include "GraphicComponent.h"

#define MAX_ANIMATIONS 4

class AnimationComponent
{
public:
	AnimationComponent(GraphicEngine& graphicEngine, GraphicEngine::GraphicID gid);
	void RequestTileset(uint8 depth, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles);

	void AddAnimation(uint8 startingTileID, uint8 finishingTileID);
	void Play(uint8 AnimationID);

	void Update();

	GraphicComponent graphicComponent;
private:
	//animation id is an index in the anims
	struct Animation
	{
		uint8 startingTileID;
		uint8 finishingTileID;
	};

	uint8 currentTileID;
	uint8 lastTileID;
	const uint32 transitionDelay;
	uint32 currentDelay;
	bool finishedAnimation;

	uint8 _animationCount;
	Animation animations[MAX_ANIMATIONS];
};