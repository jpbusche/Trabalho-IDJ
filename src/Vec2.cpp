#include <cmath>
#include "Vec2.h"

using namespace std;

Vec2::Vec2(float posX, float posY) : x(posX), y(posY) {

}

float Vec2::GetX() {
	return x;
}

float Vec2::GetY() {
	return y;
}

Vec2 Vec2::Rotate(Vec2 vector, double angle) {
	float newX = vector.GetX() * cos(angle) - vector.GetY() * sin(angle);
	float newY = vector.GetX() * sin(angle) + vector.GetY() * cos(angle);

	return Vec2(newX, newY);
}

Vec2 Vec2::Translate(Vec2 vector, float posX, float posY) {
	float newX = vector.GetX() + posX;
	float newY = vector.GetY() + posY;

	return Vec2(newX, newY);
}

Vec2 Vec2::Rotate(Vec2 vector, double angle, float posX, float posY) {
	Vec2 aux_vector = Translate(vector, -posX, -posY);
	aux_vector = Rotate(aux_vector, angle);
	aux_vector = Translate(aux_vector, posX, posY);

	return aux_vector;
}