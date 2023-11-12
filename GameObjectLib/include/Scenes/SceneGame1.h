#pragma once
#include <SFML/Graphics.hpp>

#include "SceneGameAbstract.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       

class SceneGame1 : public SceneGameAbstract
{
public:
	SceneGame1(sf::RenderWindow* window);

	void Awake() override;

	bool PauseMenu(bool gamePause);

	//TODO: ajouter la texture
	void CreatePlatform(sf::Texture texture);
	void CreateBackground();
	void Create() override;
	void Delete() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;

private:
	bool gamePause;
	bool escapeIsPress = true;
};

