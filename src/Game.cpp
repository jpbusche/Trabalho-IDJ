#include "Game.h"

using namespace std;

Game * Game::instance = nullptr;

Game::Game(string title, int width, int height) {
	
	if(instance != nullptr) {
		printf("Mais de uma instância iniciada! Jogo fechando...\n");
		exit(1);
	} else {
		instance = this;
	}

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		printf("Nao foi possivel inicializar a SDL: %s\n", SDL_GetError());
		exit(1);
	} else {
		int img_flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
		if(IMG_Init(img_flags) != img_flags) {
			printf("Nao foi possivel inicializar a SDL_Image: %s\n", SDL_GetError());
			exit(1);
		} else {
			window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
			if(window == nullptr) {
				printf("A janela nao pode ser criada: %s\n", SDL_GetError());
				exit(1);
			}			
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);			
			if(renderer == nullptr) {
				printf("A renderização nao pode ser criada: %s\n", SDL_GetError());
				exit(1);
			}
		}
	}
	state = new State();
}

Game::~Game() {

	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

Game & Game::GetInstance() {
	return * instance;
}

State & Game::GetState() {
	return * state;
}

SDL_Renderer * Game::GetRenderer() {
	return renderer;
}

void Game::run() {
	state->LoadAssets();
	while(!state->QuitRequested()) {
		state->Update();
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}