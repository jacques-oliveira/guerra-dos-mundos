#include <iostream>

enum EnemyType{
    Boss,
    Soldier,
    Guardian
};

class Enemy{
public:
    Enemy(EnemyType e);
    ~Enemy();
    const EnemyType enemytype;

private:
    EnemyType getEnemytype();
};


