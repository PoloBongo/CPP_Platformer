#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Scene.h"

class Button : public Component
{

public:
	Button();

	void SetButton(unsigned int fontSize);
	void SetButton(const sf::Font& font, unsigned int fontSize);
	void SetOrigin();
	void SetSize(float _width, float _height);
	void SetPosition(float _x, float _y);

	void Render(sf::RenderWindow* _window) override;
	bool IsClicked();
	void Update(sf::Time _delta) override;

	~Button();

private:
	float width, height;
	sf::Font font;
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::FloatRect textBounds;
	bool clicked = false;
	sf::RenderWindow* window = nullptr;
};

