#pragma once
#include "Scene.h"

class SceneRankMenu : public Scene
{
public:
	SceneRankMenu(sf::RenderWindow* window);

	void CreateSceneButtonsMenu();

	void SetOrigin();

	void Create() override;
	void Render(sf::RenderWindow* _window) override;
	void Update(sf::Time _delta) override;
private:
	GameObject* rankButton = nullptr;
	GameObject* backButton = nullptr;
	GameObject* listRank = nullptr;
	sf::Text text;
};


