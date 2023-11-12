#include "Scene.h"
#include "SceneManager.h"

#include "Components/Button.h"
#include "Components/SquareCollider.h"
#include "Components/SpriteRenderer.h"
#include "Components/Gravity.h"
#include "Components/Platforme.h"
#include "Components/Entities/Enemies/Grunt.h"
#include "Components/Entities/Enemies/Turret.h"
#include "Components/FireBullet.h"
#include "Components/Rectangle.h"
#include "Components/Armes.h"
#include "Components/Slider.h"

sf::RenderWindow* Scene::window = nullptr;

Scene::Scene(sf::RenderWindow* _window) {
	window = _window;
	this->balleTiree = false;
	this->inputHandlerPlayer = nullptr;
}

void Scene::Create() {
	balleTiree = false;
	interval = sf::seconds(0.1f);
}

void Scene::Delete() {
	for (GameObject* gameObject : this->gameObjects) {
		delete gameObject;
	}
	gameObjects.clear();
}

void Scene::Awake() {
	for (GameObject* const& gameObject : gameObjects)
	{
		gameObject->Start();
	}
}

void Scene::Update(sf::Time _delta)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window->close();
		if (event.type == sf::Event::KeyPressed)
		{
			/*if (event.key.code == sf::Keyboard::Escape) window->close();*/
			if (event.key.code == sf::Keyboard::LAlt) if (event.key.code == sf::Keyboard::F4) window->close();
		}

	}

	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update(_delta);
	}

	//TODO: Ne pas faire de foreach lorsqu'on modifie le nombre d'élément dans le vector
	//for (GameObject* const& gameObject : gameObjects)
	//{
	//	std::cout << gameObject->GetName() << std::endl;
	//	gameObject->Update(_delta);
	//}
}

void Scene::Render(sf::RenderWindow* _window)
{
	for (GameObject* const& gameObject : gameObjects)
	{
		gameObject->Render(_window);
	}
}

GameObject* Scene::CreateGameObject(const std::string& _name)
{
	auto gameObject = new GameObject();
	gameObject->SetName(_name);
	gameObject->SetActive(true);
	gameObjects.push_back(gameObject);
	return gameObject;
}


//GAME ELEMENT

GameObject* Scene::CreateButtonGameObject(const std::string& name, float x, float y, unsigned int fontSize)
{
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(x, y));
	gameObject->SetActive(true);

	Button* button = gameObject->CreateComponent<Button>();
	button->SetPosition(x, y);
	button->SetButton(fontSize);
	button->SetOrigin();

	return gameObject;
}


GameObject* Scene::CreatePlatformObject(const std::string& name, float x, float y, float scaleX, float scaleY, const sf::Texture texture, sf::IntRect* _rectSource) {

	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(x, y));

	Sprite* sprite = gameObject->CreateComponent<Sprite>();
	sprite->SetTexture(texture);
	sprite->SetRect(_rectSource);
	sprite->SetScale(scaleX, scaleY);
	sprite->SetSprite();

	SquareCollider* squareCollider = gameObject->CreateComponent<SquareCollider>();
	squareCollider->SetSize(sprite->GetBounds().x, sprite->GetBounds().y);
	squareCollider->SetScale(scaleX, scaleY);

	

	return gameObject;
}

GameObject* Scene::CreateDecorObject(const std::string& name, float x, float y, float scaleX, float scaleY, const sf::Texture texture) {

	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(x, y));

	Sprite* sprite = gameObject->CreateComponent<Sprite>();
	sprite->SetTexture(texture);
	sprite->SetScale(scaleX, scaleY);

	return gameObject;
}

GameObject* Scene::CreateBackgroundGameObject(const std::string& name, float x, float y, sf::Color _color) {

	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(x, y));

	Rectangle* background = gameObject->CreateComponent<Rectangle>();
	background->Create(SceneManager::GetWindow()->getSize().x, SceneManager::GetWindow()->getSize().y, _color);
	
	return gameObject;
}

GameObject* Scene::CreateBackgroundGameObject(const std::string& name, float x, float y, const sf::Texture texture) {
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(x, y));

	Sprite* sprite = gameObject->CreateComponent<Sprite>();
	sprite->SetTexture(texture);
	
	float scalerX = (float)SceneManager::GetWindow()->getSize().x / texture.getSize().x;
	float scalerY = (float)SceneManager::GetWindow()->getSize().y / texture.getSize().y;
	sprite->SetScale(scalerX, scalerY);
	sprite->SetSprite();

	return gameObject;
}


GameObject* Scene::CreateSliderGameObject(const std::string& name, float _x, float _y, float _widthBar, float _heightBar, float _widthCursor, float _heightCursor, unsigned int _fontSize, float _data, float _maxData) {
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(_x, _y));

	Slider* slider = gameObject->CreateComponent<Slider>();
	slider->SetMaxData(_maxData);
	slider->SetData(_data);
	slider->SetSizeBar(_widthBar, _heightBar);
	slider->SetSizeCursor(_widthCursor, _heightCursor);
	slider->SetCursorText(_fontSize);
	slider->SetTitleText();
	slider->SetPosition(_x, _y);

	return gameObject;
}

GameObject* Scene::CreateSliderGameObject(const std::string& name, float _x, float _y, float _widthBar, float _heightBar, float _widthCursor, float _heightCursor, unsigned int _fontSize, float _data, float _minData, float _maxData) {
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(_x, _y));

	Slider* slider = gameObject->CreateComponent<Slider>();
	slider->SetMaxData(_maxData);
	slider->SetMinData(_minData);
	slider->SetData(_data);
	slider->SetSizeBar(_widthBar, _heightBar);
	slider->SetSizeCursor(_widthCursor, _heightCursor);
	slider->SetCursorText(_fontSize);
	slider->SetTitleText();
	slider->SetPosition(_x, _y);

	return gameObject;
}

//GameObject* Scene::CreateDecorObject(const std::string& name, float positionx, float positiony, float scalex, float scaley, sf::Texture _texture)
//{
//	GameObject* gameObject = CreateGameObject(name);
//	gameObject->SetPosition(Maths::Vector2f(positionx, positiony));
//
//	SquareCollider* squareCollider = gameObject->CreateComponent<SquareCollider>();
//	squareCollider->SetWidth(60.f);
//	squareCollider->SetHeight(60.f);
//
//	Sprite* spriteBullet = gameObject->CreateComponent<Sprite>();
//	spriteBullet->SetTexture(_texture);
//	spriteBullet->SetScale(scalex, scaley);
//
//	Gravity* gravity = gameObject->CreateComponent<Gravity>();
//
//
//	return gameObject;
//
//}

