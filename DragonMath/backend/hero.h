#pragma once

#include "attacker.h"

class Hero : virtual public Attacker {
public:
	Hero() = default;
	Hero(const Hero&) = default;
	Hero(Hero&&) = default;

	virtual bool isEnemy() const override final {
		return is_enemy_;
	}

	Hero& operator=(const Hero&) = default;
	Hero& operator=(Hero&&) = default;

	void setExperience(const int& exp) {
		experience_ = exp;
	}

	int getExperience() const {
		return experience_;
	}

	virtual ~Hero() = default;
private:
	int experience_ = 0;
};
