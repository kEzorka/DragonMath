#pragma once
#include "enemy.h"

class Dragon : public Enemy {
public:
	Dragon();
	Dragon(int hp);
	virtual bool isEnemy() override final;
	virtual std::pair<int, int> question() = 0;
	virtual bool checkAnswer(int answer);
	char getOperator() const { return operator_; }

protected:
	int answer_ = 0;
	char operator_;
};

