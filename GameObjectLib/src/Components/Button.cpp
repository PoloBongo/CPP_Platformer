#include "Components/Button.h"
#include "SceneManager.h"

Button::Button() {
	this->height = 0;
	this->width = 0;
	this->clicked = false;
	this->window = SceneManager::GetWindow();
}


void Button::SetButton(unsigned int fontSize) {
	

	if (!font.loadFromFile("../Fonts/Roboto-Medium.ttf")) {
		std::cout << "Font introuvable" << std::endl;
	}
	text = sf::Text(GetOwner()->GetName(), font, fontSize);
	text.setFillColor(sf::Color::White);

	textBounds = text.getLocalBounds();
	this->SetSize(textBounds.width + fontSize *3, textBounds.height + fontSize * 1.5);
	
	rectangle = sf::RectangleShape(sf::Vector2f(width, height));
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setFillColor(sf::Color::Blue);
}

void Button::SetButton(const sf::Font& font, unsigned int fontSize) {
	text = sf::Text(GetOwner()->GetName(), font, fontSize);
	text.setFillColor(sf::Color::White);

	textBounds = text.getLocalBounds();
	this->SetSize(textBounds.width + fontSize * 3, textBounds.height + fontSize * 1.5);

	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Blue);
}

void Button::SetOrigin() {
	rectangle.setOrigin(sf::Vector2f(width / 2, height / 2));
	text.setOrigin(sf::Vector2f(textBounds.width / 2, textBounds.height / 2));
}

void Button::SetSize(float _width, float _height) {
	width = _width;
	height = _height;
}

void Button::SetPosition(float _x, float _y) {
	text.setPosition(_x, _y);
	rectangle.setPosition(_x, _y);
}

void Button::Render(sf::RenderWindow* _window) {
	Component::Render(_window);

	const auto position = GetOwner()->GetPosition();
	SetPosition(position.x, position.y);

	_window->draw(rectangle);
	_window->draw(text);
}

void Button::Update(sf::Time _delta) {
}

bool Button::IsClicked() {

	return rectangle.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked;
}


Button::~Button() {}