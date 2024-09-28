#include "../app/push_button.h"
#include <iostream>

PushButton::PushButton() : color_(sf::Color(0, 0, 0)), height_(0), width_(0){
	button_.setSize(sf::Vector2f(width_, height_));
	button_.setPosition(sf::Vector2f(0, 0));
	text_.setPosition(0, 0);
	button_.setFillColor(color_);
	text_.setFillColor(sf::Color(255, 255, 255));
}

void PushButton::setString(const std::string& text) {
	text_.setString(text);
	text_.setCharacterSize(static_cast<unsigned int>(button_.getLocalBounds().height / 2.5));
	setPosition(button_.getPosition());
}

void PushButton::setColor(const sf::Color& color) {
	text_.setFillColor(color);
}

void PushButton::setFillColor(const sf::Color& color) {
	color_ = color;
	button_.setFillColor(color_);
}

void PushButton::setLayout(sf::RenderWindow* window) {
	window_ = window;
}

sf::Vector2f PushButton::getSize() const {
	return button_.getSize();
}

std::string PushButton::getString() const {
	return text_.getString();
}

sf::Vector2f PushButton::getPosition() const {
	return button_.getPosition();
}

sf::Color PushButton::getColor() const {
	return color_;
}

void PushButton::setFont(const sf::Font& font) {
	text_.setFont(font);
}

void PushButton::setSize(const sf::Vector2f& size) {
	button_.setSize(size);
	width_ = size.x;
	height_ = size.y;
	text_.setCharacterSize(static_cast<unsigned int>(button_.getLocalBounds().height / 2.5));
	setPosition(button_.getPosition());
}

void PushButton::setPosition(const sf::Vector2f& pos) {
	button_.setPosition(pos);
	float x = (pos.x + static_cast<float>(width_ / 2)) - (text_.getGlobalBounds().width / 2);
	float y = (pos.y + static_cast<float>(height_ / 2.7)) - (text_.getLocalBounds().height / 2);
	text_.setPosition(x, y);
}

void PushButton::draw() const {
	window_->draw(button_);
	window_->draw(text_);
}

bool PushButton::isClicked() {
	float mouseX = static_cast<float>(sf::Mouse::getPosition(*window_).x);
	float mouseY = static_cast<float>(sf::Mouse::getPosition(*window_).y);
	float btnPosX = button_.getPosition().x;
	float btnPosY = button_.getPosition().y;
	float btnxPosWidth = button_.getPosition().x + width_;
	float btnyPosHeight = button_.getPosition().y + height_;
	if (mouseX < btnxPosWidth &&
		mouseX > btnPosX &&
		mouseY < btnyPosHeight &&
		mouseY > btnPosY) {
		sf::Color color = color_;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && is_clicked_ == false) {
			color.r = static_cast<uint8_t>(kCoefDarknessPressedButton * static_cast<double>(color.r));
			color.g = static_cast<uint8_t>(kCoefDarknessPressedButton * static_cast<double>(color.g));
			color.b = static_cast<uint8_t>(kCoefDarknessPressedButton * static_cast<double>(color.b));
			button_.setFillColor(color);
			is_clicked_ = true;
		} else {
			color.r *= static_cast<uint8_t>(kCoefDarknessOntoButton * static_cast<double>(color.r));
			color.g *= static_cast<uint8_t>(kCoefDarknessOntoButton * static_cast<double>(color.g));
			color.b *= static_cast<uint8_t>(kCoefDarknessOntoButton * static_cast<double>(color.b));
			button_.setFillColor(color);
			is_clicked_ = false;
		}
	} else { 
		button_.setFillColor(color_);
	}
	return is_clicked_;
}
