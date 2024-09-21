#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class TextBox {
public:
    TextBox() {
        output = "";
        fill = "";
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(24);
        text_box.setFillColor(sf::Color(204, 102, 153));
    }

    TextBox(sf::Font& font, float x, float y) {
        text.setFont(font);
        sheet_width_ = x;
        sheet_height_ = y;
        output = "";
        fill = "";
        text_box.setSize(sf::Vector2f(x, y));
    }

    void Event(const sf::Event& event);

    void setPosition(float x, float y) {
        text_box.setPosition(x, y);
    }

    void setFont(const sf::Font& font) {
        text.setFont(font);
    }

    void setSize(float x, float y) {
        text_box.setSize(sf::Vector2f(x, y));
        sheet_width_ = x;
        sheet_height_ = y;
    }

    void setText(std::string str) {
        output = str;
    }

    std::string getText() {
        return output;
    }

    void setSheetHeight(float sheet_height) {
        sheet_height_ = sheet_height;
    }

    float getSheetHeight() const {
        return sheet_height_;
    }

    void setSheetWidth(float sheet_widthed) {
        sheet_width_ = sheet_widthed;
    }

    float getSheetWidth() const {
        return sheet_width_;
    }

    bool isEntered() const {
        return enter_pressed;
    }

    void setEnterFalse() {
        enter_pressed = false;
    }

    void clear() {
        output = "";
        fill = "";
        text.setString("");
    }

    sf::RectangleShape text_box;
    sf::Text text;

private:
    std::string output, fill;
    float sheet_height_ = 0.0;
    float sheet_width_ = 0.0;
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