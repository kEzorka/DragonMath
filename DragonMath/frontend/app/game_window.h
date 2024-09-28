#pragma once

#include "main_window.h"
#include "../../backend/black_dragon.h"
#include "../../backend/red_dragon.h"
#include "../../backend/green_dragon.h"
#include "../../backend/hero.h"
#include "../app/TextBox.h"

#include <vector>

class GameWindow : virtual public MainWindow {
	friend MainWindow;
public:
	void setLayout(sf::RenderWindow* win);
	void setFont(sf::Font* font);

protected:
	virtual void draw() override;
	virtual void setup() override;
	virtual MainWindow* InteractingWithScreen() override;
	virtual void setTexturesType(TexturesType* type) override;
	virtual void updateTexturesAndSprites() override;

private:
	sf::Texture* black_dragon_txr = nullptr;
	sf::Texture* green_dragon_txr = nullptr;
	sf::Texture* red_dragon_txr = nullptr;
	sf::Texture* knight_first_txr = nullptr;
	sf::Texture* knight_second_txr = nullptr;
	sf::Texture* knight_third_txr = nullptr;
	sf::Texture* background_first_txr = nullptr;
	sf::Texture* background_second_txr = nullptr;
	sf::Texture* background_third_txr = nullptr;
	sf::Texture* dragon_hp_txr = nullptr;
	sf::Texture* knight_hp_txr = nullptr;
	sf::Texture* dragon_attack_txr = nullptr;
	sf::Texture* knight_attack_txr = nullptr;

	sf::Sprite* black_dragon_spr = nullptr;
	sf::Sprite* green_dragon_spr = nullptr;
	sf::Sprite* red_dragon_spr = nullptr;
	sf::Sprite* knight_spr = nullptr;
	sf::Sprite* background_spr = nullptr;
	sf::Sprite* dragon_hp_spr = nullptr;
	sf::Sprite* knight_hp_spr = nullptr;
	sf::Sprite* dragon_attack_spr = nullptr;
	sf::Sprite* knight_attack_spr = nullptr;

	sf::Sprite* cur_enemy_spr = nullptr;
	sf::Texture* cur_hero_txr = nullptr;

	void makeShtypaTexturesAndSprites();
	void makeStdTexturesAndSprites();

	sf::Text* dragon_hp_text = nullptr;
	sf::Text* dragon_attack_text = nullptr;
	sf::Text* knight_hp_text = nullptr;
	sf::Text* knight_attack_text = nullptr;

	void InteractingWithStd(const sf::Event& event);
	void InteractingWithShtypa(const sf::Event& event);

	void drawShtypa();
	void drawStd();

	Hero* hero_ = nullptr;
	Enemy* enemy_ = nullptr;

	void makeGameCharacters();


	sf::Text* question_text_ = nullptr;
	sf::RectangleShape* question_rect_ = nullptr;

	sf::Text* experience_text_ = nullptr;
	sf::RectangleShape* experience_rect_ = nullptr;

	TextBox* answer_tb_ = nullptr;
	FocusController* cur_focus = nullptr;
	
	void makeQuestion();
	void AskQuestion();
	void UpdateQuestionTextPos();
	void UpdateShtypaHpAndDamage();
	void UpdateStdHpAndDamage();
	void callNewEnemy();
	void chooseNewBackground();
	void makeCharactersForFirstBackground();
	void makeCharactersForSecondBackground();
	void makeCharactersForThirdBackground();
	void UpdateExperiencePosition();
	void MakeNewTextures();
	bool entered = false;

	bool keyPressedOneTime = false;
};

