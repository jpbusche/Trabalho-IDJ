#include "Camera.h"
#include "InputManager.h"
#include "Game.h"

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

void Camera::Update(double dt) {
	InputManager & input = InputManager::GetInstance();
	speed = Vec2(0, 0);
	if(focus) {
		pos.x = (SCREEN_WIDTH / 2) -focus->box->x;
		pos.y = (SCREEN_HEIGHT / 2) -focus->box->y;
	} else {
		if(input.IsKeyDown(LEFT_ARROW_KEY)) {
			speed.x = 1.0 / dt;
		} else if(input.IsKeyDown(RIGHT_ARROW_KEY)) {
			speed.x = - 1.0 / dt;
		} else if(input.IsKeyDown(DOWN_ARROW_KEY)) {
			speed.y = - 1.0 / dt;
		} else if(input.IsKeyDown(UP_ARROW_KEY)) {
			speed.y = 1.0 / dt;
		}
		pos.x += speed.GetX();
		pos.y += speed.GetY();
	}
	
}