#pragma once

#include "main_window.h"

class PausedWindow : virtual public MainWindow {
public:
	PausedWindow();

	void setLayout(sf::RenderWindow* win);
	void setFont(sf::Font* font);
	
protected:
	virtual void draw() override;

private:
	PushButton* start_game_pbt_;

};

