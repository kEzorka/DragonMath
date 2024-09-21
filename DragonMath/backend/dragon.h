#pragma once
#include "enemy.h"

class Dragon : public Enemy {
public:
	Dragon();
	Dragon(int hp);
	virtual bool isEnemy() override final;
	virtual std::pair<int, int> question();
	virtual bool checkAnswer(int answer);
	char getOperator() const { return operator_; }

protected:
	int answer_ = 0;
	char operator_;
};

Dragon::Dragon() {
	damage_ = INF;
}

Dragon::Dragon(int hp) {
	hp_ = hp;
}

bool Dragon::checkAnswer(int answer) {
	return answer == answer_;
}

bool Dragon::isEnemy() {
	return false;
}

std::pair<int, int> Dragon::question() {
	return std::pair<int, int>();
}

