#ifndef Game_h
#define Game_h

#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>

class GameObject;
class Stick;
class Ball;

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
	static int getWidth();
	static int getHeight();
	static bool objectCanMoveUp(GameObject* obj);
	static bool objectCanMoveDown(GameObject* obj);
	static bool objectCanMoveLeft(GameObject* obj);
	static bool objectCanMoveRight(GameObject* obj);
	static bool checkCollision(GameObject* obj1, GameObject* obj2);

	bool running();

	static SDL_Renderer* renderer;
	static SDL_Event event;

private:
	bool isRunning;
	SDL_Window* window;
	static int width;
	static int height;

	
	int cnt = 0;

};

#endif