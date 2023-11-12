#include "Components/SpriteRenderer.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "AssetManager.h"

Sprite::Sprite()
{

	texture.create(100, 100);
	scalex = 1.0f;
	scaley = 1.0f;
	rectTexture = nullptr;

	currentFrame = 0;
	frameDuration = 0.2f;
	animationClock.restart();
	LoadPlayAnimation();
	LoadPlayAnimationGrunt();                                        

}
sf::Vector2f Sprite::GetBounds()
{
	return sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
}

void Sprite::LoadPlayAnimation()
{
	for (int i = 0; i <= 4; i++) {
		std::string filename = "../assets/Sprite/player/playerStatic/john_idle_" + std::to_string(i) + ".png";

		AssetManager::AddAsset("Player" + std::to_string(i), sf::Texture());
		AssetManager::LoadAsset("Player" + std::to_string(i), filename);
		animPlayer.push_back(AssetManager::GetAsset("Player" + std::to_string(i)));
	}
	for (int i = 0; i <= 9; i++) {
		std::string filename = "../assets/Sprite/player/playerRun/john_run_" + std::to_string(i) + ".png";

		AssetManager::AddAsset("Player" + std::to_string(i), sf::Texture());
		AssetManager::LoadAsset("Player" + std::to_string(i), filename);
		animPlayerRun.push_back(AssetManager::GetAsset("Player" + std::to_string(i)));
	}
}

void Sprite::PlayerPlayAnimation()
{
	if (animationClock.getElapsedTime().asSeconds() > frameDuration)
	{
		currentFrame = (currentFrame + 1) % animPlayer.size();
		texture = animPlayer[currentFrame];
		animationClock.restart();
	}
}

void Sprite::PlayerPlayAnimationRun()
{
	if (animationClock.getElapsedTime().asSeconds() > frameDuration)
	{
		currentFrame = (currentFrame + 1) % animPlayerRun.size();
		texture = animPlayerRun[currentFrame];
		animationClock.restart();
	}
}

void Sprite::LoadPlayAnimationGrunt()
{

	std::string filename = "../assets/Sprite/enemy/enemyStatic/grunt_idle_0.png";

	AssetManager::AddAsset("Grunt0", sf::Texture());
	AssetManager::LoadAsset("Grunt0", filename);
	animGrunt.push_back(AssetManager::GetAsset("Grunt0"));

	for (int i = 0; i <= 9; i++) {
		std::string filename = "../assets/Sprite/enemy/enemyRun/grunt_run_" + std::to_string(i) + ".png";

		AssetManager::AddAsset("Grunt" + std::to_string(i), sf::Texture());
		AssetManager::LoadAsset("Grunt" + std::to_string(i), filename);
		animGruntRun.push_back(AssetManager::GetAsset("Grunt" + std::to_string(i)));
	}
}

void Sprite::GruntPlayAnimation()
{
	if (animationClock.getElapsedTime().asSeconds() > frameDuration)
	{
		currentFrame = (currentFrame + 1) % animGrunt.size();
		texture = animGrunt[currentFrame];
		animationClock.restart();
	}
}

void Sprite::GruntPlayAnimationRun()
{
	if (animationClock.getElapsedTime().asSeconds() > frameDuration)
	{
		currentFrame = (currentFrame + 1) % animGruntRun.size();
		texture = animGruntRun[currentFrame];
		animationClock.restart();
	}
}
void Sprite::Update(sf::Time _delta)
{
}

void Sprite::SetSprite()
{
	const auto position = GetOwner()->GetPosition();
	sprite.setTexture(texture);

	if (this->rectTexture) {
		sprite.setTextureRect(*rectTexture);
	}

	sprite.setScale(scalex, scaley);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.x, position.y);
}

void Sprite::Render(sf::RenderWindow* _window)
{
	Component::Render(_window);
	this->SetSprite();
	_window->draw(sprite);
}
