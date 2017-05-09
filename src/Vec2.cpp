#include <cmath>
#include "Vec2.h"

using namespace std;

Vec2::Vec2() : x(0), y(0) {

}

Vec2::Vec2(double posX, double posY) : x(posX), y(posY) {

}

double Vec2::GetX() {
	return x;
}

double Vec2::GetY() {
	return y;
}

Vec2 Vec2::Rotate(Vec2 vector, double angle) {
	double newX = vector.GetX() * cos(angle) - vector.GetY() * sin(angle);
	double newY = vector.GetX() * sin(angle) + vector.GetY() * cos(angle);

	return Vec2(newX, newY);
}

Vec2 Vec2::Translate(Vec2 vector, double posX, double posY) {
	double newX = vector.GetX() + posX;
	double newY = vector.GetY() + posY;

	return Vec2(newX, newY);
}

Vec2 Vec2::Rotate(Vec2 vector, double angle, double posX, double posY) {
	Vec2 aux_vector = Translate(vector, -posX, -posY);
	aux_vector = Rotate(aux_vector, angle);
	aux_vector = Translate(aux_vector, posX, posY);

	return aux_vector;
}