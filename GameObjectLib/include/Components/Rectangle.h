#pragma once
#include <SFML/Graphics.hpp>
#include "Components/Component.h"

class Rectangle : public Component
{
public:
	Rectangle() = default;
	~Rectangle() override = default;

	void Create(int _width, int _height, sf::Color _color);
	void Render(sf::RenderWindow* _window) override;

private:
	sf::RectangleShape rectangle;
};

