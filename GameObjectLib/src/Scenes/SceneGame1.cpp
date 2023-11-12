#include "Scenes/SceneGame1.h"
#include "SceneManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/SquareCollider.h"
#include "Components/Gravity.h"
#include "AssetManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/Button.h"
#include "Scenes/SceneMainMenu.h"

SceneGame1::SceneGame1(sf::RenderWindow* _window) : SceneGameAbstract(_window) {
	this->Awake();
	srand(time(nullptr));
}


bool SceneGame1::PauseMenu(bool gamePause)
{
	return gamePause;
};


void SceneGame1::Create() {
	SceneGameAbstract::Create();
	this->CreatePlayer();
	CreatePlatform(sf::Texture());
	for (size_t i = 0; i < 7; i++) {
		this->CreateGrunt();
	}
}

void SceneGame1::Delete()
{
	SceneGameAbstract::Delete();
}


void SceneGame1::Awake() {
	SceneGameAbstract::Awake();
}

void SceneGame1::Update(sf::Time _delta) {

	SceneGameAbstract::Update(_delta);

	if (enemies.empty())
	{
		int random_number = rand() % 10 + 5;
		for (size_t i = 0; i < random_number; i++) {
			this->CreateGrunt();
		}
	}
}

void SceneGame1::CreatePlatform(sf::Texture textureplatforme) {


	if (!textureplatforme.loadFromFile("../assets/Sprite/tiles_spritesheet.png"))
	{
		std::cout << "pas d'image ennemy" << std::endl;
	}

	sf::IntRect rectSource(200, 0, 95, 40);
	platforms.push_back(CreatePlatformObject("platforme1", 300.f, 700.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme2", 750.f, 900.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme3", 1100.f, 900.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme4", 1600.f, 700.f, 4.f, 2.f, textureplatforme, new sf::IntRect(rectSource)));;
}

void SceneGame1::CreateBackground()
{
	sf::Texture backgroundTexture1;

	if (!backgroundTexture1.loadFromFile("../assets/Sprite/background/background_color.png"))
	{
		std::cout << "pas d'image" << std::endl;
	}
	GameObject* background1 = CreateBackgroundGameObject("Background1", SceneManager::GetWindowWidth() / 2, SceneManager::GetWindowHeight() / 2, backgroundTexture1);
};

void SceneGame1::Render(sf::RenderWindow* _window) {
	SceneGameAbstract::Render(_window);
}