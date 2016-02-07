#include "GraphicEngine.h"
#include "DataKeeper.h"

GraphicEngine::GraphicEngine(sf::RenderWindow & window, DataKeeper& dataKeeper)
	: window(window), dataKeeper(dataKeeper)
{
	_spritesCount = 0;
	_texturesCount = 0;
	_fontsCount = 0;
	_textsCount = 0;
}

uint8 GraphicEngine::RequestSprite(GraphicID gid, uint8 depth)
{
	uint8 sid = CreateSprite(gid);
	renderables.insert(Renderable{ sid, depth });
	return sid;
}

uint8 GraphicEngine::RequestTileset(GraphicID gid, uint8 depth, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles)
{
	uint8 sid = CreateTileset(gid, tileWidth, tileHeight, numOfTiles);
	renderables.insert(Renderable{ sid, depth });
	return sid;
}

sf::Text* GraphicEngine::RequestText(const sf::Vector2f &position, const sf::String &string, FontID font)
{
	if (_textsCount < MAX_TEXTS)
	{
		sf::Text *pText = &texts[_textsCount];
		pText->setPosition(position);
		pText->setFont(fonts[(int)font]);
		pText->setString(string);
		++_textsCount;
		return pText;
	}
	else
	{
		printf("No more texts slots available, increase the capacity");
		return nullptr;
	}
}

void GraphicEngine::ChangeTile(uint8 sid, uint8 tileNum)
{
	sprites[(int)sid].SetTile(tileNum);
}

void GraphicEngine::LoadFonts()
{
	LoadFont("assets/ui/font.ttf");
}

void GraphicEngine::LoadFont(const char* path)
{
	if (_fontsCount < MAX_FONTS)
	{
		if (fonts[_fontsCount].loadFromFile(path))
			++_fontsCount;
		else
			printf("Couldn't load font: %s", path);
	}
	else
	{
		printf("No more fonts slots available, increase the capacity");
	}
}

void GraphicEngine::LoadTexture(GraphicID gid, const char* path)
{
	if (_texturesCount < MAX_TEXTURES)
	{
		if (textures[(int)gid].loadFromFile(path))
			++_texturesCount;
		else
			printf("Couldn't load texture: %s", path);
	}
	else
	{
		printf("No more textures slots available, increase the capacity");
	}
}

void GraphicEngine::LoadTextures()
{
	LoadTexture(GraphicID::IntroLogo, "assets/intro/arrowgance_logo_small.jpg");

	LoadTexture(GraphicID::MenuBackground, "assets/ui/MainMenu.jpg");
	LoadTexture(GraphicID::MenuBackgroundTest, "assets/ui/MainMenu1366x768.png");
	LoadTexture(GraphicID::MenuBackgroundClouds, "assets/ui/clouds.jpg");
	LoadTexture(GraphicID::GameMenuBackground, "assets/ui/GameMenu1366x768.png");

	LoadTexture(GraphicID::MenuButtonNewGame, "assets/ui/MainMenuButtonNewGame.png");
	LoadTexture(GraphicID::MenuButtonQuit, "assets/ui/MainMenuButtonQuit.png");
	LoadTexture(GraphicID::GameButtonEnterBattle, "assets/ui/GameMenuButtonEnterBattle.png");
	LoadTexture(GraphicID::GameButtonEnterShop, "assets/ui/GameMenuButtonEnterShop.png");
	LoadTexture(GraphicID::GameButtonGoBack, "assets/ui/GameMenuButtonGoBack.png");

	LoadTexture(GraphicID::TestColorAnim, "assets/test/colorAnim.png");
}

uint8 GraphicEngine::CreateSprite(GraphicID gid)
{
	sprites[_spritesCount].Init(textures[(int)gid]);
	return _spritesCount++;
}

uint8 GraphicEngine::CreateTileset(GraphicID gid, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles)
{
	sprites[_spritesCount].Init(textures[(int)gid], tileWidth, tileHeight, numOfTiles);
	return _spritesCount++;
}

void GraphicEngine::Reset()
{
	for (int i = 0; i < MAX_SPRITES; ++i)
	{
		sprites[i].sprite.setPosition({ 0, 0 }); //prolly to be removed since most of the objects set their 
												 //position to non-default one anyway
		sprites[i].sprite.setColor(sf::Color::White);
	}
	renderables.clear();
	_spritesCount = 0;

	for (int i = 0; i < _textsCount; ++i)
	{
		texts[i] = sf::Text();
	}
	_textsCount = 0;
}

void GraphicEngine::Init()
{
	textures = dataKeeper.GetTextureTable();
	sprites = dataKeeper.GetSpriteTable();
	fonts = dataKeeper.GetFontTable();
	texts = dataKeeper.GetTextTable();

	LoadTextures();
	LoadFonts();
}

void GraphicEngine::RenderScene()
{
	window.clear(sf::Color(255, 255, 255)); 
	for (auto& renderable : renderables)
	{
		window.draw(sprites[renderable.sid].sprite);
	}

	for (int i = 0; i < _textsCount; ++i)
	{
		window.draw(texts[i]);
	}

	window.display();
}

