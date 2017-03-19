#include "Game.h"

using namespace std;


int main(int argc, char ** argv) {
	int width = 1024;
	int height = 600;
	Game * game = new Game("Joao Paulo Busche - 14/0023348", width, height);
	game.run();
	return 0;
}