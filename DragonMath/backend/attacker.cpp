#include "attacker.h"

Attacker::Attacker() : hp_(RandNum() % 100 + 100), damage_(RandNum() % 10 + 10) {}

void Attacker::becomeEnemy() {
	is_enemy = true;
}

bool Attacker::isAlive() {
	return (hp_ <= 0 ? false : true);
}

void Attacker::attack(Attacker& enemy) {
	if (damage_ == INF) {
		enemy.hp_ = 0;
	} else {
		enemy.hp_ = std::max(enemy.hp_ - damage_, 0);
	}
}
