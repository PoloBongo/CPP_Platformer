#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Components/Entity.h"

class Player : public Entity
{
public:
	enum Direction { Left, Right };
	Player();
	Player(int _hp, int _damage, float _speed);
	void Update(sf::Time _delta);
	void setDirection(Direction direction);
	Direction getDirection() { return direction; }

public:
	Direction direction;
	bool directionPlayer;
};