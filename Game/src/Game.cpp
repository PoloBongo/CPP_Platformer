#include "Game.h"

Game::Game() {
	this->config = new GameConfig();
	this->state = new GameState(this->config->GetWindow(), this->config->GetFps());
	this->stats = new GameStats();
	this->log = new GameLog();
}

void Game::run() {
	sf::RenderWindow* window = config->GetWindow();
	state->Create();
	state->Preload();
	

	while (window->isOpen())
	{
		state->Update();
	}
}

Game::~Game() {
	delete this->config;
	delete this->state;
	delete this->stats;
	delete this->log;
}