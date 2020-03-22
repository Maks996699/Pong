#include "Stick.h"	//
#include "Ball.h"   //при переносе в хедер - не определяет GameObject
#include "Game.h"

int Game::height = 0;
int Game::width = 0;

Stick* player = nullptr;
Ball* ball = nullptr;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;


Game::Game() : isRunning(false), window(nullptr)
{
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	Game::width = width;
	Game::height = height;

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}

	player = new Stick("assets/Bplayer.png", 20, 0);
	ball = new Ball("assets/ball.png", 400, 300);

}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_KEYDOWN:
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
		{
			if (objectCanMoveUp(player))
				player->moveUP();
			break;
		}
		case SDLK_s:
		{
			if (objectCanMoveDown(player))
				player->moveDown();
			break;
		}
		default:
			break;
		}
		break;
	}

	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
	if (checkCollision(player, ball))
		ball->chengeStateFromCollision();
	player->update();
	ball->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->render();
	ball->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}

int Game::getWidth()
{
	return width;
}

int Game::getHeight()
{
	return height;
}


bool Game::objectCanMoveUp(GameObject* obj)
{
	if (obj->getY() > 0)
	{
		return true;
	}
	return false;
}

bool Game::objectCanMoveDown(GameObject* obj)
{
	if ((obj->getY() + obj->getHeight()) < Game::height) {
		return true;
	}
	return false;
}

bool Game::objectCanMoveLeft(GameObject* obj)
{
	if (obj->getX() > 0) {
		return true;
	}
	return false;
}

bool Game::objectCanMoveRight(GameObject* obj)
{
	if ((obj->getX() + obj->getWidth()) < Game::width)
	{
		return true;
	}
	return false;
}

bool Game::checkCollision(Stick* st, Ball* bl)
{
	if (
	st->getX() + st->getWidth() >= bl->getX() &&
	bl->getX() + bl->getWidth() >= st->getX() &&
	st->getY() + st->getHeight() >= bl->getY()&&
	bl->getY() + bl->getHeight() >= st->getY()
	)
	{
		return true;
	}

	return false;

}

bool Game::running()
{
	return isRunning;
}
