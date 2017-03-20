#ifndef SPRITE_H
#define SPRITE_H

using namespace std;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Sprite {
	public:
		Sprite();
		Sprite(string file);
		~Sprite();

		void Open(string file);
		void SetClip(int x, int y, int w, int h);
		void Render(int x, int y);
		int GetWidth();
		int GetHeight();
		bool IsOpen();

	private:
		SDL_Texture * texture;
		int width;
		int height;
		SDL_Rect * clipRect;
};

#endif