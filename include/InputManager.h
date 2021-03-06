#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

using namespace std;

#include <unordered_map>

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGTH
#define W_KEY SDLK_w
#define S_KEY SDLK_s
#define A_KEY SDLK_a
#define D_KEY SDLK_d

class InputManager {
	public:
		void Update();
		int GetMouseX();
		int GetMouseY();
		bool KeyPress(int key);
		bool KeyRelease(int key);
		bool IsKeyDown(int key);
		bool MousePress(int button);
		bool MouseRelease(int button);
		bool IsMouseDown(int button);
		bool QuitRequested();

		static InputManager & GetInstance();

	private:
		InputManager();
		~InputManager();

		int mouseX;
		int mouseY;
		int updateCounter;
		bool quitRequested;

		bool mouseState[6];
		int mouseUpdate[6];

		unordered_map<int, bool> keyState;
		unordered_map<int, int> keyUpdate;
};

#endif