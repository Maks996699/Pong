#ifndef GameObject_h
#define GameObject_h

#include "TextureManager.h"

class GameObject
{

public:
	GameObject(const char* texturesheet, int x, int y);
	GameObject(int x, int y, int width, int height);
	virtual ~GameObject();

	int getX() const;
	int getY() const;
	int getHeight() const;
	int getWidth() const;

	virtual void update();
	void render();

protected:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

};

#endif
