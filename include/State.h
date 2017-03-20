#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>
#include "Sprite.h"

using namespace std;

class State {
	public:
		State();

		bool QuitRequested();
		void LoadAssets();
		void Update(float dt = 0);
		void Render();
		
	private:
		Sprite * background;
		bool quitRequest;
};

#endif