#include "Block.h"

Block::Block()
{
	renewBlock();
}

Block::Block(BlockData BD) : Object(BD.OD), lineColor(BD.lineColor), width(BD.width), height(BD.height)
{	
	renewBlock();
}

Block::~Block()
{
}

void Block::moveBlock(Vector f)
{
	moveObject(f);
}

void Block::renewBlock()
{
	renewObject();
	p1 = { x - width / 2.0, y - height / 2.0 };
	p2 = { x + width / 2.0, y - height / 2.0 };
	p3 = { x + width / 2.0, y + height / 2.0 };
	p4 = { x - width / 2.0, y + height / 2.0 };
}

void Block::drawBlock()
{
	setfillcolor(mainColor);
	setlinecolor(lineColor);
	setlinestyle(PS_SOLID, 2);
	fillrectangle(p1[0], p1[1], p3[0], p3[1]);
	printData();
}

void Block::printData()
{
	std::string str = _T("Data：");
	str += "  ";
	str += "坐标：";
	str += std::to_string(x);
	str += ",";
	str += std::to_string(y);
	str += "  ";
	str += "速度：";
	str += std::to_string(v.mod);
	str += ",";
	str += std::to_string(v.angle / PI) + " * PI";
	str += "  ";
	str += "加速度：";
	str += std::to_string(a.mod);
	str += ",";
	str += std::to_string(a.angle / PI) + " * PI";
	str += "  ";
	str += "质量：";
	str += std::to_string(mass);
	
	settextcolor(0xaa0000);
	settextstyle(20, 0, _T("黑体"));
	setbkmode(TRANSPARENT);//设置文字背景透明
	outtextxy(x, y + 50, str.c_str());
}
