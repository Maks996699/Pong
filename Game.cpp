#include "Stick.h"	//
#include "Ball.h"   //
#include "Score.h"  //
#include "Game.h"   //

int Game::height = 0;
int Game::width = 0;

Stick* player = nullptr;
Stick* enemy = nullptr;
Ball* ball = nullptr;
Score* playerScore = nullptr;
Score* enemyScore = nullptr;

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

		if (TTF_Init() == 0)
		{
			std::cout << "TTF is working!" << std::endl;
		}

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		font = TTF_OpenFont("font/comic.ttf", 25);
		if (font)
		{
			std::cout << "Font loaded!" << std::endl;
		}

		isRunning = true;
	}

	player = new Stick("assets/WPlayer.png", 20, 0, 20);
	enemy = new Stick("assets/WPlayer.png", width - 40, 0, 10);
	playerScore = new Score(font, 255, 255, 255, width / 4 , 20, 25, 40);
	enemyScore = new Score(font, 255, 255, 255, (width * 3)/4, 20, 25, 40);
	ball = new Ball("assets/WBall.png", 400, 300);

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
		ball->chengeStateFromCollisionWithPlayer();
	if (checkCollision(enemy, ball))
		ball->changeStateFromCollisionWithEnemy();

	botLogic();

	if (ball->getX() == 0)
	{
		playerScore->addPoint();
		SDL_Delay(600);
	}
	if (ball->getX() + ball->getWidth() == Game::width)
	{
		enemyScore->addPoint();
		SDL_Delay(600);
	}

	player->update();
	playerScore->update();
	enemy->update();
	enemyScore->update();
	ball->update();

}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->render();
	playerScore->render();
	enemy->render();
	enemyScore->render();
	ball->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	delete player;
	delete playerScore;
	delete enemy;
	delete enemyScore;
	delete ball;
	std::cout << "Game Cleaned!" << std::endl;
}

void Game::botLogic()
{
	if (ball->getX() > (Game::width * 2) / 3) //
	{
		int deadZone = 10;
		int posHalfStick = enemy->getY() + enemy->getHeight() / 2;
		if (posHalfStick + deadZone > ball->getY())
		{
			enemy->moveUP();
		}
		else if (posHalfStick + deadZone < ball->getY())
		{
			enemy->moveDown();
		}
	}
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

bool Game::checkCollision(GameObject* obj1, GameObject* obj2)
{
	if (obj1 == obj2) return false;
	if (
	obj1->getX() + obj1->getWidth() >= obj2->getX() &&
	obj2->getX() + obj2->getWidth() >= obj1->getX() &&
	obj1->getY() + obj1->getHeight() >= obj2->getY() &&
	obj2->getY() + obj2->getHeight() >= obj1->getY()
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
