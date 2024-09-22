#include "../app/paused_window.h"

PausedWindow::PausedWindow() {
	cur_font = new sf::Font();
	start_game_pbt_ = new PushButton();
	start_game_pbt_->setSize(sf::Vector2f(100, 100));
	start_game_pbt_->setPosition(sf::Vector2f(100, 100));
}

void PausedWindow::setLayout(sf::RenderWindow* win) {
	window = win;
	start_game_pbt_->setLayout(window);
}

void PausedWindow::setFont(sf::Font* font) {
	cur_font = font;
	start_game_pbt_->setFont(*cur_font);
}

void PausedWindow::draw() {
	start_game_pbt_->draw();
}
