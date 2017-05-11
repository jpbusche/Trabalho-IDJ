#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

using namespace std;

#include "Rect.h"

class GameObject {
	public:
		Rect * box;
		double rotation;

		virtual ~GameObject() = default;
		virtual void Update(double dt) = 0;
		virtual void Render() = 0;
		virtual bool IsDead() = 0;
};

#endif