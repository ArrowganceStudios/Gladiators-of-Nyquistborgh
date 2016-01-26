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
	sf::Sprite* sprite = GetSpriteTable();
	for (uint8 i = 0; i < MAX_SPRITES; ++i)
	{
		sprite = new (sprite) sf::Sprite();
		sprite++;
	}
	sf::Texture* texture = GetTextureTable();
	for (uint8 i = 0; i < MAX_TEXTURES; ++i)
	{
		texture = new (texture) sf::Texture();
		texture++;
	}
	Intro *intro = GetIntro();
	intro = new (intro) Intro(evtSystem, grphEngine);
	MainMenu *mm = GetMainMenu();
	mm = new (mm) MainMenu(evtSystem, grphEngine);
	GameMenu *gm = GetGameMenu();
	gm = new (gm) GameMenu(evtSystem, grphEngine);

}
