#pragma once
#include "attacker.h"

class Enemy : virtual public Attacker {
public:
	virtual bool isEnemy() const override {
		return is_enemy_;
	}
	virtual std::pair<int, int> question() {
		return std::pair<int, int>();
	}
	virtual char getOperation() const { return operation_; }
	virtual bool checkAnswer(int answer) const {
		return answer == answer_;
	}

protected:
	int answer_ = 0;
	char operation_ = ' ';

private:

};
