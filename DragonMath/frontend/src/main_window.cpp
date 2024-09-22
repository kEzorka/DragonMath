#include "../app/paused_window.h"
#include "../app/main_window.h"
#include <iostream>


void MainWindow::setup() {
	event_ = new sf::Event();
	cur_font = new sf::Font();
	cur_font->loadFromFile("frontend/assets/fonts/baseFont.ttf");
	window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Let's Math!", sf::Style::Close);
	p = new PausedWindow();
	p->setLayout(window);
	p->setFont(cur_font);
	cur_window_ = p;
	text = new sf::Text();
	text->setFont(*cur_font);
	text->setString("111");
	text->setPosition(sf::Vector2f(0, 0));
	text->setCharacterSize(24);
	text->setFillColor(sf::Color::Black);
}

void MainWindow::exec() {
	setup();
	while (window->isOpen()) {
		InteractingWithScreen();

		window->clear(sf::Color(102, 102, 153));
		cur_window_->draw();
		window->display();
	}
}

void MainWindow::InteractingWithScreen() {
	while (window->pollEvent(*event_)) {
		if (event_->type == sf::Event::Closed) {
			window->close();
		}

	}
}

void MainWindow::draw() {
	window->draw(*text);
}

