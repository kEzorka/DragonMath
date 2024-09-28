#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class TextBox {
public:
    TextBox();
    TextBox(const TextBox&) = default;
    TextBox(TextBox&&) = default;
    TextBox& operator=(const TextBox&) = default;
    TextBox& operator=(TextBox&&) = default;
    ~TextBox() = default;

    TextBox(const sf::Font& font, const float& x, const float& y);


    void Event(const sf::Event& event);
    void draw() const;
    void clear();
    void setLayout(sf::RenderWindow* win);


    void setPosition(const float& x, const float& y);
    void setPosition(const sf::Vector2f& pos);
    void setFont(const sf::Font& font);
    void setSize(const float& x, const float& y);
    void setSize(const sf::Vector2f& size);
    void setString(const std::string& str);
    void setSheetHeight(const float& sheet_height);
    void setSheetWidth(const float& sheet_widthed);
    void setEnterFalse();
    void setColor(const sf::Color& color);
    void setFillColor(const sf::Color& color);
    void setCharacterSize(const int& size);


    std::string getText() const;
    float getSheetHeight() const;
    float getSheetWidth() const;


    bool isEntered() const;

private:
    sf::RenderWindow* window = nullptr;
    sf::RectangleShape text_box;
    sf::Text text;
    std::string output;
    float sheet_height_ = 0.f;
    float sheet_width_ = 0.f;
    bool enter_pressed = false;
};

class FocusController {
public:
    FocusController(TextBox* cur_obj = nullptr) : m_object(cur_obj) {}

    void setFocusObject(TextBox*);

    TextBox* getFocusObject() {
        return m_object;
    }
private:
    TextBox* m_object;
};