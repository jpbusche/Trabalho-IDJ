#include "State.h"

using namespace std;

State::State() {
	quitRequest = false;
	background = new Sprite();
}

void State::LoadAssets() {
	background->Open("img/ocean.jpg");
}

void State::Update(float dt) {
	if(SDL_QuitRequested()) {
		quitRequest = true;
	}
}

void State::Render() {
	background->Render(0, 0);
}

bool State::QuitRequested() {
	return quitRequest;
}