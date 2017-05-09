#include "Camera.h"
#include "Bullet.h"

using namespace std;

Bullet::Bullet(double x, double y, double angle, double speed, double maxDistance, string spriteName) {
	sprite = Sprite(spriteName);
	box = new Rect(x, y, sprite.GetWidth(), sprite.GetHeight());
	bulletSpeed = Vec2(cos(angle) * speed, sin(angle) * speed);
	distanceLeft = maxDistance;	
}

void Bullet::Update(double dt) {
	box->x -= bulletSpeed.GetX() * dt;
	box->y -= bulletSpeed.GetY() * dt;

	double dist = hypot(bulletSpeed.GetX(), bulletSpeed.GetY());

	distanceLeft -= dist;
}

void Bullet::Render() {
	sprite.Render(box->x + Camera::pos.x, box->y + Camera::pos.y);
}

bool Bullet::IsDead() {
	if(distanceLeft <= 0) {
		return true;
	} else {
		return false;
	}
}