#pragma once

#include "Component.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>

class Sprite : public Component
{
public:
	Sprite();
	~Sprite() override = default;

	void Update(sf::Time _delta);
	void SetTexture(const sf::Texture& _texture) { texture = _texture; }
	void SetScale(float _scalex, float _scaley) { scalex = _scalex; scaley = _scaley; }
	sf::Vector2f GetSize() { return sf::Vector2f(sprite.getLocalBounds().width * scalex, sprite.getLocalBounds().height * scaley); }
	sf::Vector2f GetBounds();
	
	void LoadPlayAnimation();
	void PlayerPlayAnimation();
	void PlayerPlayAnimationRun();
	void LoadPlayAnimationGrunt();
	void GruntPlayAnimation();
	void GruntPlayAnimationRun();
	
	float GetTop() { return sprite.getLocalBounds().top * scaley; }
	float GetBottom() { return (sprite.getLocalBounds().top + sprite.getLocalBounds().height) * scaley; }
	float GetLeft() { return sprite.getLocalBounds().left * scalex; }
	float GetRight() { return (sprite.getLocalBounds().left + sprite.getLocalBounds().width) * scalex; }

	void Render(sf::RenderWindow* _window) override;
	void SetSprite();
	void SetRect(sf::IntRect* _rectSource) { rectTexture = _rectSource; }

private:
	sf::Texture texture;
	sf::IntRect* rectTexture;
	float scalex, scaley;
	std::vector<sf::Texture> animPlayer;
	std::vector<sf::Texture> animPlayerRun;
	std::vector<sf::Texture> animGrunt;
	std::vector<sf::Texture> animGruntRun;
	sf::Sprite sprite;
	int currentFrame;
	float frameDuration;
	sf::Clock animationClock;

};
