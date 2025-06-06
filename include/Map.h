
#pragma once

#include "Area.h"

class Map: public Area
{
public:
	int dataColor = 0x000000;
	int color = 0x000000;

	Map(int dataColor);
	Map(int dataColor, int color);
	Map(int dataColor, HRGN area);
	Map(int dataColor, int color, HRGN area);
	~Map();

	void addMap(HRGN h);
	void delMap(HRGN h);

	void addMap(int x1, int y1, int x2, int y2);
	void delMap(int x1, int y1, int x2, int y2);

	void drawMap(int color);
	void drawMap();
	void drawMapData();
};
