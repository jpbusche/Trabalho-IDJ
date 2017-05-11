#include <cmath>
#include <cstdio>
#include "Minion.h"
#include "Bullet.h"
#include "State.h"
#include "Game.h"
#include "Camera.h"
#include "InputManager.h"

using namespace std;

Minion::Minion(GameObject * minionCenter, double arcOffSet, double minionRotation) : sprite(Sprite("img/minion.png")) {
	rotation = minionRotation;
	center = minionCenter;
	arc = arcOffSet;
	double posX = center->box->x + center->box->w / 2;
	double posY = center->box->y + center->box->h / 2; 
	box = new Rect(posX, posY, sprite.GetWidth(), sprite.GetHeight());

	double randomScale = 1.0 + float(rand()) / float((RAND_MAX)/(0.5));
	sprite.SetScaleX(randomScale);
	sprite.SetScaleY(randomScale);
}

void Minion::Update(double dt) {
	const double PI = acos(-1) / 180.0;
	double posX = center->box->x + center->box->w / 2;
	double posY = center->box->y + center->box->h / 2; 

	arc += 100 * dt;
	if(arc > 360) {
		arc = 0;
	}
	double angle = arc * PI;
	rotation = arc;

	Vec2 pos = Vec2(posX, posY);
	pos = pos.Translate(pos, center->box->w, 0);
	pos = pos.Rotate(pos, angle, posX, posY);

	box->x = pos.x - box->w / 2;
	box->y = pos.y - box->h / 2;
}

void Minion::Render() {
	sprite.Render(box->x + Camera::pos.GetX(), box->y + Camera::pos.GetY(), rotation);
}

void Minion::Shoot(Vec2 pos) {
	InputManager & input = InputManager::GetInstance();
	double angle = atan2(box->y - pos.y, box->x - pos.x);
	double speed = 200;
	double maxDistance = 16000;

	Bullet * minionBullet = new Bullet(box->x, box->y, angle, speed, maxDistance, "img/minionbullet1.png");

	State * state = Game::GetInstance().GetState();
	state->AddObject(minionBullet);
}

bool Minion::IsDead() {
	return false;
}