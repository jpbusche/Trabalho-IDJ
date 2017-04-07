#include "Sprite.h"
#include "Game.h"
#include "Resources.h"

using namespace std;

Sprite::Sprite() {
	texture = nullptr;
}

Sprite::Sprite(string file) {
	texture = nullptr;
	Open(file);
}

Sprite::~Sprite() {
	Resources::ClearImages();
}

void Sprite::Open(string file) {
	if(texture != nullptr) {
		texture = nullptr;
		SDL_DestroyTexture(texture);
	}
	texture = Resources::GetImage(file);
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
	clipRect = new SDL_Rect {x, y, w, h};
}

void Sprite::Render(int x, int y) {
	SDL_Rect * dst = new SDL_Rect {x, y, clipRect->w, clipRect->h};
	SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, clipRect, dst);

}

int Sprite::GetWidth() {
	return width;
}

int Sprite::GetHeight() {
	return height;
}

bool Sprite::IsOpen() {
	if(texture != nullptr) {
		return true;
	} else {
		return false;
	}
}