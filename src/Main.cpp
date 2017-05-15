#include "Game.h"

using namespace std;

int main(int argc, char ** argv) {
	Game * game = new Game("Joao Paulo Busche - 14/0023348", SCREEN_WIDTH, SCREEN_HEIGHT);
	game->run();
	delete game;
	return 0;
}