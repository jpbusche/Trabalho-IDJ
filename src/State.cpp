#include "State.h"
#include "Alien.h"
#include "Penguins.h"
#include "Vec2.h"
#include "InputManager.h"
#include "Camera.h"

using namespace std;

State::State() {
	quitRequest = false;
	background = new Sprite();
    tileSet = new TileSet(64, 64, "img/tileset.png");
    tileMap = new TileMap("map/tileMap.txt", tileSet);

    Alien * alien = new Alien(512, 300, 6);
    Penguins * penguings = new Penguins(704, 640);
    Camera::Follow(penguings);
    AddObject(penguings);
    AddObject(alien);
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
    for(int index = 0; index < objectArray.size(); index++) {
        objectArray[index]->Update(dt);
        if(objectArray[index]->IsDead()) {
            objectArray.erase(objectArray.begin() + index);
            break;
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

void State::AddObject(GameObject * object) {
    objectArray.emplace_back(object);
}

bool State::QuitRequested() {
	return quitRequest;
}