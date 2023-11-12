#pragma once
#include <SFML/Graphics.hpp>

class GameConfig
{
public:

	GameConfig();

	int GetFps() const { return FPS; }
	void SetFps(int _FPS) { FPS = _FPS; }
	sf::RenderWindow* GetWindow() const { return window; }
	void SetWindow(sf::RenderWindow* _window) { window = _window; }

	~GameConfig();

private:
	int FPS ;
	sf::RenderWindow* window;
};

