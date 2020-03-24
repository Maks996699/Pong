#include "Score.h"

Score::Score(TTF_Font* font, int r, int g, int b, int x, int y, int width, int height)
	: GameObject(x, y, width, height)
{
	this->font = font;
	color.r = r;
	color.g = g;
	color.b = b;
	surface = TTF_RenderText_Solid(font, " ", color);
	objTexture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	score = 0;
}

Score::~Score()
{
}

void Score::addPoint()
{
	score++;
}

void Score::update()
{
	SDL_DestroyTexture(objTexture);
	SDL_FreeSurface(surface);
	surface = TTF_RenderText_Solid(font, std::to_string(score).c_str(), color);
	objTexture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_QueryTexture(objTexture, NULL, NULL, &destRect.w, &destRect.h);
}

int Score::getScore()
{
	return score;
}