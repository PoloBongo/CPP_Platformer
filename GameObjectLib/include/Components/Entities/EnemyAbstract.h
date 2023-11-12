#pragma once
#include "Components/Entity.h"
#include "Scene.h"

class EnemyAbstract : public Entity {
public:
    EnemyAbstract();
    EnemyAbstract(int _hp, int _damage, float _speed);

    void Update(sf::Time _delta) override;

    void Die() override;
};