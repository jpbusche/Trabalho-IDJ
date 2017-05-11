#ifndef SPRITE_H
#define SPRITE_H

using namespace std;

#include <string>
#include "Vec2.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Sprite {
	public:
		Sprite();
		Sprite(string file);
		~Sprite();

		void Open(string file);
		void SetClip(int x, int y, int w, int h);
		void Render(int x, int y, double angle = 0);
		void SetScaleX(double scale);
		void SetScaleY(double scale);
		int GetWidth();
		int GetHeight();
		bool IsOpen();

	private:
		SDL_Texture * texture;
		int width;
		int height;
		SDL_Rect * clipRect;
		double scaleX;
		double scaleY;
};

#endif