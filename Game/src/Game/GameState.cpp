#include "Game/GameState.h"
#include "SceneManager.h"
#include "SceneMainMenu.h"
#include "SceneSuccessMenu.h"
#include "SceneRankMenu.h"
#include "SceneGame1.h"
#include "SceneGame2.h"

GameState::GameState(sf::RenderWindow* _window, int _FPS) {
	this->window = _window;
	this->FPS = _FPS;
	SceneManager::SetFps(this->FPS);
}


void GameState::Preload() {
	SceneManager::GetActiveScene()->Awake();
	
}

void GameState::Create() {
	SceneManager::AddScene("SceneMainMenu", new SceneMainMenu(this->window));
	SceneManager::AddScene("SceneGame1", new SceneGame1(this->window));
	SceneManager::AddScene("SceneGame2", new SceneGame2(this->window));
	SceneManager::AddScene("SceneSuccessMenu", new SceneSuccessMenu(this->window));
	SceneManager::AddScene("SceneRankMenu", new SceneRankMenu(this->window));
	SceneManager::RunScene("SceneMainMenu");
	
}


void GameState::Update() {
	// Mesurer le temps écoulé depuis le dernier frame
	sf::Time delta = this->clock.restart();

	// limiter à un nombre fixe de FPS
	sf::Time frameTime = sf::seconds(1.0f / FPS);
	//Delta time for the update
	if (delta < frameTime)
	{
		sf::sleep(frameTime - delta);
		delta = frameTime;
	}

	SceneManager::GetActiveScene()->Update(delta);

	this->window->clear(sf::Color::Black);
	 
	SceneManager::GetActiveScene()->Render(this->window);
	this->window->display();
}

GameState::~GameState() {
}

