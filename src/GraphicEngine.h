#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <queue>
#include <vector>

typedef sf::Vector2f Position;

class GraphicEngine
{
public:
	GraphicEngine() = delete;
	GraphicEngine(GraphicEngine const&) = delete;
	GraphicEngine& operator=(GraphicEngine const&) = delete;

	GraphicEngine(sf::RenderWindow& window);

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

	void RequestRender(RenderableObject&& object);
	void RenderScene();
private:
	sf::RenderWindow& window;
	std::map<GraphicID, sf::Sprite> spriteMap;
	//std::priority_queue<RenderableObject, std::vector<RenderableObject>, /* LOWEST DEPTH */> renderQueue;
	//^ to be implemented once we implement the LOWEST DEPTH function object.
};