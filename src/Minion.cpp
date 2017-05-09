#include <cmath>
#include <cstdio>
#include "Minion.h"
#include "Rect.h"
#include "Camera.h"

using namespace std;

Minion::Minion(GameObject * minionCenter, double arcOffSet) : sprite(Sprite("img/minion.png")) {
	center = minionCenter;
	arc = arcOffSet;
	double posX = center->box->x + center->box->w / 2;
	double posY = center->box->y + center->box->h / 2; 
	box = new Rect(posX, posY, sprite.GetWidth(), sprite.GetHeight());
}

void Minion::Update(double dt) {
	const double PI = acos(-1);
	double speed = PI / 30;
	double posX = center->box->x + center->box->w / 2;
	double posY = center->box->y + center->box->h / 2; 

	Vec2 pos = Vec2(posX, posY);
	pos = pos.Translate(pos, center->box->w, 0);
	pos = pos.Rotate(pos, arc, posX, posY);

	box->x = pos.x - box->w / 2;
	box->y = pos.y - box->h / 2;

	arc += speed;
}

void Minion::Render() {
	sprite.Render(box->x + Camera::pos.x, box->y + Camera::pos.y);
}

void Minion::Shoot(Vec2 pos) {
	//TODO
}

bool Minion::IsDead() {
	return false;
}