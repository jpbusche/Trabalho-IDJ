#include "Sprite.h"
#include "Game.h"
#include "Resources.h"

using namespace std;

Sprite::Sprite() {
	texture = nullptr;
	scaleX = 1;
	scaleY = 1;
}

Sprite::Sprite(string file) {
	texture = nullptr;
	scaleX = 1;
	scaleY = 1;
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

void Sprite::Render(int x, int y, double angle) {
	SDL_Rect * dst = new SDL_Rect {x, y, clipRect->w * scaleX, clipRect->h * scaleY};
	SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, clipRect, dst, angle, nullptr, SDL_FLIP_NONE);

}

void Sprite::SetScaleX(double scale) {
	scaleX = scale;
}

void Sprite::SetScaleY(double scale) {
	scaleY = scale;
}

int Sprite::GetWidth() {
	return width * scaleX;
}

int Sprite::GetHeight() {
	return height * scaleY;
}

bool Sprite::IsOpen() {
	if(texture != nullptr) {
		return true;
	} else {
		return false;
	}
}