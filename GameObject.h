#ifndef GameObject_h
#define GameObject_h

#include "TextureManager.h"

class GameObject
{

public:
	GameObject(const char* texturesheet, int x, int y);
	virtual ~GameObject();

	int getX();
	int getY();
	int getHeight();
	int getWidth();

	virtual void update();
	void render();

protected:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

};

#endif
