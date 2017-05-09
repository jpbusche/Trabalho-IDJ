#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include "Vec2.h"
#include "Sprite.h" 

using namespace std;

class Bullet : public GameObject {
	public:
		Bullet(float x, float y, float angle, float speed, float maxDistance, string sprite_name);

		void Update(float dt = 0);
		void Render();
		bool IsDead();

	private:
		Sprite sprite;
		Vec2 speed;
		float distanceLeft;
};

#endif