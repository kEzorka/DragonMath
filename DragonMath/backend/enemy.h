#pragma once
#include "attacker.h"

class Enemy : public Attacker {
public:
	virtual bool isEnemy() override = 0;

private:

};

