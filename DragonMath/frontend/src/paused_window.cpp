#include "../app/paused_window.h"

void PausedWindow::setup() {
	shop_pbt_ = new PushButton();
	switch_to_other_pbt_ = new PushButton();
	restart_pbt_ = new PushButton();
	background_first_ = new sf::RectangleShape();
	background_second_ = new sf::RectangleShape();

	background_first_->setSize(sf::Vector2f(800, 400));
	background_first_->setPosition(sf::Vector2f((1200 - background_first_->getSize().x) / 2,
		(800 - background_first_->getSize().y) / 2));
	background_first_->setFillColor(sf::Color(102, 102, 153, 230));

	background_second_->setSize(sf::Vector2f(1200, 800));
	background_second_->setPosition(sf::Vector2f((1200 - background_second_->getSize().x) / 2,
		(800 - background_second_->getSize().y) / 2));
	background_second_->setFillColor(sf::Color(255, 255, 255, 40));

	shop_pbt_->setSize(sf::Vector2f(150, 150));
	shop_pbt_->setPosition(sf::Vector2f(
		(background_first_->getSize().x - shop_pbt_->getSize().x * 3 - 100)
		/ 2 + background_first_->getPosition().x,
		(background_first_->getSize().y - shop_pbt_->getSize().y)
		/ 2 + background_first_->getPosition().y));
	shop_pbt_->setFont(*cur_font);
	shop_pbt_->setLayout(window);
	shop_pbt_->setFillColor(sf::Color(220, 220, 220, 50));

	switch_to_other_pbt_->setSize(shop_pbt_->getSize());
	switch_to_other_pbt_->setPosition(shop_pbt_->getPosition()
		+ sf::Vector2f(50 + shop_pbt_->getSize().x, 0));
	switch_to_other_pbt_->setFont(*cur_font);
	switch_to_other_pbt_->setLayout(window);
	switch_to_other_pbt_->setFillColor(shop_pbt_->getColor());

	restart_pbt_->setSize(shop_pbt_->getSize());
	restart_pbt_->setPosition(switch_to_other_pbt_->getPosition()
		+ sf::Vector2f(50 + switch_to_other_pbt_->getSize().x, 0));
	restart_pbt_->setFont(*cur_font);
	restart_pbt_->setLayout(window);
	restart_pbt_->setFillColor(shop_pbt_->getColor());

	setTextures();
}

MainWindow* PausedWindow::InteractingWithScreen() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		} else if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode == 27) {
				return this;
			}
		}
		if (shop_pbt_->isClicked()) {

		} else if (switch_to_other_pbt_->isClicked()) {
			/*if (*cur_textures_type_ == TexturesType::Std) {
				*cur_textures_type_ = TexturesType::Shtypa;
			} else if (*cur_textures_type_ == TexturesType::Shtypa) {
				*cur_textures_type_ = TexturesType::Std;
			}

			return nullptr;*/
		} else if (restart_pbt_->isClicked()) {

		}

	}
	return nullptr;
}

void PausedWindow::updateTexturesAndSprites() {
	switch_to_other_text_->setString("switch\n  to\n std");
	sf::Vector2f tmp_pos = switch_to_other_pbt_->getPosition();
	sf::Vector2f tmp_size = switch_to_other_pbt_->getSize();
	float x = (tmp_pos.x + static_cast<float>(tmp_size.x / 2)) - (switch_to_other_text_->getLocalBounds().width / 2);
	float y = (tmp_pos.y + static_cast<float>(tmp_size.y / 2.7)) - (switch_to_other_text_->getLocalBounds().height / 2.f);
	switch_to_other_text_->setPosition(x, y);
}

void PausedWindow::setTextures() {
	shop_txr_ = new sf::Texture();
	restart_txr_ = new sf::Texture();

	shop_spr_ = new sf::Sprite();
	restart_spr_ = new sf::Sprite();

	switch_to_other_text_ = new sf::Text();


	shop_txr_->loadFromFile("frontend/assets/images/DragonsAndKnights/shop.png");
	restart_txr_->loadFromFile("frontend/assets/images/DragonsAndKnights/restart.png");

	shop_spr_->setTexture(*shop_txr_);
	restart_spr_->setTexture(*restart_txr_);

	shop_spr_->setPosition(shop_pbt_->getPosition());
	restart_spr_->setPosition(restart_pbt_->getPosition());

	switch_to_other_text_->setString(" switch \n   to   \n Shtypa ");
	switch_to_other_text_->setFont(*cur_font);
	sf::Vector2f tmp_pos = switch_to_other_pbt_->getPosition();
	sf::Vector2f tmp_size = switch_to_other_pbt_->getSize();
	float x = (tmp_pos.x + static_cast<float>(tmp_size.x / 2)) - (switch_to_other_text_->getLocalBounds().width / 2);
	float y = (tmp_pos.y + static_cast<float>(tmp_size.y / 2.7)) - (switch_to_other_text_->getLocalBounds().height / 2.f);
	switch_to_other_text_->setPosition(x, y);
}

void PausedWindow::setTexturesType(TexturesType* type) {
	cur_textures_type_ = type;
}

void PausedWindow::setLayout(sf::RenderWindow* win) {
	window = win;
}

void PausedWindow::setFont(sf::Font* font) {
	cur_font = font;
}

void PausedWindow::draw() {
	window->draw(*background_second_);
	window->draw(*background_first_);
	shop_pbt_->draw();
	switch_to_other_pbt_->draw();
	restart_pbt_->draw();

	window->draw(*shop_spr_);
	window->draw(*restart_spr_);
	window->draw(*switch_to_other_text_);
}
