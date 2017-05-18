#include <algorithm>
#include "Penguins.h"
#include "Camera.h"
#include "InputManager.h"
#include "State.h"
#include "Game.h"
#include "Bullet.h"

using namespace std;

Penguins * Penguins::player = nullptr;

Penguins::Penguins(double x, double y) {
	bodySprite = Sprite("img/penguin.png");
	cannonSprite = Sprite("img/cubngun.png");
	box = new Rect(x, y, bodySprite.GetWidth(), bodySprite.GetHeight());
	speed = Vec2(0, 0);
	linearSpeed = 0;
	cannonAngle = 0;
	hp = 5;
	player = this;
}

Penguins::~Penguins() {
	player = nullptr;
}

void Penguins::Update(double dt) {
	const double PI = acos(-1) / 180.0;
	double speedLimit = 300;
	double acceleration = 10;
	double angle = 30.0;
	InputManager & input = InputManager::GetInstance();
	if(input.IsKeyDown(W_KEY)) {
		linearSpeed = min((linearSpeed + acceleration), speedLimit);
	} else if(input.IsKeyDown(S_KEY)) {
		linearSpeed = max((linearSpeed - acceleration), -speedLimit);
	}
	if(input.IsKeyDown(D_KEY)) {
		rotation += (angle * dt);
	} else if(input.IsKeyDown(A_KEY)) {
		rotation -= (angle * dt);
	}
	speed.x = linearSpeed * cos(rotation * PI);
	speed.y = linearSpeed * sin(rotation * PI);

	box->x += speed.x * dt;
	box->y += speed.y * dt;

	int mouseX = input.GetMouseX();
	int mouseY = input.GetMouseY();
	cannonAngle = atan2(mouseY - box->y, mouseX - box->x);

	if(input.MousePress(LEFT_MOUSE_BUTTON)) {
		Shoot();
	}

}

void Penguins::Render() {
	cannonAngle = cannonAngle * 180 / acos(-1);
	bodySprite.Render(box->x + Camera::pos.x, box->y + Camera::pos.y, rotation);
	double cannonX = box->x + abs(cannonSprite.GetWidth() - bodySprite.GetWidth()) / 2.0;
	double cannonY = box->y + abs(bodySprite.GetHeight() - cannonSprite.GetHeight()) / 2.0;
	cannonSprite.Render(cannonX + Camera::pos.x, cannonY + Camera::pos.y, cannonAngle);
}

void Penguins::Shoot() {
	double speed = 100;
	double maxDistance = 16000;

	double middleX = box->x + box->w / 2;
	double middleY = box->y + box->h / 2;

	Vec2 bullet;
	bullet.Transform(cannonSprite.GetWidth() / 2.0, cannonAngle);

	Bullet * penguinBullet = new Bullet(middleX + bullet.GetX(), middleY + bullet.GetY(), cannonAngle + acos(-1), speed, maxDistance, "img/penguinbullet.png", 4, 1.0/10.0);

	State * state = Game::GetInstance().GetState();
	state->AddObject(penguinBullet);
}

bool Penguins::IsDead() {
	if (hp <= 0) {
		return true;
	} else {
		return false;
	}
}