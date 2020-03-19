#include "Game.h"


GameObject* player = nullptr;
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
	this->width = width;
	this->height = height;

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

	player = new GameObject("assets/Bplayer.png", 20, 0);
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
			if (playerCanMoveUp(player))
				player->MoveUP();
			break;
		}
		case SDLK_s:
		{
			if (playerCanMoveDown(player))
				player->MoveDown();
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
	player->Update();

	ball->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->Render();
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

bool Game::playerOnBorder(GameObject* obj)
{
	if (obj->getY() > 0 && obj->getY() < width)
		return false;
	return true;
}

bool Game::playerCanMoveUp(GameObject* obj)
{
	if (obj->getY() > 0)
	{
		return true;
	}
	return false;
}

bool Game::playerCanMoveDown(GameObject* obj)
{
	if (obj->getY() + obj->getHeight() < height) {
		return true;
	}
	return false;
}

bool Game::running()
{
	return isRunning;
}
