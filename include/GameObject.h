#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

using namespace std;

#include "Rect.h"

class GameObject {
	public:
		Rect * box;

		virtual ~GameObject() = default;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
		virtual bool IsDead() = 0;
};

#endif