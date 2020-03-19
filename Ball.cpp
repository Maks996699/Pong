#include "Ball.h"
BallState state = BallState::Right;

Ball::Ball(const char* texturesheet, int x, int y)
	: objTexture(TextureManager::LoadTexture(texturesheet)), xpos(x), ypos(y)
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 10;
	srcRect.w = 10;
	destRect.x = x;
	destRect.y = y;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
    state = BallState::Right;
    speed = 1;
}

Ball::~Ball()
{
}

void Ball::setState(BallState& state)
{
    this->state = state;
}

void Ball::update()
{
	switch (state)
	{
    case BallState::Right30:
        ypos -= speed * 2;
        xpos += speed;
        break;
    case BallState::Right45:
        ypos -= speed;
        xpos += speed;
        break;
    case BallState::Right60:
        ypos -= speed;
        xpos += speed * 2;
        break;
    case BallState::Right:
        xpos += speed;
        break;
    case BallState::Right120:
        ypos += speed;
        xpos += speed * 2;
        break;
    case BallState::Right135:
        ypos += speed;
        xpos += speed;
        break;
    case BallState::Right150:
        ypos += speed * 2;
        xpos += speed;
        break;
    case BallState::Left30:
        ypos -= speed * 2;
        xpos -= speed;
        break;
    case BallState::Left45:
        ypos -= speed;
        xpos -= speed;
        break;
    case BallState::Left60:
        ypos -= speed;
        xpos -= speed * 2;
        break;
    case BallState::Left:
        xpos -= speed;
        break;
    case BallState::Left120:
        ypos += speed;
        xpos -= speed * 2;
        break;
    case BallState::Left135:
        ypos += speed;
        xpos -= speed;
        break;
    case BallState::Left150:
        ypos += speed * 2;
        xpos -= speed;
        break;
    default:
        break;
	}
    destRect.y = ypos;
    destRect.x = xpos;
}

void Ball::render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
