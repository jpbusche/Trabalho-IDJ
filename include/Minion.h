#ifndef MINION_H
#define MINION_H

#include "Vec2.h"
#include "Sprite.h"
#include "GameObject.h"

using namespace std;

class Minion : public GameObject {
	public:
		Minion(GameObject * minionCenter, double arcOffSet = 0);

		void Update(double dt = 0);
		void Render();
		void Shoot(Vec2 pos);
		bool IsDead();

	private:
		GameObject * center;
		Sprite sprite;
		double arc;
};

#endif