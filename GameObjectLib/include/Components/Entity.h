#pragma once
#include "Component.h"
class Entity : public Component
{
public:
    Entity();
    Entity(int _hp, int _damage, float _speed);

    int GetHealthPoint() const { return healthPoint; }
    int GetMaxHealthPoint() const { return maxHealthPoint; }
    int GetDamage() const { return damage; }
    float GetSpeed() const { return speed; }
    void SetHealthPoint(const int _hp)  { healthPoint = _hp;}
    void SetMaxHealthPoint(const int _maxHp)  { maxHealthPoint = _maxHp;}
    void SetDamage(const int _damage)  { damage = _damage; }
    void SetSpeed(const float _speed)  {  speed = _speed; }

    void TakeDamage(int damage);
    virtual void Die();
    void Update(sf::Time _delta) override;

protected:
    int healthPoint;
    int maxHealthPoint;
    int damage;
    float speed;
};
