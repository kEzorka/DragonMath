#pragma once
#include "dragon.h"
class BlackDragon : public Dragon {
public:
	BlackDragon();
	virtual std::pair<int, int> question() override final;
};

BlackDragon::BlackDragon() {
    operator_ = '*';
}

std::pair<int, int> BlackDragon::question() {
    int first_summand = RandNum() % 1000;
    int second_summand = RandNum() % 1000;
    answer_ = first_summand * second_summand;
    return std::make_pair(first_summand, second_summand);
}

