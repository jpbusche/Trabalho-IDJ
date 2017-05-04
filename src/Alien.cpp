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
	minionArray.clear();
}

void Alien::Update(float dt) {
	InputManager & input = InputManager::GetInstance();
	if(input.MousePress(SDL_BUTTON_LEFT)) {
		Action action = new Action((float)input.GetMouseX(), (float)input.GetMouseY(), Action::ActionType::SHOOT);
		taskQueue.emplace(action);
	} else if(input.MousePress(SDL_BUTTON_RIGHT)) {
		Action action = new Action((float)input.GetMouseX(), (float)input.GetMouseY(), Action::ActionType::MOVE);
		taskQueue.emplace(action);
	}

	if(!taskQueue.empty()) {
		Action action = taskQueue.front();
		if(action.type == Action::ActionType::MOVE) {
			taskQueue.pop();
		} else if(action.type == Action::ActionType::SHOOT) {
			taskQueue.pop();
		}
	}

}

void Alien::Render() {
	sprite.Render(box->x + Camera::pos.x, box->y + Camera::pos.y);
	for(int i = 0; i < minionArray.size(); i++) {
		Minion * minion = (Minion*) minionArray[i].get();
		minion->Render(); 
	}
}

bool Alien::IsDead() {
	if (hitPoints <= 0) {
		return true;
	} else {
		return false;
	}
}