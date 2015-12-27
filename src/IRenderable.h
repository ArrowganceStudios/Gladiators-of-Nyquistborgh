#pragma once
#include "GraphicEngine.h"

class IRenderable
{
public:
	IRenderable(GraphicEngine& graphicEngine)
		: graphicEngine(graphicEngine) {}

	void RequestRender(Position position, GraphicEngine::GraphicID id)
	{
		graphicEngine.RequestRender(GraphicEngine::RenderableObject(position, id));
	}
private:
	GraphicEngine& graphicEngine;
};