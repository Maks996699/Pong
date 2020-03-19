#pragma once
#include "TextureManager.h"

class GameObject
{

public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void MoveUP();
	void MoveDown();

	int getX();
	int getY();
	int getHeight();

	void Update();
	void Render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;


};

