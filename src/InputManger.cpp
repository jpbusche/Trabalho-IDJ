#include "InputManager.h"
#include "SDL2/SDL.h"

using namespace std;

InputManager::InputManager() {
	mouseX = 0;
	mouseY = 0;
	updateCounter = 0;
	quitRequested = false;
	memset(mouseUpdate, 0, sizeof mouseUpdate);
	memset(mouseState, false, sizeof mouseState);
}

InputManager::~InputManager() {
	keyState.clear();
	keyUpdate.clear();
}


InputManager & InputManager::GetInstance() {
	static InputManager instance;
	return instance;
}

void InputManager::Update() {
	SDL_Event event;
	quitRequested = false;
	updateCounter++;

	SDL_GetMouseState(&mouseX, &mouseY);
	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		} else if(event.type == SDL_KEYDOWN && not event.key.repeat) {
			keyState[event.key.keysym.sym] = true;
			keyUpdate[event.key.keysym.sym] = updateCounter;
		} else if(event.type == SDL_KEYUP) {
			keyState[event.key.keysym.sym] = false;
			keyUpdate[event.key.keysym.sym] = updateCounter;
		} else if(event.type == SDL_MOUSEBUTTONDOWN && not event.key.repeat) {
			mouseState[event.button.button] = true;
			mouseUpdate[event.button.button] = updateCounter;
		} else if(event.type == SDL_MOUSEBUTTONUP) {
			mouseUpdate[event.button.button] = false;
			mouseState[event.button.button] = updateCounter;
		}
	}
}

bool InputManager::KeyPress(int key) {
	return ((keyUpdate[key] == updateCounter) and (IsKeyDown(key)));
}

bool InputManager::KeyRelease(int key) {
	return ((keyUpdate[key] == updateCounter) and (not IsKeyDown(key)));
}

bool InputManager::IsKeyDown(int key) {
	return keyState[key];
}

bool InputManager::MousePress(int button) {
	return ((mouseUpdate[button] == updateCounter) and (IsMouseDown(button)));
}

bool InputManager::MouseRelease(int button) {
	return ((mouseUpdate[button] == updateCounter) and (not IsMouseDown(button)));
}

bool InputManager::IsMouseDown(int button) {
	return mouseState[button];
}

bool InputManager::QuitRequested() {
	return quitRequested;
}

int InputManager::GetMouseX() {
	return mouseX;
}

int InputManager::GetMouseY() {
	return mouseY;
}