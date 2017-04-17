#ifndef CAMERA_H
#define CAMERA_H

#include "SDL2/SDL.h"
#include "GameObject.h"
#include "Vec2.h"

using namespace std;

class Camera {
	public:
		static void Follow(GameObject * newFocus);
		static void Unfollow();
		static void Update(float dt);

		static Vec2 pos;
		static Vec2 speed;

	private:
		static GameObject * focus;
};

#endif