#include "Sprite.h"
#include "Game.h"

using namespace std;

Sprite::Sprite() {
	texture = nullptr;
}

Sprite::Sprite(string file) {
	texture = nullptr;
	Open(file);
}

Sprite::~Sprite() {
	texture = nullptr;
	SDL_DestroyTexture(texture);
}

void Sprite::Open(string file) {
	if(texture != nullptr) {
		texture = nullptr;
		SDL_DestroyTexture(texture);
	}
	texture = IMG_LoadTexture(Game.renderer, file);
	if(texture == nullptr) {
		printf("Textura nao pode ser carregada corretamente: %s\n", SDL_GetError());
		exit(1);
	}
	SDl_QueryTexture(texture, nullptr, nullptr, widht, heigth);
	SetClip(/* x */, /* y */, widht, height);
}

void Sprite::SetClip(int posx, int posy, int rectWidth, int rectHeight) {
	clipRect.x = posx;
	clipRect.y = posy;
	clipRect.w = rectWidth;
	clipRect.h = rectHeight;
}

void Sprite::Render(int posx, int posy) {
	SDL_Rect dst;
	dst.x = posx;
	dst.y = posy;
	dst.w = clipRect.w;
	dst.h = clipRect.h;
	SDL_RenderCopy(Game.renderer, texture, clipRect, dst);

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