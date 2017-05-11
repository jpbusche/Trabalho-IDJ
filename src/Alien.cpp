#include <cmath>
#include "Alien.h"
#include "Camera.h"
#include "InputManager.h"
#include "Rect.h"

using namespace std;

Alien::Alien(double x, double y, int nMinions,double alienRotation) : sprite(Sprite("img/alien.png")) {
	rotation = alienRotation;
	box = new Rect(x, y, sprite.GetWidth(), sprite.GetHeight());
	hitPoints = 30;
	speed = Vec2(0, 0);
	move = Vec2(0, 0);

	double arc = 0;
	for(int i = 0; i < nMinions; i++) {
		arc 	= i * ( 360 / nMinions);
		minionArray.emplace_back(Minion(this, arc, arc));
	}
}

Alien::~Alien() {
	while(!taskQueue.empty()) {
		taskQueue.pop();
	}
	delete box;
}

void Alien::Update(double dt) {
	
	rotation -= 0.5;
	if(rotation < 0) {
		rotation += 360;		
	}

	InputManager & input = InputManager::GetInstance();
	double mouseX = (double)input.GetMouseX();
	double mouseY = (double)input.GetMouseY();

	if(input.MousePress(SDL_BUTTON_LEFT)) {
		Action action = Action(mouseX, mouseY, Action::ActionType::SHOOT);
		taskQueue.emplace(action);
	} else if(input.MousePress(SDL_BUTTON_RIGHT)) {
		move.x = mouseX;
		move.y = mouseY;
		Action action = Action(box->x, box->y, Action::ActionType::MOVE);
		taskQueue.emplace(action);
	}

	if(!taskQueue.empty()) {
		Action action = taskQueue.front();
		if(action.type == Action::ActionType::MOVE) {
			double deltaT = 100;
			speed.x = fabs(action.pos.x - move.x) / deltaT;
			speed.y = fabs(action.pos.y - move.y) / deltaT;

			const double EPS = 4;
			if(fabs(box->x - move.x) >= EPS && fabs(box->y - move.y) >= EPS) {
				if(move.x > box->x) {
					box->x += speed.x;
				} else {
					box->x -= speed.x;
				}

				if(move.y > box->y) {
					box->y += speed.y;
				} else {
					box->y -= speed.y;
				}
			} else {
				taskQueue.pop();
			}
		} else if(action.type == Action::ActionType::SHOOT) {
			double minDist = 1e9;
			int minionIndex = 0;
			for(int i = 0; i < minionArray.size(); i++) {
				Minion minion = minionArray[i];
				double dist = hypot(minion.box->x - action.pos.x, minion.box->y - action.pos.y);
				if(dist < minDist) {
					minionIndex = i;
					minDist = dist;
				}
			}

			Minion minion = minionArray[minionIndex];
			minion.Shoot(action.pos);
			taskQueue.pop();
		}
	}

	for(auto &minion : minionArray) {
		minion.Update(dt); 
	}

}

void Alien::Render() {
	sprite.Render(box->x + Camera::pos.x, box->y + Camera::pos.y, rotation);
	for(auto &minion : minionArray) {
		minion.Render(); 
	}
}

bool Alien::IsDead() {
	if (hitPoints <= 0) {
		return true;
	} else {
		return false;
	}
}