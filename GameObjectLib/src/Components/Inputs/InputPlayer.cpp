#include "Components/Inputs/InputPlayer.h"
#include "Commands/CommandsPlayer.h"
#include "Components/Armes.h"
#include "Components/SpriteRenderer.h"
#include "SceneManager.h"

InputPlayer::InputPlayer() {
	this->player = nullptr;
	this->KeyD_ = new MoveToRightCommand(this);
	this->KeyQ_ = new MoveToLeftCommand(this);
	this->KeySpace_ = new MoveToRightBulletCommand(this);
	this->KeyEscape_ = new GamePause(this);
	this->KeyZ_ = new JumpCommand(this);
}

void InputPlayer::Update(sf::Time _delta) {
	Component::Update(_delta);

	Command* commandMoves = this->HandleInput();
	if (commandMoves) {
		commandMoves->Execute(_delta);
	}
	Command* commandJump = this->JumpInput();
	if (commandJump) {
		commandJump->Execute(_delta);
	}
	Command* fireBullet = this->FireInput();
	if (fireBullet) {
		fireBullet->Execute(_delta);
	}

}

Command* InputPlayer::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return KeyQ_;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return KeyD_;

	return nullptr;

}

Command* InputPlayer::JumpInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) return KeyZ_;
	return nullptr;
}

Command* InputPlayer::FireInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return KeySpace_;
	return nullptr;
}

Command* InputPlayer::PauseInput() {
	static bool isPressedEscape = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !isPressedEscape) {
		isPressedEscape = true;
		return KeyEscape_;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		isPressedEscape = false;
	}

	return nullptr;
}

void InputPlayer::MoveRight(sf::Time _delta)
{
	GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Right + Maths::Vector2f(25, 0) * _delta.asSeconds() * speed);
	GetOwner()->GetComponent<Player>()->setDirection(Player::Direction::Right);
	GetOwner()->GetComponent<Sprite>()->PlayerPlayAnimationRun();
}

void InputPlayer::MoveLeft(sf::Time _delta)
{
	GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Left + Maths::Vector2f(-25, 0) * _delta.asSeconds() * speed);
	GetOwner()->GetComponent<Player>()->setDirection(Player::Direction::Left);
	GetOwner()->GetComponent<Sprite>()->PlayerPlayAnimationRun();
}

float InputPlayer::AddSpeed(float _addSpeed) {
	speed = +_addSpeed;	
	return speed;
}

void InputPlayer::Jump(sf::Time _delta)
{
	GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Down + Maths::Vector2f(0, -130) * _delta.asSeconds() * speed);
}

void InputPlayer::MoveRightBullet()
{
	player = SceneManager::GetActiveScene()->GetGameObject("Player");
	player->GetComponent<Armes>()->Shoot();
}

void InputPlayer::GamePauseMenu()
{
}

InputPlayer::~InputPlayer() {
	delete 	this->KeyD_;
	delete 	this->KeyQ_;
	delete 	this->KeySpace_;
	delete 	this->KeyEscape_;
	delete 	this->KeyZ_;
}