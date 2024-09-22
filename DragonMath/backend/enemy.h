#pragma once
#include "attacker.h"

class Enemy : virtual public Attacker {
public:
	virtual bool isEnemy() const override;

private:

};

bool Enemy::isEnemy() const {
	return is_enemy_;
}
