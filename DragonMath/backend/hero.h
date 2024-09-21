#pragma once

#include "attacker.h"

class Hero : public Attacker {
public:
	Hero();
	virtual bool isEnemy() override final;
};

Hero::Hero() {}

bool Hero::isEnemy() {
	return is_enemy_;
}
