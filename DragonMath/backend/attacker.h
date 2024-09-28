#pragma once

#include <random>
#include <chrono>
#include <utility>

static std::mt19937 RandNum = std::mt19937{ static_cast<std::mt19937::result_type>(
	std::chrono::steady_clock::now().time_since_epoch().count()) };

class Attacker {
public:
	Attacker() : hp_(RandNum() % 100 + 100), damage_(RandNum() % 30 + 30) {}
	Attacker(const Attacker&) = default;
	Attacker(Attacker&&) = default;

	virtual bool isEnemy() const = 0;
	virtual bool isAlive() {
		return (hp_ <= 0 ? false : true);
	}

	virtual void becomeEnemy() {
		is_enemy_ = true;
	}
	void virtual attack(Attacker& enemy) {
		if (damage_ == INF) {
			enemy.hp_ = 0;
		} else {
			enemy.hp_ = std::max(enemy.hp_ - damage_, 0);
		}
	}

	virtual inline void setHp(const int& hp) {
		hp_ = hp;
	}
	virtual inline void setDamage(const int& damage) {
		damage_ = damage;
	}

	virtual inline int getHp() const {
		return hp_;
	}
	virtual inline int getDamage() const {
		return damage_;
	}

	virtual Attacker& operator=(const Attacker&) = default;
	virtual Attacker& operator=(Attacker&&) = default;

	virtual ~Attacker() = default;
	const int INF = -1;

protected:
	int hp_;
	int damage_;
	bool is_enemy_ = false;
};
