#ifndef ALIEN_H
#define ALIEN_H

#include <vector>
#include <queue>
#include "Vec2.h"
#include "Sprite.h"
#include "Minion.h"
#include "GameObject.h"

using namespace std;

class Alien : public GameObject{
	public:
		Alien(float x, float y, int nMinions);
		~Alien();

		void Update(float dt);
		void Render();
		bool IsDead();

	private:
		class Action {
			public:
				enum ActionType {
					MOVE,
					SHOOT
				};
				
				Action(float x, float y, ActionType type) {
					pos = Vec2(x, y);
					this->type = type;
				};

				ActionType type;
				Vec2 pos;
		};

		Sprite sprite;
		Vec2 speed;
		Vec2 move;
		int hitPoints;
		queue<Action> taskQueue;
		vector<Minion> minionArray;
};

#endif