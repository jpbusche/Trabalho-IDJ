#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include "Vec2.h"
#include "Sprite.h" 

using namespace std;

class Bullet : public GameObject {
	public:
		Bullet(double x, double y, double angle, double speed, double maxDistance, string sprite_name);

		void Update(double dt = 0);
		void Render();
		bool IsDead();

	private:
		Sprite sprite;
		Vec2 bulletSpeed;
		double distanceLeft;
};

#endif