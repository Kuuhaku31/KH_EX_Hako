
#pragma once

#include "tools.h"

#include "Library.h"

#include "DataPrinter.h"

#include "Map.h"
#include "BlockDriver.h"
#include "Cameraman.h"

class MainGame
{
private:
	IMAGE world = NULL;
	Map* mainMap = nullptr;
	Map* wall = nullptr;
	BlockDriver* driver = nullptr;
	Cameraman* cameraman = nullptr;

	DataPrinter* printer = nullptr;

	BaseMessageBox mbox;

	int timer_0 = 0;
	int timer_1 = 0;

	bool isGameEnd = true;

public:
	MainGame();
	~MainGame();

	void run();

	void initGame();//初始化游戏
	void gamwOver();
	void loop();//循环
	void loopForTest();

	void initWorld();
	void initWidgets();

	void getMessage();
	void blockBox();

	BlockData loadBlockData();
	void saveBlockData(BlockDriver* driver);

	void timer();//计时器
};

