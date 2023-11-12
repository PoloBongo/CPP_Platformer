#pragma once

#include "Components/SpriteRenderer.h"
#include "Scene.h"
#include "Components/Armes.h"

class FireBullet : public Component
{
public:
	enum DirectionBullet { Left, Right };
	DirectionBullet dirBullet = DirectionBullet::Right;
	FireBullet();
	void setDirection(GameObject* _player);
	void Update(sf::Time _delta) override;
	void Collided();

private:
	GameObject* player;
};