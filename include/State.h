#ifndef STATE_H
#define STATE_H

#include <memory>
#include <vector>
#include "SDL2/SDL.h"
#include "GameObject.h"
#include "Sprite.h"
#include "TileMap.h"
#include "GameObject.h"

using namespace std;

class State {
	public:
		State();
		~State();

		bool QuitRequested();
		void LoadAssets();
		void Update(double dt = 0);
		void Render();
		void Input();
		void AddObject(GameObject * object);
		
	private:
		TileSet * tileSet;
		TileMap * tileMap;
		Sprite * background;
		bool quitRequest;
		vector <unique_ptr <GameObject>> objectArray;
};

#endif