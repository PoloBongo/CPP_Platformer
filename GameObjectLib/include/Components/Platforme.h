#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class Platforme : public Component
{
public:
	Platforme();

	void SetPlatforme();
	void SetOrigin();

	sf::Vector2f GetSize() { return sf::Vector2f(width, height); }
	void SetSize(float _width, float _height);

	void SetPosition(float _x, float _y);
	void Render(sf::RenderWindow* _window) override;

private:
	float width, height, scaleX, scaleY;
	sf::RectangleShape rectangle;
	sf::RenderWindow* window = nullptr;
};

