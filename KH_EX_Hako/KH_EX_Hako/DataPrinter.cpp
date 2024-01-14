#include "DataPrinter.h"

DataPrinter::DataPrinter() : Moniter(0, 0, 160, 90)
{
}

DataPrinter::DataPrinter(int x, int y, int width, int height) : Moniter(x, y, width, height)
{
}

DataPrinter::~DataPrinter()
{
}

void DataPrinter::printData()
{
	printData(x, y, width, height);
}

void DataPrinter::printData(int x, int y)
{
	printData(x, y, width, height);
}

void DataPrinter::printData(int x, int y, int width, int height)
{
	int d = 3;

	areaDIFF(area);
	areaOR(x, y, x + width, y + height);

	HRGN h = CreateRectRgn(x + d, y + d, x + width - d, y + height - d);
	CombineRgn(h, area, h, RGN_DIFF);
	setcliprgn(h);
	setbkcolor(GREEN);
	clearcliprgn();
	DeleteObject(h);

	setcliprgn(area);
	setbkmode(TRANSPARENT);
	settextcolor(BLUE);
	for (int i = 0; i < dataName.size(); i++)
	{
		std::string str = dataName[i] + " : " + data[i];
		outtextxy(x + 10, y + 10 + 20 * i, str.c_str());
	}
	setcliprgn(NULL);
}
