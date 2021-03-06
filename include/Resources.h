#ifndef RESOURCES_H
#define RESOURCES_H

using namespace std;

#include <string>
#include <unordered_map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Resources {
	public:
		static void ClearImages();
		static SDL_Texture * GetImage(string file);
	private:
		static unordered_map<string, SDL_Texture*> imageTable;
};

#endif