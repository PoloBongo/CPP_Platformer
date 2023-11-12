#include "Components/Rectangle.h"

void Rectangle::Create(int _width, int _height, sf::Color _color) {
	rectangle = sf::RectangleShape(sf::Vector2f(_width, _height));
	rectangle.setFillColor(_color);
}

void Rectangle::Render(sf::RenderWindow* _window) {
	Component::Render(_window);
	_window->draw(rectangle);
}