#pragma once
#include "dragon.h"
class BlackDragon : public Dragon {
public:
	BlackDragon();
	virtual std::pair<int, int> question() override final;
};

