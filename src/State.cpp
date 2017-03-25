#include "State.h"
#include "Face.h"
#include "Vec2.h"

using namespace std;

State::State() {
	quitRequest = false;
	background = new Sprite();
}

State::~State() {
	objectArray.clear();
}

void State::LoadAssets() {
	background->Open("img/ocean.jpg");
}

void State::Update(float dt) {
	Input();
	for(int i = 0; i < objectArray.size(); i++) {
		Face * face = (Face*) objectArray[i].get();
		if (face->IsDead()) {
			objectArray.erase(objectArray.begin() + i);
		}
	}
}

void State::Render() {
	background->Render(0, 0);
	for(int i = 0; i < objectArray.size(); i++) {
        Face * face = (Face*) objectArray[i].get();
        face->Render();
    }
}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    while (SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            quitRequest = true;
            delete background;
        } else if(event.type == SDL_MOUSEBUTTONDOWN) {
            for(int i = objectArray.size() - 1; i >= 0; --i) {
                Face * face = (Face*) objectArray[i].get();
                if(face->box->IsInside((float)mouseX, (float)mouseY)) {
                    face->Damage(rand() % 10 + 10);
                    break;
                }
            }
        } else if( event.type == SDL_KEYDOWN ) {
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
                quitRequest = true;
            } else {
                int rand_ang = rand() % 361;
                double angle = (rand_ang) * acos(-1) / 180.0;
                Vec2 vector((float)mouseX + 200, (float)mouseY);
                vector = vector.Rotate(vector, angle, (float)mouseX, (float)mouseY);
                AddObject(vector.GetX(), vector.GetY());
            }
        }
    }
}

void State::AddObject(float mouseX, float mouseY) {
    Face * face = new Face(mouseX, mouseY);
    objectArray.emplace_back(unique_ptr<GameObject>(face));
}

bool State::QuitRequested() {
	return quitRequest;
}