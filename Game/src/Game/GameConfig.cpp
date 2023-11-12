#include "Game/GameConfig.h"
#include "SceneManager.h"
#include "AudioManager.h"


GameConfig::GameConfig() {
	this->FPS = 240;
	this->window = new sf::RenderWindow(sf::VideoMode(600, 600), "RAMBO", sf::Style::Fullscreen);
	SceneManager::SetWindow(this->window);
	SceneManager::SetFps(this->FPS);
	AudioManager::AddMusic(std::string("valkyrieApocalypse"), std::string("../Sounds/valkyrie.mp3"));
	AudioManager::AddSound(std::string("dead"), std::string("../Sounds/pas_ma_guerre.mp3"));
	AudioManager::Play(std::string("valkyrieApocalypse"));
}

GameConfig::~GameConfig() {
	delete this->window;
}
