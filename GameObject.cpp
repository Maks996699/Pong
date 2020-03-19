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

void GameObject::MoveUP()
{
	ypos -= 10;
	destRect.y = ypos;
}


void GameObject::MoveDown()
{
	ypos += 10;
	destRect.y = ypos;
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

void GameObject::Update()//////////////////
{

}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
