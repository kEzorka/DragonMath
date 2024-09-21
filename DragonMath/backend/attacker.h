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
	int hp_;
	int damage_;
	bool is_enemy_ = false;
};

