#pragma once

#include <random>
#include <chrono>
#include <utility>

class Attacker {
public:
	Attacker();
	virtual bool isEnemy() = 0;
	virtual void becomeEnemy();
	virtual bool isAlive();
	void virtual attack(Attacker& enemy);
	virtual ~Attacker() = default;

protected:
    std::mt19937 RandNum = std::mt19937{ static_cast<std::mt19937::result_type>(
	std::chrono::steady_clock::now().time_since_epoch().count() )};
	const int INF = -1;
	int hp_ = 0;
	int damage_ = 0;
	bool is_enemy_ = false;
};

Attacker::Attacker() : hp_(1), damage_(1) {}

void Attacker::becomeEnemy() {
	is_enemy_ = true;
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

