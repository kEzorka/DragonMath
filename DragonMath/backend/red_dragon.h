#pragma once
#include "dragon.h"

class RedDragon : public Dragon {
public:
	RedDragon();
	virtual std::pair<int, int> question() override final;
};

