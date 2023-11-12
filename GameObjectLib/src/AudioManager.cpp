#include "AudioManager.h"
#include <iostream>

int AudioManager::volume = 100;
int AudioManager::maxVolume = 100;
sf::Music* AudioManager::music = nullptr;
sf::Music* AudioManager::sound = nullptr;
std::map<std::string, sf::Music*> AudioManager::musics;
std::map<std::string, sf::Music*> AudioManager::sounds;

void AudioManager::Play(std::string _key) {
	if (AudioManager::musics.find(_key) != AudioManager::musics.end())
	{
		AudioManager::music = AudioManager::musics.at(_key);
		AudioManager::Stop();
		AudioManager::music->play();
	}
	else
	{
		std::cout << "no music" << std::endl;
	}
}

void AudioManager::PlaySound(std::string _key) {
	if (AudioManager::sounds.find(_key) != AudioManager::sounds.end())
	{
		AudioManager::sound = AudioManager::sounds.at(_key);
		AudioManager::sound->play();
	}
	else
	{
		std::cout << "no sound" << std::endl;
	}
}

void AudioManager::AddMusic(std::string _key, std::string _fileName) {
	sf::Music* _music = new sf::Music();
	_music->openFromFile(_fileName);
	AudioManager::musics.insert(std::make_pair(_key, _music));
}

void AudioManager::AddSound(std::string _key, std::string _fileName) {
	sf::Music* _sound = new sf::Music();
	_sound->openFromFile(_fileName);
	AudioManager::sounds.insert(std::make_pair(_key, _sound));
}

AudioManager::~AudioManager() {
	delete  AudioManager::music;
	delete  AudioManager::sound;
	for (auto& music : AudioManager::musics) {
		delete music.second;
	}
	for (auto& sound : AudioManager::sounds) {
		delete sound.second;
	}
	AudioManager::musics.clear();
	AudioManager::sounds.clear();
}
