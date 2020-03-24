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

GameObject::GameObject(int x, int y, int width, int height)
	: xpos(x), ypos(y)
{
	objTexture = nullptr;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = height;
	srcRect.w = width;
	destRect.x = x;
	destRect.y = y;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
}

GameObject::~GameObject()
{
}

int GameObject::getX() const
{
	return xpos;
}

int GameObject::getY() const
{
	return ypos;
}

int GameObject::getHeight() const
{
	return srcRect.h;
}

int GameObject::getWidth() const
{
	return srcRect.w;
}

void GameObject::update()
{

}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
