#pragma once

//#include "Player.h"
//#include "Enemy.h"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "ForwardDeclarations.h"
//#include "Core.h"
#include "MainMenu.h"
#include "GameMenu.h"

#define MAX_TEXTURES 16
#define MAX_SPRITES 16
#define MAX_SOUNDS 16

class DataKeeper
{
public:
	DataKeeper();
	~DataKeeper();

	void InitData(EventSystem &evtSystem, GraphicEngine &grphEngine);

	sf::Sprite *GetSpriteTable() { return GameData->sprites; }
	sf::Texture *GetTextureTable() { return GameData->textures; }
	sf::Sound *GetSoundTable() { return GameData->sounds; }
	MainMenu *GetMainMenu() { return &(GameData->mainMenu); }
	GameMenu *GetGameMenu() { return &(GameData->gameMenu); }

private:
	struct Data
	{
		sf::Sprite sprites[MAX_SPRITES];
		sf::Texture textures[MAX_TEXTURES];	//	TODO: Check frequency of accesses by sprites
		sf::Sound sounds[MAX_SOUNDS];
		MainMenu mainMenu;
		GameMenu gameMenu;
	} *GameData;

	void* memory;
};