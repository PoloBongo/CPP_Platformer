#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "GameObject.h"

class GameObject;

class Component
{
public:
	Component() = default;
	Component(GameObject* owner);
	virtual ~Component() = default;

	virtual void Start();
	virtual void Update(sf::Time _delta);
	virtual void Render(sf::RenderWindow* _window);

	GameObject* GetOwner() const { return owner; }
	void SetOwner(GameObject* _owner) { owner = _owner; }

protected:
	GameObject* owner = nullptr;
};
