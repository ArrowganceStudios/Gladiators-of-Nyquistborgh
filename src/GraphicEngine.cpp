#include "GraphicEngine.h"

GraphicEngine::GraphicEngine(sf::RenderWindow & window)
	: window(window)
{
	//Graphic inits
}

void GraphicEngine::RequestRender(RenderableObject && object)
{
	renderQueue.push(object);
}

void GraphicEngine::RenderScene()
{
	window.clear(); 
	while (!renderQueue.empty())
	{
		window.draw(spriteMap[renderQueue.top().graphicID]);
		renderQueue.pop();
	}
	window.display();
}
