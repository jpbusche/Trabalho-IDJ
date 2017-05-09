#include "Camera.h"
#include "Bullet.h"

using namespace std;

Bullet::Bullet(float x, float y, float angle, float speed, float maxDistance, string sprite_name) {
	sprite = Sprite(sprite_name);
	box = new Rect(x, y, sprite.GetWidth(), sprite.GetHeight());
	speed.x = cos(angle) * speed;
	speed.y = sin(angle) * speed;
	distanceLeft = maxDistance;	
}

void Bullet::Update(float dt) {
	box->x -= speed.GetX() * dt;
	box->y -= speed.GetY() * dt;

	float dist = hypot(speed.GetX(), speed.GetY());

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