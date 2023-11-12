#pragma once
#include "Scene.h"

class SceneMainMenu : public Scene
{
public:
	SceneMainMenu(sf::RenderWindow* window);


	void CreateSceneButtonsMenu();

	void Create() override;
	void Delete() override;
	void Render(sf::RenderWindow* _window) override;
	void Update(sf::Time _delta) override;
	void activeOption(bool _state);
	void activeMenu(bool _state);
	~SceneMainMenu();
private:
	GameObject* playButton = nullptr;
	GameObject* optionsButton = nullptr;
	GameObject* quitButton = nullptr;
	GameObject* backButton = nullptr;
	GameObject* successButton = nullptr;
	GameObject* rankButton = nullptr;
	GameObject* player = nullptr;
	GameObject* bullet = nullptr;
	GameObject* sliderVolume = nullptr;
	GameObject* sliderFPS = nullptr;
	sf::Texture* texture;
	sf::Texture* textureBullet;
};

