#include <cmath>
#include "Alien.h"
#include "Camera.h"
#include "InputManager.h"
#include "Rect.h"

using namespace std;

Alien::Alien(float x, float y, int nMinions) : sprite(Sprite("img/alien.png")) {
	box = new Rect(x, y, sprite.GetWidth(), sprite.GetHeight());
	hitPoints = 30;
	speed.x = 0;
	speed.y = 0;
}

Alien::~Alien() {
	while(!taskQueue.empty()) {
		taskQueue.pop();
	}
	delete box;
}

void Alien::Update(float dt) {
	InputManager & input = InputManager::GetInstance();
	float mouseX = (float)input.GetMouseX();
	float mouseY = (float)input.GetMouseY();

	if(input.MousePress(SDL_BUTTON_LEFT)) {
		Action action = Action(mouseX, mouseY, Action::ActionType::SHOOT);
		taskQueue.emplace(action);
	} else if(input.MousePress(SDL_BUTTON_RIGHT)) {
		Action action = Action(box->x, box->y, Action::ActionType::MOVE);
		taskQueue.emplace(action);
	}

	if(!taskQueue.empty()) {
		Action action = taskQueue.front();
		if(action.type == Action::ActionType::MOVE) {
			double deltaT = 200;
			speed.x = fabs(action.pos.x - mouseX) / deltaT;
			speed.y = fabs(action.pos.y - mouseY) / deltaT;

			const double EPS = 1e-9;
			if(fabs(box->x - mouseX) >= EPS && fabs(box->y - mouseY) >= EPS) {
				if(mouseX > box->x) {
					box->x += speed.x;
				} else {
					box->x -= speed.x;
				}

				if(mouseY > box->y) {
					box->y += speed.y;
				} else {
					box->y -= speed.y;
				}
			} else {
				taskQueue.pop();
			}
		} else if(action.type == Action::ActionType::SHOOT) {
			taskQueue.pop();
		}
	}

}

void Alien::Render() {
	sprite.Render(box->x + Camera::pos.x, box->y + Camera::pos.y);
	// for(int i = 0; i < minionArray.size(); i++) {
	// 	Minion * minion = (Minion*) minionArray[i].get();
	// 	minion->Render(); 
	// }
}

bool Alien::IsDead() {
	if (hitPoints <= 0) {
		return true;
	} else {
		return false;
	}
}