#ifndef VEC2_H
#define VEC2_H

using namespace std;

class Vec2 {
	public:
		float x;
		float y;

		Vec2(float x, float y);

		float GetX();
		float GetY();
		Vec2 Translate(Vec2 vector, float x, float y);
		Vec2 Rotate(Vec2 vector, double angle);
		Vec2 Rotate(Vec2 vector, double angle, float x, float y);
};

#endif