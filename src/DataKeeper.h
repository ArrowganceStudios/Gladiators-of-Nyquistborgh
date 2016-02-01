#pragma once

//#include "Player.h"
//#include "Enemy.h"
#include "SFML\Audio.hpp"
#include "Tileset.h"
#include "ForwardDeclarations.h"
#include "Intro.h"
#include "MainMenu.h"
#include "GameMenu.h"
#include "Constants.h"

class DataKeeper
{
public:
	DataKeeper();
	~DataKeeper();

	DataKeeper(DataKeeper const&) = delete;
	DataKeeper& operator=(DataKeeper const&) = delete;

	void InitData(EventSystem &evtSystem, GraphicEngine &grphEngine);

	Tileset *GetSpriteTable() { return GameData->sprites; }
	sf::Texture *GetTextureTable() { return GameData->textures; }
	sf::Sound *GetSoundTable() { return GameData->sounds; }
	Intro *GetIntro() { return &(GameData->intro); }
	MainMenu *GetMainMenu() { return &(GameData->mainMenu); }
	GameMenu *GetGameMenu() { return &(GameData->gameMenu); }

private:
	struct Data
	{
		Tileset sprites[MAX_SPRITES];
		//sf::Sprite sprites[MAX_SPRITES];  //	TODO: Check frequency of accesses by sprites
		sf::Texture textures[MAX_TEXTURES];	//edit: it's high but since sf::sprite uses
											//pointer to texture we can't optimize it anyway
		sf::Sound sounds[MAX_SOUNDS];
		Intro intro;
		MainMenu mainMenu;
		GameMenu gameMenu;
	} *GameData;

	void* memory;
};