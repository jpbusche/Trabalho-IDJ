#include "Face.h"

Face::Face(float x, float y) {
	sprite = new Sprite("img/peguinface.png");
	box = new Rect(x, y, sprite->GetWidth(), sprite->GetHeight());
} 

void Face::Damage(int damage) {
	hitPoints -= damage;
}

void Face::Update(float dt) {

}

void Face::Render() {
	sprite->Render(box->x, box->	y);
}

bool Face::IsDead() {
	if (hitPoints == 0) {
		return true;
	} else {
		return false;
	}
}