#pragma once
#include "GameObject.h"
#include "SDL_ttf.h"
#include "Game.h"
#include <string>
class Score :
	public GameObject
{

public:
	Score(TTF_Font* font, int r, int g, int b, int x, int y, int width, int height);
	~Score();
	void addPoint();
	void update();
	int getScore();

private:
	TTF_Font* font;
	SDL_Color color;
	SDL_Surface* surface;
	int score;
};

