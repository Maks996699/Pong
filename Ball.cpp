#include "Ball.h"
#include "GameObject.h"

BallState state = BallState::Right;

Ball::Ball(const char* texturesheet, int x, int y)
    : GameObject(texturesheet, x, y)
{
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.h = 10;
    srcRect.w = 10;
    destRect.x = x;
    destRect.y = y;
    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
    state = BallState::Right30;
    speed = 5;
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
    if (!Game::objectCanMoveUp(this))
    {
        reboundFromUp();
    }
    else if (!Game::objectCanMoveDown(this))
    {
        reboundFromDown();
    }
    else if (!Game::objectCanMoveRight(this))
    {
        reboundFromRight();
    }
    else if (!Game::objectCanMoveLeft(this))
    {
        reboundFromLeft();
    }


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

void Ball::chengeStateFromCollision()
{
    reboundFromLeft();
}

void Ball::reboundFromUp()
{
    switch (state)
    {
    case BallState::Right30:
        state = BallState::Right150;
        break;
    case BallState::Right45:
        state = BallState::Right135;
        break;
    case BallState::Right60:
        state = BallState::Right120;
        break;
    case BallState::Left30:
        state = BallState::Left150;
        break;
    case BallState::Left45:
        state = BallState::Left135;
        break;
    case BallState::Left60:
        state = BallState::Left120;
        break;
    }
}

void Ball::reboundFromDown()
{
    switch (state)
    {
    case BallState::Right150:
        state = BallState::Right30;
        break;
    case BallState::Left150:
        state = BallState::Left30;
        break;
    case BallState::Right135:
        state = BallState::Right45;
        break;
    case BallState::Left135:
        state = BallState::Left45;
        break;
    case BallState::Right120:
        state = BallState::Right60;
        break;
    case BallState::Left120:
        state = BallState::Left60;
        break;
    }
}

void Ball::reboundFromRight()
{
    switch (state)
    {
    case BallState::Right30:
        state = BallState::Left30;
        break;
    case BallState::Right150:
        state = BallState::Left150;
        break;
    case BallState::Right45:
        state = BallState::Left45;
        break;
    case BallState::Right135:
        state = BallState::Left135;
        break;
    case BallState::Right60:
        state = BallState::Left60;
        break;
    case BallState::Right120:
        state = BallState::Left120;
        break;
    case BallState::Right:
        state = BallState::Left;
        break;
    }
}

void Ball::reboundFromLeft()
{
    switch (state)
    {
    case BallState::Left30:
        state = BallState::Right30;
        break;
    case BallState::Left150:
        state = BallState::Right150;
        break;
    case BallState::Left45:
        state = BallState::Right45;
        break;
    case BallState::Left135:
        state = BallState::Right135;
        break;
    case BallState::Left60:
        state = BallState::Right60;
        break;
    case BallState::Left120:
        state = BallState::Right120;
        break;
    case BallState::Left:
        state = BallState::Right;
        break;
    }
}


