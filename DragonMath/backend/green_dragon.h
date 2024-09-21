#pragma once
#include "dragon.h"
class GreenDragon : public Dragon {
public:
	GreenDragon();
	virtual std::pair<int, int> question() override final;
};

