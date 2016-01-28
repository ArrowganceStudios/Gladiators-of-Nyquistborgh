#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <set>
#include <vector>
#include "BaseTypes.h"
#include "ForwardDeclarations.h"
#include "Constants.h"
#include "Tileset.h"

typedef sf::Vector2f Position;

class GraphicEngine
{
public:
	GraphicEngine(sf::RenderWindow& window, DataKeeper& dataKeeper);

	GraphicEngine(GraphicEngine const&) = delete;
	GraphicEngine& operator=(GraphicEngine const&) = delete;

	void LoadTextures();

	

	enum class GraphicID
	{
		IntroLogo,

		MenuBackground,

		MenuButtonNewGame,
		MenuButtonQuit,
		GameButtonEnterBattle,
		GameButtonEnterShop,
		GameButtonGoBack,

		ENUM_SIZE
	};

	void SetPosition(uint8 sid, sf::Vector2f pos) { 
		sprites[sid].sprite.setPosition(pos);
		//sprites[sid].setPosition(pos); 
	}
	void SetTexture(uint8 sid, GraphicID gid) { 
		sprites[sid].sprite.setTexture(textures[(int)gid]);
		//sprites[sid].setTexture(textures[(int)gid]); 
	}
	void SetAlpha(uint8 sid, float alpha) { 
		sprites[sid].sprite.setColor(sf::Color(255, 255, 255, sf::Uint8(alpha * 255.0f)));
		//sprites[sid].setColor(sf::Color(255, 255, 255, sf::Uint8(alpha * 255.0f))); 
	}

	uint8 RequestSprite(GraphicID gid, uint8 depth);
	uint8 RequestTileset(GraphicID gid, uint8 depth, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles);
	void ChangeTile(uint8 sid, uint8 tileNum);

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

	void ResetSprites()
	{
		for (int i = 0; i < MAX_SPRITES; ++i)
		{
			sprites[i].sprite.setPosition({ 0, 0 });
			sprites[i].sprite.setColor(sf::Color::White);
		}

		renderables.clear();
		_spritesCount = 0;
	}

	void Init();

	void RenderScene();
private:
	sf::RenderWindow& window;
	sf::Texture* textures;
	Tileset* sprites;
	std::multiset<Renderable, DepthTester> renderables;
	uint8 _spritesCount;
	uint8 _texturesCount;
	DataKeeper& dataKeeper;

	void LoadTexture(GraphicID gid, const char* path);
	uint8 CreateSprite(GraphicID gid);
	uint8 CreateTileset(GraphicID gid, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles);
};