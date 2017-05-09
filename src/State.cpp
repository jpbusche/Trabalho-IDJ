#include "State.h"
#include "Alien.h"
#include "Vec2.h"
#include "InputManager.h"
#include "Camera.h"

using namespace std;

State::State() {
	quitRequest = false;
	background = new Sprite();
    tileSet = new TileSet(64, 64, "img/tileset.png");
    tileMap = new TileMap("map/tileMap.txt", tileSet);

    Alien * alien = new Alien(512, 300, 10);
    objectArray.emplace_back(alien);
}

State::~State() {
	objectArray.clear();
}

void State::LoadAssets() {
	background->Open("img/ocean.jpg");
}

void State::Update(double dt) {
	InputManager & input = InputManager::GetInstance();
    input.Update();
    Camera::Update(dt);
    if(input.KeyPress(SDLK_ESCAPE) || input.QuitRequested()) {
        quitRequest = true;
    }
	for(auto object = objectArray.begin(); object < objectArray.end(); object++) {
        (*object)->Update(dt);
        if((*object)->IsDead()) {
            objectArray.erase(object);
        }
	}
}

void State::Render() {
	background->Render(0, 0);
    tileMap->Render(Camera::pos.x, Camera::pos.y);
    for(auto object = objectArray.begin(); object < objectArray.end(); object++) {
        (*object)->Render();
    }
}   

void State::AddObject(double mouseX, double mouseY) {}

bool State::QuitRequested() {
	return quitRequest;
}