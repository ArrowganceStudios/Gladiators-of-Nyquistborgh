#include "Tileset.h"

void Tileset::Init(const sf::Texture &texture, uint16 tileWidth, uint16 tileHeight, uint8 numOfTiles)
{
	this->sprite.setTexture(texture, true);
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;

	uint16 texWidth = texture.getSize().x;
	uint16 texHeight = texture.getSize().y;

	this->numTilesX = texWidth / tileWidth;
	this->numTilesY = texHeight / tileHeight;

	uint16 realNumOfTiles = numTilesX * numTilesY;

	if (!realNumOfTiles)
	{
		this->tileWidth = texWidth;
		this->tileHeight = texHeight;
	}
	if (numOfTiles > realNumOfTiles)	this->numOfTiles = realNumOfTiles;
	else this->numOfTiles = numOfTiles;

	this->sprite.setTextureRect({ 0, 0, this->tileWidth, this->tileHeight });
	
	initialized = true;

}

void Tileset::Init(const sf::Texture & texture)
{
	sprite.setTexture(texture, true);
	this->numTilesX = 1;
	this->numTilesY = 1;
	this->tileWidth = texture.getSize().x;
	this->tileHeight = texture.getSize().y;
	this->numOfTiles = 1;

	initialized = true;
}

void Tileset::SetTile(uint16 tileNum)
{
	if (tileNum > numOfTiles) tileNum = 0;
	int x = tileNum % numTilesX;
	int y = tileNum / numTilesX;
	sprite.setTextureRect({ x * tileWidth, y * tileHeight, tileWidth, tileHeight });
}
