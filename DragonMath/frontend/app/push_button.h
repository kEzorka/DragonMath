#pragma once
#include "main_window.h"

class PushButton {
public:
	PushButton();

	void setSize(const sf::Vector2f& size);
	void setString(const std::string& text);
	void setColor(const sf::Color& color);
	void setFillColor(const sf::Color& color);
	void setPosition(const sf::Vector2f& pos);
	void setFont(const sf::Font& font);
	void setLayout(sf::RenderWindow* window);

	sf::Vector2f getSize() const;
	std::string getString() const;
	sf::Vector2f getPosition() const;
	sf::Color getColor() const;

	bool isClicked();

	void draw() const;

private:
	sf::Color color_;
	sf::RenderWindow* window_ = nullptr;
	bool is_clicked_ = false;
	sf::RectangleShape button_;
	sf::Text text_;
	float width_;
	float height_;
	const double kCoefDarknessOntoButton = 0.7;
	const double kCoefDarknessPressedButton = 0.5;
};
