#ifndef VEC2_H
#define VEC2_H

using namespace std;

class Vec2 {
	public:
		double x;
		double y;

		Vec2();
		Vec2(double x, double y);

		double GetX();
		double GetY();
		Vec2 Translate(Vec2 vector, double x, double y);
		Vec2 Rotate(Vec2 vector, double angle);
		Vec2 Rotate(Vec2 vector, double angle, double x, double y);
		void Transform(double module, double angle);
};

#endif