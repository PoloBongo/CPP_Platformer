
#include "Components/Entities/Player.h"
#include "SceneManager.h"
#include "Components/Armes.h"

Player::Player() : Entity(200, 30, 20.f)
{
    directionPlayer = false;
	direction = Direction::Right;
}

Player::Player(int _hp, int _damage, float _speed) : Entity(_hp, _damage, _speed)
{
    directionPlayer = false;
    direction = Direction::Right;
}

void Player::setDirection(Direction newDirection) {
	direction = newDirection;
}

void Player::Update(sf::Time _delta)
{
    Entity::Update(_delta);
    if (direction == Direction::Left)
    {
        directionPlayer = true;
    }
    else if (direction == Direction::Right)
    {
        directionPlayer = false;
    }
    if (GetOwner()->GetPosition().GetX() > SceneManager::GetWindowWidth()
        || GetOwner()->GetPosition().GetY() > SceneManager::GetWindowHeight()
        || GetOwner()->GetPosition().GetY() < 0
        || GetOwner()->GetPosition().GetX() < 0
        )
    { 
        GetOwner()->GetComponent<Armes>()->ClearBullets();
        this->Die();
        SceneManager::GetActiveScene()->RemoveGameObject(GetOwner());
        SceneManager::RunScene("SceneMainMenu");
    }
}