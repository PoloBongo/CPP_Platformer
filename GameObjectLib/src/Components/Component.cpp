#include "Components/Component.h"

Component::Component(GameObject* owner)
{
	this->owner = owner;
}
void Component::Start() {}

void Component::Update(sf::Time _delta) {}

void Component::Render(sf::RenderWindow* _window) {

}
