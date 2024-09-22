#pragma once
#include "enemy.h"

class Dragon : virtual public Enemy {
public:
	Dragon();
	Dragon(int hp);
	Dragon(const Dragon&) = default;
	Dragon(Dragon&&) = default;

	virtual bool isEnemy() const override final;

	virtual std::pair<int, int> question();
	virtual bool checkAnswer(int answer) const;

	char getOperation() const { return operation_; }

	Dragon& operator=(const Dragon&) = default;
	Dragon& operator=(Dragon&&) = default;

	virtual ~Dragon() = default;

protected:
	int answer_ = 0;
	char operation_;
};

inline Dragon::Dragon() : operation_(' ') {
	damage_ = INF;
}

inline Dragon::Dragon(int hp) : operation_(' ') {
	hp_ = hp;
}


bool Dragon::checkAnswer(int answer) const {
	return answer == answer_;
}

bool Dragon::isEnemy() const {
	return is_enemy_;
}

std::pair<int, int> Dragon::question() {
	return std::pair<int, int>();
}

