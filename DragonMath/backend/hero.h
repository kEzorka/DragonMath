#pragma once
#include "attacker.h"

class Hero : public Attacker {
public:
	Hero();
	virtual bool isEnemy() override final;
	void init(const std::string& name) {
		name_ = name;
	}
	~Hero() = default;
private:
	std::string name_ = "";
	int expirience_ = 0;
};

