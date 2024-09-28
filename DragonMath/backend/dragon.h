#pragma once
#include "enemy.h"

class Dragon : virtual public Enemy {
public:
	Dragon() {
		operation_ = ' ';
		damage_ = INF;
	}
	Dragon(int hp) {
		operation_ = ' ';
		hp_ = hp;
	}
	Dragon(const Dragon&) = default;
	Dragon(Dragon&&) = default;

	virtual std::pair<int, int> question() override {
		return std::pair<int, int>();
	}
	virtual bool checkAnswer(int answer) const override {
		return answer == answer_;
	}

	virtual char getOperation() const override { return operation_; }

	Dragon& operator=(const Dragon&) = default;
	Dragon& operator=(Dragon&&) = default;

	virtual ~Dragon() = default;

protected:

};
