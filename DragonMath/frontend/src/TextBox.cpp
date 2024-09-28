#include "../app/TextBox.h"

TextBox::TextBox() {
    output = "";
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(24);
    text_box.setFillColor(sf::Color(204, 102, 153));
}

TextBox::TextBox(const sf::Font& font, const float& x, const float& y) {
    text.setFont(font);
    sheet_width_ = x;
    sheet_height_ = y;
    output = "";
    text_box.setSize(sf::Vector2f(x, y));
}

void TextBox::setPosition(const float& x, const float& y) {
    text_box.setPosition(x, y);
}

void TextBox::setPosition(const sf::Vector2f& pos) {
    text_box.setPosition(pos);
    text.setString("1");
    sf::Vector2f tmp_pos = text_box.getPosition();
    sf::Vector2f tmp_size = text_box.getSize();
    float x = (tmp_pos.x + static_cast<float>(tmp_size.x / 2)) - (text.getLocalBounds().width / 2);
    float y = (tmp_pos.y + static_cast<float>(tmp_size.y / 2.7)) - (text.getLocalBounds().height / 1.3f);
    text.setPosition(x, y);
    text.setString("");
}

void TextBox::clear() {
    output = "";
    text.setString(output);
}

void TextBox::setFont(const sf::Font& font) {
    text.setFont(font);
}

void TextBox::setSize(const float& x, const float& y) {
    text_box.setSize(sf::Vector2f(x, y));
    sheet_width_ = x;
    sheet_height_ = y;
}

void TextBox::setSize(const sf::Vector2f& size) {
    text_box.setSize(size);
}

void TextBox::setString(const std::string& str) {
    output = str;
}

std::string TextBox::getText() const {
    return output;
}

void TextBox::setSheetHeight(const float& sheet_height) {
    sheet_height_ = sheet_height;
}

float TextBox::getSheetHeight() const {
    return sheet_height_;
}

void TextBox::setSheetWidth(const float& sheet_widthed) {
    sheet_width_ = sheet_widthed;
}

float TextBox::getSheetWidth() const {
    return sheet_width_;
}

bool TextBox::isEntered() const {
    return enter_pressed;
}

void TextBox::setEnterFalse() {
    enter_pressed = false;
}

void TextBox::setColor(const sf::Color& color) {
    text.setFillColor(color);
}

void TextBox::setFillColor(const sf::Color& color) {
    text_box.setFillColor(color);
}

void TextBox::setCharacterSize(const int& size) {
    text.setCharacterSize(size);
}

void TextBox::Event(const sf::Event& event) {
    bool backspace = false;
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 27) {

        } else if (event.text.unicode == 0xD) { // enter
            enter_pressed = true;
        } else if (event.text.unicode == 0x8) { // backspace
            if (output.size() > 0) {
                backspace = true;
                output.pop_back();
            }
        } else if (event.text.unicode >= '0' && event.text.unicode <= '9' || event.text.unicode == '-') {
            output.push_back(static_cast<char>(event.text.unicode));
        }
    }
    if (output.size() > 0 && output.back() == '-') {
        if (output.size() != 1) {
            output.pop_back();
        }
    }
    text.setString(output);
    if (output.size() > 8) {
        output.pop_back();
        text.setString(output);
    }
    sf::Vector2f tmp_pos = text_box.getPosition();
    sf::Vector2f tmp_size = text_box.getSize();
    float x = (tmp_pos.x + static_cast<float>(tmp_size.x / 2)) - (text.getLocalBounds().width / 2);
    text.setPosition(x, text.getPosition().y);
}

void TextBox::draw() const {
    window->draw(text_box);
    window->draw(text);
}

void TextBox::setLayout(sf::RenderWindow* win) {
    window = win;
}

void FocusController::setFocusObject(TextBox* cur_obj) {
    if (m_object == cur_obj) {
        return;
    }
    m_object = cur_obj;
}
