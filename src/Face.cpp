#include "Camera.h"
#include "Face.h"
#include "InputManager.h"

Face::Face(float x, float y) : sprite(Sprite("img/penguinface.png")) {
	box = new Rect(x, y, sprite.GetWidth(), sprite.GetHeight());
} 

void Face::Damage(int damage) {
	hitPoints -= damage;
}

void Face::Update(float dt) {
	InputManager & input = InputManager::GetInstance();
	for(int i = 0; i < 6; i++) {
		if(input.MousePress(i)) {
			if(box->IsInside((float)input.GetMouseX(), (float)input.GetMouseY())) {
				Damage(rand() % 10 + 10);	
			}
		}
	}
}

void Face::Render() {
	sprite.Render(box->x + Camera::pos.x, box->y + Camera::pos.y);
}

bool Face::IsDead() {
	if (hitPoints <= 0) {
		return true;
	} else {
		return false;
	}
}