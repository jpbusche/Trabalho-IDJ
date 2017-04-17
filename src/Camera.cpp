#include "Camera.h"
#include "InputManager.h"

using namespace std;

GameObject * Camera::focus;
Vec2 Camera::pos;
Vec2 Camera::speed;

void Camera::Follow(GameObject * newFocus) {
	focus = newFocus;
}

void Camera::Unfollow() {
	focus = nullptr;
}

void Camera::Update(float dt) {
	InputManager & input = InputManager::GetInstance();
	speed.x = 0;
	speed.y = 0;
	if(focus) {
	} else {
		if(input.IsKeyDown(SDLK_RIGHT)) {
			speed.x = 1.0 / dt;
		} else if(input.IsKeyDown(SDLK_LEFT)) {
			speed.x = - 1.0 / dt;
		} else if(input.IsKeyDown(SDLK_UP)) {
			speed.y = - 1.0 / dt;
		} else if(input.IsKeyDown(SDLK_DOWN)) {
			speed.y = 1.0 / dt;
		}
	}
	pos.x += speed.x;
	pos.y += speed.y;
}
