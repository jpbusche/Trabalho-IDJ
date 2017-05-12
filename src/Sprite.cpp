#include "Sprite.h"
#include "Game.h"
#include "Resources.h"

using namespace std;

Sprite::Sprite() {
	texture = nullptr;
	scaleX = 1;
	scaleY = 1;
	frameCount = 1;
	currentFrame = 0;
	timeElapsed = 0;
	frameTime = 1;
}

Sprite::Sprite(string file, int frameCount, double frameTime) {
	texture = nullptr;
	scaleX = 1;
	scaleY = 1;
	currentFrame = 0;
	timeElapsed = 0;
	SetFrameCount(frameCount);
	SetFrameTime(frameTime);
	Open(file);
}

Sprite::~Sprite() {
	Resources::ClearImages();
}

void Sprite::Update(double dt) {
	timeElapsed += dt;
	if(timeElapsed >= frameTime) {
		timeElapsed = 0;
		SetFrame((currentFrame + 1) % frameCount);
	}
}

void Sprite::Open(string file) {
	if(texture != nullptr) {
		texture = nullptr;
		SDL_DestroyTexture(texture);
	}
	texture = Resources::GetImage(file);
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	width = width / frameCount;
	SetClip(width * currentFrame, 0, width, height);
}

void Sprite::SetFrame(int frame) {
	currentFrame = frame;
	SetClip(width * currentFrame, 0, width, height);
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

void Sprite::SetFrameCount(int frameCount) {
	this->frameCount = frameCount;
}

void Sprite::SetFrameTime(double frameTime) {
	this->frameTime = frameTime;
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