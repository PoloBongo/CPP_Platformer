#include "Components/Platforme.h"

Platforme::Platforme() {
	this->height = 0;
	this->width = 0;
	this->scaleX = 0;
	this->scaleY = 0;
	this->rectangle.setFillColor(sf::Color::Transparent);
};

void Platforme::SetPlatforme() {

	rectangle = sf::RectangleShape(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Blue);
}

void Platforme::SetOrigin() {
	rectangle.setOrigin(sf::Vector2f(width / 2, height / 2));
}

void Platforme::SetSize(float scaleX, float scaleY) {
	rectangle.setSize(sf::Vector2f(scaleX, scaleY));
}

void Platforme::SetPosition(float _x, float _y) {
	rectangle.setPosition(_x, _y);
}

void Platforme::Render(sf::RenderWindow* _window) {
	Component::Render(_window);

	const auto position = GetOwner()->GetPosition();
	this->SetPosition(position.x, position.y);
	_window->draw(rectangle);
}