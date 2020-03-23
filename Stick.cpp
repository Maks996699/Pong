#include "Stick.h"

Stick::Stick(const char* texturesheet, int x, int y, int speed)
	: GameObject(texturesheet, x, y)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 100;
	srcRect.w = 20;
	destRect.x = x;
	destRect.y = y;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	this->speed = speed;

}

Stick::~Stick()
{
}

void Stick::moveUP()
{
	ypos -= speed;
	destRect.y = ypos;
}

void Stick::moveDown()
{
	ypos += speed;
	destRect.y = ypos;
}

