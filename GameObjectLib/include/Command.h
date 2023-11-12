#pragma once

#include <SFML/Graphics.hpp>
class Command
{
public:
	~Command();
	virtual void Execute();
	virtual void Execute(sf::Time delta);
};

