
#include "MainGame.h"

int main()
{
	MainGame* game = new MainGame();
	game->run();
	delete game;

	/*initgraph(WINDOW_SIZE[0], WINDOW_SIZE[1], SHOWCONSOLE);
	saveMap();*/

	return 0;
}
