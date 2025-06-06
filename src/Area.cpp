
#include "Area.h"

Area::Area()
{
}

Area::Area(HRGN area) : area(area)
{
}

Area::~Area()
{
	DeleteObject(area);
}

void Area::areaAND(HRGN h)
{
	CombineRgn(area, area, h, RGN_AND);
}

void Area::areaOR(HRGN h)
{
	CombineRgn(area, area, h, RGN_OR);
}

void Area::areaXOR(HRGN h)
{
	CombineRgn(area, area, h, RGN_XOR);
}

void Area::areaDIFF(HRGN h)
{
	CombineRgn(area, area, h, RGN_DIFF);
}

void Area::areaCOPY(HRGN h)
{
	CombineRgn(area, area, h, RGN_COPY);
}

void Area::areaAND(int x1, int y1, int x2, int y2)
{
	HRGN h = CreateRectRgn(x1, y1, x2, y2);
	CombineRgn(area, area, h, RGN_AND);
	DeleteObject(h);
}

void Area::areaOR(int x1, int y1, int x2, int y2)
{
	HRGN h = CreateRectRgn(x1, y1, x2, y2);
	CombineRgn(area, area, h, RGN_OR);
	DeleteObject(h);
}

void Area::areaXOR(int x1, int y1, int x2, int y2)
{
	HRGN h = CreateRectRgn(x1, y1, x2, y2);
	CombineRgn(area, area, h, RGN_XOR);
	DeleteObject(h);
}

void Area::areaDIFF(int x1, int y1, int x2, int y2)
{
	HRGN h = CreateRectRgn(x1, y1, x2, y2);
	CombineRgn(area, area, h, RGN_DIFF);
	DeleteObject(h);
}

void Area::areaCOPY(int x1, int y1, int x2, int y2)
{
	HRGN h = CreateRectRgn(x1, y1, x2, y2);
	CombineRgn(area, area, h, RGN_COPY);
	DeleteObject(h);
}
