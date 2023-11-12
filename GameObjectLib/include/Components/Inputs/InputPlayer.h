#pragma once

#include "Command.h"
#include "Components/Component.h"


class InputPlayer : public Component
{
public:
	InputPlayer();

	void Update(sf::Time _delta) override;
	Command* HandleInput();
	Command* JumpInput();
	Command* FireInput();
	Command* PauseInput();
	void MoveRight(sf::Time _delta);
	void MoveRightBullet();
	void GamePauseMenu();
	void MoveLeft(sf::Time _delta);
	void Jump(sf::Time _delta);
	float GetSpeed() { return speed; }
	float AddSpeed(float _speed);
	~InputPlayer();

private:
	float speed = 15.f;
	float JumpVelocity = 0.f;


	Command* KeyZ_;

	Command* KeyD_;
	Command* KeyQ_;
	Command* KeySpace_;
	GameObject* player;
	Command* KeyEscape_;
};