#pragma once

#include "attacker.h"

class Hero : virtual public Attacker {
public:
	Hero() = default;
	Hero(const Hero&) = default;
	Hero(Hero&&) = default;

	virtual bool isEnemy() const override final;

	Hero& operator=(const Hero&) = default;
	Hero& operator=(Hero&&) = default;

	virtual ~Hero() = default;
};

bool Hero::isEnemy() const {
	return is_enemy_;
}
