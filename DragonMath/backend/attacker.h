#pragma once

#include <random>
#include <chrono>
#include <utility>

class Attacker {
public:
	Attacker();
	Attacker(const Attacker&) = default;
	Attacker(Attacker&&) = default;

	virtual bool isEnemy() const = 0;
	virtual bool isAlive();

	virtual void becomeEnemy();
	void virtual attack(Attacker& enemy);

	virtual void setHp(const int& hp);
	virtual void setDamage(const int& damage);

	virtual int getHp() const;
	virtual int getDamage() const;

	virtual Attacker& operator=(const Attacker&) = default;
	virtual Attacker& operator=(Attacker&&) = default;

	virtual ~Attacker() = default;
	const int INF = -1;

protected:
    std::mt19937 RandNum = std::mt19937{ static_cast<std::mt19937::result_type>(
	std::chrono::steady_clock::now().time_since_epoch().count() )};
	int hp_;
	int damage_;
	bool is_enemy_ = false;
};

Attacker::Attacker() : hp_(RandNum() % 100 + 100), damage_(RandNum() % 10 + 10) {}

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

inline void Attacker::setHp(const int& hp) {
	hp_ = hp;
}

inline void Attacker::setDamage(const int& damage) {
	damage_ = damage;
}

inline int Attacker::getHp() const {
	return hp_;
}

inline int Attacker::getDamage() const {
	return damage_;
}

