#include "GraphicEngine.h"
#include "DataKeeper.h"

GraphicEngine::GraphicEngine(sf::RenderWindow & window, DataKeeper& dataKeeper)
	: window(window), dataKeeper(dataKeeper), _spritesCount(0)
{
	textures = dataKeeper.GetTextureTable();
	sprites = dataKeeper.GetSpriteTable();
	LoadTextures();
}

void GraphicEngine::LoadTextures()
{
	LoadTexture(GraphicID::MenuBackground,			 "assets/ui/MainMenu.jpg");
	LoadTexture(GraphicID::MenuButtonNewGameStatic,  "assets/ui/MainMenuButtonNewGameStatic.png");
	LoadTexture(GraphicID::MenuButtonNewGameHovered, "assets/ui/MainMenuButtonNewGameHover.png");
	LoadTexture(GraphicID::MenuButtonNewGamePressed, "assets/ui/MainMenuButtonNewGamePressed.png");
	LoadTexture(GraphicID::MenuButtonQuitStatic,     "assets/ui/MainMenuButtonQuitStatic.png");
	LoadTexture(GraphicID::MenuButtonQuitHovered,	 "assets/ui/MainMenuButtonQuitHover.png");
	LoadTexture(GraphicID::MenuButtonQuitPressed,	 "assets/ui/MainMenuButtonQuitPressed.png");
}

uint8 GraphicEngine::RequestSprite(GraphicID gid, uint8 depth)
{
	uint8 sid = CreateSprite(gid);
	renderables.insert(Renderable{ sid, depth });
	return sid;
}

void GraphicEngine::LoadTexture(GraphicID gid, const char* path)
{
	if (_texturesCount < MAX_TEXTURES)
	{
		textures[(int)gid].loadFromFile(path);
		++_texturesCount;
	}
	else
	{
		//TODO: log error that we have exceeded amount of textures to be loaded
	}
}

uint8 GraphicEngine::CreateSprite(GraphicID gid)
{
	sprites[_spritesCount].setTexture(textures[(int)gid]);
	return _spritesCount++;
}

void GraphicEngine::RenderScene()
{
	window.clear(sf::Color(255, 0, 255)); 
	for (auto& renderable : renderables)
	{
		window.draw(sprites[renderable.sid]);
	}

	window.display();
}
