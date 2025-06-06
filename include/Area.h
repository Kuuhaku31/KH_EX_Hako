
#pragma once

#include "tools.h"

class Area
{
public:
	HRGN area = CreateRectRgn(0, 0, 0, 0);

	Area();
	Area(HRGN area);
	~Area();

	//OR 并，AND 交，XOR 异或，DIFF 差，COPY 复制
	void areaAND(HRGN h);
	void areaOR(HRGN h);
	void areaXOR(HRGN h);
	void areaDIFF(HRGN h);
	void areaCOPY(HRGN h);

	void areaAND(int x1, int y1, int x2, int y2);
	void areaOR(int x1, int y1, int x2, int y2);
	void areaXOR(int x1, int y1, int x2, int y2);
	void areaDIFF(int x1, int y1, int x2, int y2);
	void areaCOPY(int x1, int y1, int x2, int y2);
};

