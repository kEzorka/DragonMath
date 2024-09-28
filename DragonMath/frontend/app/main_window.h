#pragma once
#include <SFML/Graphics.hpp>
#include "push_button.h"
//
class PausedWindow;
class GameWindow;

class MainWindow {
protected:
	enum TexturesType {
		Shtypa,
		Std
	};

public:
	//friend PausedWindow;
	MainWindow() = default;
	void exec();

protected:
	virtual void draw();
	sf::RenderWindow* window = nullptr;
	sf::Font* cur_font = nullptr;
	sf::Font* normal_font = nullptr;
	virtual void setup();
	virtual MainWindow* InteractingWithScreen();
	TexturesType* cur_textures_type_ = nullptr;
	virtual void setTexturesType(TexturesType* type) {
		cur_textures_type_ = type;
	};
	virtual void updateTexturesAndSprites() {}
	bool* keyPressedOneTime = nullptr;

private:
	void makePausedWindow();
	void makeGameWindow();

	sf::Event* event_ = nullptr;

	PausedWindow* paused_window_ = nullptr;
	GameWindow* game_window_ = nullptr;
	MainWindow* cur_window_ = nullptr;
};
