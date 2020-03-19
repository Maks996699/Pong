#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Ball.h"
#include <iostream>

class GameObject;

class Game
{

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	int getWidth();
	int getHeight();
	bool playerOnBorder( GameObject* obj); ////
	bool playerCanMoveUp(GameObject* obj);
	bool playerCanMoveDown(GameObject* obj);

	bool running();

	static SDL_Renderer* renderer;
	static SDL_Event event;

private:
	bool isRunning;
	SDL_Window* window;
	int width;
	int height;
	
	int cnt = 0;

};

