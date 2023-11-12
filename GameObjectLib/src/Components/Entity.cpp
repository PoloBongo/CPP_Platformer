#include "Components/Entity.h"
#include "SceneManager.h"
#include "AudioManager.h"

Entity::Entity() : healthPoint(100), maxHealthPoint(100), damage(10), speed(20.f) {}
Entity::Entity(int _hp, int _damage, float _speed) : healthPoint(_hp), maxHealthPoint(_hp), damage(_damage), speed(_speed) {}

void Entity::TakeDamage(int _damage) {
	if (healthPoint > damage)
	{
		healthPoint -= _damage;
	}

	if(healthPoint <= 0)
	{
		this->Die();
	}
}

void Entity::Die() {
	healthPoint = 0;
	AudioManager::PlaySound("dead");
	SceneManager::GetActiveGameScene()->RemoveGameObject(GetOwner());
}

void Entity::Update(sf::Time _delta) {
	Component::Update(_delta);

	if (GetOwner()->GetPosition().GetX() > SceneManager::GetWindowWidth()
		|| GetOwner()->GetPosition().GetY() > SceneManager::GetWindowHeight()
		|| GetOwner()->GetPosition().GetY() < 0
		|| GetOwner()->GetPosition().GetX() < 0
		)
	{
		this->Die();
	}
}