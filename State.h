#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>
#include "Sprite.h"

using namespace std;

class State {
	public:
		State();

		bool QuitRequest();
		void LoadAssets();
		void Update();
		void Render();
		
	private:
		Sprite background;
		bool quitRequest;
}

#endif