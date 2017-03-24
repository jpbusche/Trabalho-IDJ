#include "State.h"
#include "Face.h"

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
	for (int i = 0; i < objectArray.size(); i++) {
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
                AddObject((float)mouseX, (float)mouseY);
            }
        }
    }
}


bool State::QuitRequested() {
	return quitRequest;
}