#include "Components/Entities/EnemyAbstract.h"
#include "Scenes/SceneGame1.h"
#include "Components/SpriteRenderer.h"

class Grunt : public EnemyAbstract
{
public:
    enum Direction { Left, Right };
    Grunt();
    Grunt(int _hp, int _damage, float _speed);
    void setDirection(Direction direction);
    void MouvementGrunt();
private:
    Sprite sprite;
    Direction direction;
};