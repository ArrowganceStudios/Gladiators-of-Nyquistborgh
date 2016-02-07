#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <set>
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

	enum class GraphicID
	{
		IntroLogo,

		MenuBackground,
		MenuBackgroundTest,
		MenuBackgroundClouds,
		GameMenuBackground,

		MenuButtonNewGame,
		MenuButtonQuit,
		GameButtonEnterBattle,
		GameButtonEnterShop,
		GameButtonGoBack,

		TestColorAnim,

		ENUM_SIZE
	};

	enum class FontID
	{
		Default,

		ENUM_SIZE
	};

	sf::Vector2f GetPosition(uint8 sid) {
		return sprites[sid].sprite.getPosition();
	}

	void SetPosition(uint8 sid, sf::Vector2f pos) { 
		sprites[sid].sprite.setPosition(pos);
	}
	void SetScale(uint8 sid, float factor) {
		sprites[sid].sprite.setScale(factor, factor);
	}
	void SetRotation(uint8 sid, float angle) {
		sprites[sid].sprite.setRotation(angle);
	}
	void SetOrigin(uint8 sid, sf::Vector2f orig) {
		sprites[sid].sprite.setOrigin(orig);
	}
	void SetTexture(uint8 sid, GraphicID gid) { 
		sprites[sid].sprite.setTexture(textures[(int)gid]);
	}
	void SetAlpha(uint8 sid, float alpha) { 
		sprites[sid].sprite.setColor(sf::Color(255, 255, 255, sf::Uint8(alpha * 255.0f)));
	}

	void MoveBy(uint8 sid, sf::Vector2f pos) {
		sprites[sid].sprite.move(pos);
	}

	uint8 RequestSprite(GraphicID gid, uint8 depth);
	uint8 RequestTileset(GraphicID gid, uint8 depth, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles);
	sf::Text* RequestText(const sf::Vector2f &position, const sf::String &string, FontID font = FontID::Default);
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

	void Reset();
	void Init();
	void RenderScene();

private:
	sf::RenderWindow& window;
	sf::Texture* textures;
	Tileset* sprites;
	sf::Font* fonts;
	sf::Text* texts;
	std::multiset<Renderable, DepthTester> renderables; //to be changed to radix sort later
	uint8 _spritesCount;
	uint8 _texturesCount;
	uint8 _fontsCount;
	uint8 _textsCount;
	DataKeeper& dataKeeper;

	void LoadTextures();
	void LoadTexture(GraphicID gid, const char* path);
	void LoadFonts();
	void LoadFont(const char* path);
	uint8 CreateSprite(GraphicID gid);
	uint8 CreateTileset(GraphicID gid, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles);
};