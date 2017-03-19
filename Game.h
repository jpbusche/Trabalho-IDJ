#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "State.h"

using namespace std;

class Game {
	public:
		Game(string title, int width, int height);
		~Game();

		void run();
		SDL_Renderer * GetRenderer();
		State & GetState();
		Game & GetInstance();

	private:
		Game * instance;
		SDL_Window * window;
		SDL_Renderer * renderer;
		State * state;
}

#endif