#pragma once
#include "dragon.h"

class RedDragon : virtual public Dragon {
public:
    RedDragon() {
        operation_ = '-';
    }
	virtual std::pair<int, int> question() override final {
        int first_summand = RandNum() % 100;
        int second_summand = RandNum() % 100;
        answer_ = first_summand - second_summand;
        return std::make_pair(first_summand, second_summand);
    }
};
