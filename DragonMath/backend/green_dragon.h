#pragma once
#include "dragon.h"
class GreenDragon : virtual public Dragon {
public:
	GreenDragon();
	virtual std::pair<int, int> question() override final;
};

GreenDragon::GreenDragon() {
    operation_ = '+';
}

std::pair<int, int> GreenDragon::question() {
    int first_summand = RandNum() % 10000;
    int second_summand = RandNum() % 10000;
    answer_ = first_summand + second_summand;
    return std::make_pair(first_summand, second_summand);
}

