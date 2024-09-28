#pragma once

#include "main_window.h"

class PausedWindow : virtual public MainWindow {
	friend MainWindow;
public:
	void setLayout(sf::RenderWindow* win);
	void setFont(sf::Font* font);
	
protected:
	virtual void draw() override;
	virtual void setup() override;
	virtual void setTexturesType(TexturesType* type) override;
	virtual MainWindow* InteractingWithScreen() override;
	virtual void updateTexturesAndSprites() override;

private:
	PushButton* shop_pbt_ = nullptr;
	PushButton* switch_to_other_pbt_ = nullptr;
	PushButton* restart_pbt_ = nullptr;
	sf::RectangleShape* background_first_ = nullptr;
	sf::RectangleShape* background_second_ = nullptr;

	
	sf::Texture* shop_txr_ = nullptr;
	sf::Texture* restart_txr_ = nullptr;

	sf::Sprite* shop_spr_ = nullptr;
	sf::Sprite* restart_spr_ = nullptr;

	sf::Text* switch_to_other_text_ = nullptr;

	void setTextures();
};

