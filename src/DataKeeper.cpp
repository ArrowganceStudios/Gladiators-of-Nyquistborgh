#include <Windows.h>
#include "DataKeeper.h"

DataKeeper::DataKeeper()
{
	const LPVOID baseAddress = (LPVOID)1073741824;
	memory = VirtualAlloc(baseAddress, sizeof(Data), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	//memory = calloc(1, sizeof(Data));

	GameData = (Data*)memory;
	
}
DataKeeper::~DataKeeper() 
{ 
	VirtualFree(memory, sizeof(Data), MEM_RELEASE);
	//free(memory);
}
void DataKeeper::InitData(EventSystem & evtSystem, GraphicEngine & grphEngine)
{
	Tileset* sprite = GetSpriteTable();
	for (uint8 i = 0; i < MAX_SPRITES; ++i)
	{
		sprite = new (sprite) Tileset();
		sprite++;
	}
	sf::Texture* texture = GetTextureTable();
	for (uint8 i = 0; i < MAX_TEXTURES; ++i)
	{
		texture = new (texture) sf::Texture();
		texture++;
	}
	sf::Text* text = GetTextTable();
	for (uint8 i = 0; i < MAX_TEXTS; ++i)
	{
		text = new (text) sf::Text();
		text++;
	}
	sf::Font* font = GetFontTable();
	for (uint8 i = 0; i < MAX_FONTS; ++i)
	{
		font = new (font) sf::Font();
		font++;
	}

	Intro *intro = GetIntro();
	intro = new (intro) Intro(evtSystem, grphEngine);
	MainMenu *mm = GetMainMenu();
	mm = new (mm) MainMenu(evtSystem, grphEngine);
	GameMenu *gm = GetGameMenu();
	gm = new (gm) GameMenu(evtSystem, grphEngine);
}
