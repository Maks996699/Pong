#pragma once
#include "TextureManager.h"
enum class BallState {
	Right30, Right45, Right60, Right, Right120, Right135, Right150,
	Left30,  Left45,  Left60,  Left,  Left120,  Left135,  Left150
};


class Ball
{

public:
	Ball(const char* texturesheet, int x, int y);
	~Ball();
	void setState(BallState& state);

	
	void update();
	void render();
private:
	int speed;
	BallState state;

	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

};

