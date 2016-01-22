#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <queue>
#include <vector>

//#include "DataKeeper.h"

typedef sf::Vector2f Position;

class GraphicEngine
{
public:
	GraphicEngine(sf::RenderWindow& window);

	//GraphicEngine() = delete;
	//GraphicEngine(GraphicEngine const&) = delete;
	//GraphicEngine& operator=(GraphicEngine const&) = delete;

	enum class GraphicID
	{
		//stuff
	};

	struct RenderableObject
	{
		RenderableObject(Position position, GraphicID id, float scale = 1.0f)
			: position(position), graphicID(id), scale(scale) {}

		float scale;
		Position position;
		GraphicID graphicID;
	};

	class DepthTester
	{
	public:
		bool operator()(RenderableObject& lhs, RenderableObject& rhs)
		{
			return lhs.position.y > rhs.position.y;
		}
	};

	void RequestRender(RenderableObject&& object);
	void RenderScene();
private:
	sf::RenderWindow& window;
	std::map<GraphicID, sf::Sprite> spriteMap;
	std::priority_queue<RenderableObject, std::vector<RenderableObject>, DepthTester> renderQueue;
};