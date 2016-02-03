#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(GraphicEngine & graphicEngine, GraphicEngine::GraphicID gid)
	: graphicComponent(graphicEngine, gid), transitionDelay(32)
{
}

void AnimationComponent::RequestTileset(uint8 depth, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles)
{
	graphicComponent.spriteID = graphicComponent.graphics.RequestTileset(graphicComponent.graphicID, depth, tileWidth, tileHeight, numOfTiles);
}

void AnimationComponent::AddAnimation(uint8 startingTileID, uint8 finishingTileID)
{
	Animation animation = {};
	animation.startingTileID = startingTileID;
	animation.finishingTileID = finishingTileID;
	animations[_animationCount++] = animation;
}

void AnimationComponent::Play(uint8 AnimationID)
{
	if (AnimationID <= _animationCount) //branch misprediction should rarely occur here
	{
		currentTileID = animations[AnimationID].startingTileID;
		graphicComponent.ChangeTile(currentTileID);
		lastTileID = animations[AnimationID].finishingTileID;
		finishedAnimation = false;
	}
}

void AnimationComponent::Update()
{
	if (finishedAnimation)
		return;
	if ((++currentDelay) < transitionDelay)
	{
		return;
	}
	currentDelay = 0;

	graphicComponent.graphics.ChangeTile(graphicComponent.spriteID, ++currentTileID);
	if (currentTileID > lastTileID)
	{
		graphicComponent.ChangeTile(0);
		finishedAnimation = true;
	}
}
