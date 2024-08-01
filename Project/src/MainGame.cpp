
#include "MainGame.h"

MainGame::MainGame()
{
    std::cout << "MainGame" << std::endl;
}

MainGame::~MainGame()
{
    std::cout << "~MainGame" << std::endl;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void MainGame::run()
{
    initGame();

    loopForTest();
    //loop();

    gamwOver();
}

void MainGame::initGame()
{
    std::cout << "ごめん、さよなら" << std::endl;

    initgraph(WINDOW_SIZE[0], WINDOW_SIZE[1], SHOWCONSOLE);

    char arr[] = "LOADING...";
    setText(arr, RED);

    initWorld();
    initWidgets();
}

void MainGame::gamwOver()
{
    char arr[] = "GAME OVER";
    setText(arr, BGR(IKACYANN_COLOR));

    char c = getchar();
	closegraph();

    saveBlockData(driver);

    delete wall;
    delete driver;
    delete cameraman;
}

void MainGame::loop()
{
    BeginBatchDraw();
    do
    {
        DWORD t1 = GetTickCount();

        getMessage();

        blockBox();

        setbkcolor(BACKGROUND_COLOR);
        clearcliprgn();

        wall->drawMap();

        driver->drawBlock();

        printer->printData();

        timer();

        FlushBatchDraw();

        DWORD t2 = GetTickCount();
        DWORD t = t2 - t1;
        if (t < 1000 / 144)
        {
            Sleep(1000 / 144 - t);
        }

    } 
    while (isGameEnd);
    EndBatchDraw();
}

void MainGame::loopForTest()
{
	BeginBatchDraw();
	do
	{
        DWORD t = GetTickCount();
        
        getMessage();

		blockBox();

        SetWorkingImage();
		setbkcolor(BLACK);
		clearcliprgn();

        SetWorkingImage(&world);
        setbkcolor(BACKGROUND_COLOR);
        clearcliprgn();
		wall->drawMap();
		driver->drawBlock();
        SetWorkingImage();

        cameraman->cameraFollow(driver->x, driver->y, mbox.mx, mbox.my);
        cameraman->see(&world);
        cameraman->show();

		timer();
        t = GetTickCount() - t;
        if (t < 1000 / 120) { Sleep(1000 / 120 - t); }
        FlushBatchDraw();
    }
    while (isGameEnd && !mbox.enter);
	EndBatchDraw();
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void MainGame::initWorld()
{
    getimage(&world, 0, 0, WORLD_SIZE[0], WORLD_SIZE[1]);
    SetWorkingImage(&world);

    setbkcolor(BACKGROUND_COLOR);
    clearcliprgn();

    mainMap = new Map(MAINMAP_DATACOLOR);
    mainMap->areaOR(0, 0, WORLD_SIZE[0], WORLD_SIZE[1]);

    wall = new Map(WALL_DATACOLOR, WALL_COLOR);
    wall->areaOR(0, 0, WORLD_SIZE[0], WORLD_SIZE[1]);
    wall->areaDIFF(40, 40, WORLD_SIZE[0] - 40, WORLD_SIZE[1] - 40);
    wall->areaOR(300, 300, 500, 400);
    wall->areaDIFF(350, 350, 400, 390);
    wall->areaOR(209, 96, 483, 252);
    wall->areaDIFF(400, 0, 470, 500);
    wall->areaOR(550, 140, 580, 800);
    wall->areaDIFF(330, 200, 420, 300);
    wall->areaOR(70, 500, 190, 580);
    wall->areaOR(getHRGN_());
    //wall->areaDIFF(0, 60, WORLD_SIZE[0], WORLD_SIZE[1] - 60);

    SetWorkingImage();
}

void MainGame::initWidgets()
{
    driver = new BlockDriver(loadBlockData());

    cameraman = new Cameraman();

    //printer = new DataPrinter(0, 0, 160, 90);
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void MainGame::getMessage()
{
    ExMessage msg;
    while (peekmessage(&msg)) { getMessageBox(mbox, msg); }
}

void MainGame::blockBox()
{
    SetWorkingImage(&world);

    mainMap->drawMapData();
    if (getpixel(driver->x, driver->y) != MAINMAP_DATACOLOR) { isGameEnd = false; }

    wall->drawMapData();

    driver->mbox = mbox;
    driver->renewDriver();
    driver->driveBlock();

    SetWorkingImage();
}

BlockData MainGame::loadBlockData()
{
    std::vector<double> data = loadData(data_path_1);
    BlockData BD;
    BD.OD.x = data[0];
    BD.OD.y = data[1];
    BD.width = data[2];
    BD.height = data[3];
    BD.OD.mainColor = int(data[4]);
    BD.lineColor = int(data[5]);
    return BD;
}

void MainGame::saveBlockData(BlockDriver* driver)
{
    std::vector<double> data = 
    {
        driver->x, 
        driver->y,
        driver->width, 
        driver->height,
        double(driver->mainColor), 
        double(driver->lineColor),
    };
    saveData(data_path_1, data);
}


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void MainGame::timer()
{
    if (timer_0 > 0) { timer_0--; }
    if (timer_1 > 0) { timer_1--; }
}
