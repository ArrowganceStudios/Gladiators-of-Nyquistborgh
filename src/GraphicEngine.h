#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <set>
#include <vector>
#include "BaseTypes.h"
#include "ForwardDeclarations.h"
//#include "DataKeeper.h"

typedef sf::Vector2f Position;

class GraphicEngine
{
public:
	GraphicEngine(sf::RenderWindow& window, DataKeeper& dataKeeper);

	GraphicEngine(GraphicEngine const&) = delete;
	GraphicEngine& operator=(GraphicEngine const&) = delete;

	void LoadTextures();

	void SetPosition(uint8 sid, sf::Vector2f pos) { sprites[sid].setPosition(pos); }

	enum class GraphicID
	{
		//until we'll use spritesheets, the order of button graphics
		//needs to be preserved, so it can change it's appearance 
		//according to it's needs
		MenuBackground,
		MenuButtonNewGameStatic,
		MenuButtonNewGameHovered,
		MenuButtonNewGamePressed,
		MenuButtonQuitStatic,
		MenuButtonQuitHovered,
		MenuButtonQuitPressed,

		GameButtonEnterBattleStatic,
		GameButtonEnterBattleHover,
		GameButtonEnterBattlePressed,
		GameButtonEnterShopStatic,
		GameButtonEnterShopHover,
		GameButtonEnterShopPressed,
		GameButtonGoBackStatic,
		GameButtonGoBackHover,
		GameButtonGoBackPressed,

		ENUM_SIZE //lil' trick yo
	};

	void SetTexture(uint8 sid, GraphicID gid) { sprites[sid].setTexture(textures[(int)gid]); }

	uint8 RequestSprite(GraphicID gid, uint8 depth);

	struct Renderable
	{
		uint8 sid;
		int depth;
	};

	class DepthTester
	{
	public:
		bool operator()(const Renderable& lhs, const Renderable& rhs)
		{
			return lhs.depth < rhs.depth;
		}
	};

	void Init();

	void RenderScene();
private:
	sf::RenderWindow& window;
	sf::Texture* textures;
	sf::Sprite* sprites;
	std::multiset<Renderable, DepthTester> renderables;
	uint8 _spritesCount;
	uint8 _texturesCount;
	DataKeeper& dataKeeper;

	void LoadTexture(GraphicID gid, const char* path);
	uint8 CreateSprite(GraphicID gid);
};