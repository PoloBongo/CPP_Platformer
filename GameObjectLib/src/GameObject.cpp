#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
	this->isActive = true;
}
void GameObject::AddComponent(Component* _component)
{	
	_component->SetOwner(this);
	components.push_back(_component);
}

void GameObject::RemoveComponent(Component* _component)
{
	components.erase(std::remove(components.begin(), components.end(), _component), components.end());
	delete _component;
}

void GameObject::Start() {
	for (Component* const& component : components) {
		component->Start();
	}
}

void GameObject::Update(sf::Time _delta) const
{
	if (this->isActive) {
		for (size_t i = 0; i < components.size(); i++)
		{
			components[i]->Update(_delta);
		}
	}

}

void GameObject::Render(sf::RenderWindow* _window) const
{
	if (this->isActive) {
		for (Component* const& component : components)
		{
			component->Render(_window);
		}
	}

}

