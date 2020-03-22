#include "GameObject.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
	: objTexture(TextureManager::LoadTexture(texturesheet)), xpos(x), ypos(y)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 100;
	srcRect.w = 20;
	destRect.x = x;
	destRect.y = y;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
}

GameObject::~GameObject()
{
}

int GameObject::getX()
{
	return xpos;
}

int GameObject::getY()
{
	return ypos;
}

int GameObject::getHeight()
{
	return srcRect.h;
}

int GameObject::getWidth()
{
	return srcRect.w;
}

void GameObject::update()//////////////////
{

}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
