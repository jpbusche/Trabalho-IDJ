#include "Resources.h"
#include "Game.h"

using namespace std;

unordered_map<string, SDL_Texture*> Resources::imageTable;

SDL_Texture * Resources::GetImage(string file) {
	auto image = imageTable.find(file);

	if(image != imageTable.end()) {
		return image->second;
	}

	SDL_Texture * texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
	if(texture == nullptr) {
		printf("Textura nao pode ser carregada corretamente: %s\n", SDL_GetError());
		exit(1);
	}
	imageTable.emplace(file, texture);
	return texture;
}

void Resources::ClearImages() {
	for(auto image = imageTable.begin(); image != imageTable.end(); image++) {
		image->second = nullptr;
		SDL_DestroyTexture(image->second);
	}
	imageTable.clear();
}