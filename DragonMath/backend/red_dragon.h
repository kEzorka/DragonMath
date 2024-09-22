#pragma once
#include "dragon.h"

class RedDragon : virtual public Dragon {
public:
	RedDragon();
	virtual std::pair<int, int> question() override final;
};

RedDragon::RedDragon() {
    operation_ = '-';
}

std::pair<int, int> RedDragon::question() {
    int first_summand = RandNum() % 10000;
    int second_summand = RandNum() % 10000;
    answer_ = first_summand - second_summand;
    return std::make_pair(first_summand, second_summand);
}
