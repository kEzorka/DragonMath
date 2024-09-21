#pragma once
#include "attacker.h"

class Enemy : public Attacker {
public:
	virtual bool isEnemy();

private:

};

bool Enemy::isEnemy() {
	return is_enemy_;
}
