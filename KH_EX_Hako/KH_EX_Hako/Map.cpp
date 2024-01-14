
#include "Map.h"

Map::Map(int dataColor)
{
	this->dataColor = dataColor;
	this->color = dataColor;
}

Map::Map(int dataColor, int color)
{
	this->dataColor = dataColor;
	this->color = color;
}

Map::Map(int dataColor, HRGN area)
{
	this->dataColor = dataColor;
	this->color = dataColor;
	this->area = area;
}

Map::Map(int dataColor, int color, HRGN area)
{
	this->dataColor = dataColor;
	this->color = color;
	this->area = area;
}

Map::~Map()
{
}

void Map::addMap(HRGN h)
{
	areaOR(h);
}

void Map::delMap(HRGN h)
{
	areaDIFF(h);
}

void Map::addMap(int x1, int y1, int x2, int y2)
{
	areaOR(x1, y1, x2, y2);
}

void Map::delMap(int x1, int y1, int x2, int y2)
{
	areaDIFF(x1, y1, x2, y2);
}

void Map::drawMap(int color)
{
	setcliprgn(area);
	setbkcolor(color);
	clearcliprgn();
	setcliprgn(NULL);
}

void Map::drawMap()
{
	drawMap(color);
}

void Map::drawMapData()
{
	drawMap(dataColor);
}
