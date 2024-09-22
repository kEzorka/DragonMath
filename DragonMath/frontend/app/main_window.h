#pragma once
#include <SFML/Graphics.hpp>
#include "push_button.h"

class PausedWindow;

class MainWindow {
public:
	//friend PausedWindow;
	MainWindow() = default;
	void exec();
	virtual void draw();

protected:
	virtual void setup();
	sf::RenderWindow* window = nullptr;
	sf::Font* cur_font = nullptr;

private:
	void InteractingWithScreen();

	sf::Event* event_ = nullptr;
	sf::Text* text = nullptr;

	PausedWindow* p = nullptr;
	MainWindow* cur_window_ = nullptr;
};
