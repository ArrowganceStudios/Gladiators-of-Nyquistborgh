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
	sf::Text *GetTextTable() { return GameData->texts; }
	sf::Font *GetFontTable() { return GameData->fonts; }
	Intro *GetIntro() { return &(GameData->intro); }
	MainMenu *GetMainMenu() { return &(GameData->mainMenu); }
	GameMenu *GetGameMenu() { return &(GameData->gameMenu); }

private:
	struct Data
	{
		Tileset sprites[MAX_SPRITES];
		sf::Texture textures[MAX_TEXTURES];
		sf::Sound sounds[MAX_SOUNDS];
		sf::Text texts[MAX_TEXTS];
		sf::Font fonts[MAX_FONTS];
		Intro intro;
		MainMenu mainMenu;
		GameMenu gameMenu;
	} *GameData;

	void* memory;
};