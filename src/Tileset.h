#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "BaseTypes.h"

class Tileset
{
public:
	Tileset() : initialized(false) {}
	sf::Sprite sprite;
	void Init(const sf::Texture &texture, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles);
	void Init(const sf::Texture &texture);
	void SetTile(uint16 tileNum);
	bool Initialized() { return initialized; }
private:
	bool initialized;
	uint8 numTilesX, numTilesY;	//	numTilesY may be unused in the future
	uint16 tileWidth, tileHeight;
	uint16 numOfTiles;
};