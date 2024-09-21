#include "dragon.h"

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
