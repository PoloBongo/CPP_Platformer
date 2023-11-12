#include "Components/Entities/EnemyAbstract.h"
#include "SceneManager.h"

EnemyAbstract::EnemyAbstract() : Entity() {}
EnemyAbstract::EnemyAbstract(int _hp, int _damage, float _speed) : Entity(_hp, _damage, _speed) {}

void EnemyAbstract::Update(sf::Time _delta)
{
	Entity::Update(_delta);

	if (GetOwner()->GetPosition().GetX() > SceneManager::GetWindowWidth()
		|| GetOwner()->GetPosition().GetY() > SceneManager::GetWindowHeight()
		|| GetOwner()->GetPosition().GetY() < 0
		|| GetOwner()->GetPosition().GetX() < 0
		)
	{
		this->Die();
	}
}

void EnemyAbstract::Die()
{
	SceneManager::GetActiveGameScene()->RemoveEnemy(GetOwner());
	Entity::Die();
}