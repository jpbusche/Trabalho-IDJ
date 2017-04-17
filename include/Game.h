#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "State.h"

using namespace std;

class Game {
	public:
		Game(string title, int width, int height);
		~Game();

		void run();
		float GetDeltaTime();
		SDL_Renderer * GetRenderer();
		State & GetState();
		static Game & GetInstance();

	private:
		void CalculateDeltaTime();

		int frameStart;
		float dt;
		static Game * instance;
		SDL_Window * window;
		SDL_Renderer * renderer;
		State * state;
};

#endif