#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(GraphicEngine & graphicEngine, GraphicEngine::GraphicID gid)
	: graphicComponent(graphicEngine, gid)
{
}

void AnimationComponent::RequestTileset(uint8 depth, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles)
{
	graphicComponent.spriteID = graphicComponent.graphics.RequestTileset(graphicComponent.graphicID, depth, tileWidth, tileHeight, numOfTiles);
}

void AnimationComponent::AddAnimation(uint8 startingTileID, uint8 finishingTileID, int32 milisecondsPerFrame)
{
	Animation animation = {};
	animation.startingTileID = startingTileID;
	animation.finishingTileID = finishingTileID;
	animation.msPerFrame = milisecondsPerFrame;
	animations[_animationCount++] = animation;
}

void AnimationComponent::Play(uint8 AnimationID)
{
	if (AnimationID <= _animationCount) //branch misprediction should rarely occur here
	{
		currentTileID = animations[AnimationID].startingTileID;
		lastTileID = animations[AnimationID].finishingTileID;
		msPerFrame = animations[AnimationID].msPerFrame;
		graphicComponent.ChangeTile(currentTileID);
		finishedAnimation = false;
	}
}

void AnimationComponent::Update(const sf::Time& timeStep)
{
	if (finishedAnimation) return;

	frameTimer += timeStep.asMilliseconds();
	if (frameTimer > msPerFrame)
	{
		frameTimer -= msPerFrame;
		graphicComponent.graphics.ChangeTile(graphicComponent.spriteID, ++currentTileID);
		if (currentTileID > lastTileID)
		{
			graphicComponent.ChangeTile(0);
			finishedAnimation = true;
		}
	}
}
