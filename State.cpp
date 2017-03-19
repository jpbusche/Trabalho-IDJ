#include "State.h"

using namespace std;

State::State() {
	quitRequest = false;
	background = new Sprite();
}

void State::LoadAssets() {

}

void State::Update(float dt) {
	if(SDL_QuitResquested() == true) {
		quitRequest = true;
	}
}

void State::Render() {
	background = new Sprite("img/ocean.jpg");
}

bool State::QuitRequested() {
	return quitRequest;
}