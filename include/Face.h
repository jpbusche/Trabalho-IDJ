#ifndef FACE_H
#define FACE_H

using namespace std;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameObject.h"
#include "Sprite.h"

class Face : public GameObject {
	public:
		Face(float x, float y);
		void Damage(int damage);
		void Update(float dt = 0);
		void Render();
		bool IsDead();
	private:
		int hitPoints = 30;
		Sprite * sprite;
};

#endif