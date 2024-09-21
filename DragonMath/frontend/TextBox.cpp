#include "TextBox.h"


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
        } else {
            output.push_back(static_cast<char>(event.text.unicode));
        }
    }
    text.setString(output);
    if (backspace) {
        if (text.getLocalBounds().width + 20 <= sheet_width_) {
            fill = output;
            text.setPosition(
                (text_box.getSize().x - text.getLocalBounds().width) / 2
                + text_box.getPosition().x,
                (text_box.getSize().y - text.getLocalBounds().height - 20) / 2
                + text_box.getPosition().y);
        } else {
            text.setString(fill);
            text.setPosition(
                (text_box.getSize().x - text.getLocalBounds().width) / 2
                + text_box.getPosition().x,
                (text_box.getSize().y - text.getLocalBounds().height - 20) / 2
                + text_box.getPosition().y);
        }
    } else {
        if (fill.back() != '.') {
            if (text.getLocalBounds().width + 20 > sheet_width_) {
                fill = output;
                if (!fill.empty()) {
                    fill.pop_back();
                    if (!fill.empty()) {
                        fill.pop_back();
                        if (!fill.empty()) {
                            fill.pop_back();
                            fill.push_back('.');
                            fill.push_back('.');
                            fill.push_back('.');
                        }
                    }
                }
                text.setString(fill);
                text.setPosition(
                    (text_box.getSize().x - text.getLocalBounds().width) / 2
                    + text_box.getPosition().x,
                    (text_box.getSize().y - text.getLocalBounds().height - 20) / 2
                    + text_box.getPosition().y);
            } else {
                fill = output;
                text.setPosition(
                    (text_box.getSize().x - text.getLocalBounds().width) / 2
                    + text_box.getPosition().x,
                    (text_box.getSize().y - text.getLocalBounds().height - 20) / 2
                    + text_box.getPosition().y);
            }
        } else {
            text.setString(fill);
            text.setPosition(
                (text_box.getSize().x - text.getLocalBounds().width) / 2
                + text_box.getPosition().x,
                (text_box.getSize().y - text.getLocalBounds().height - 20) / 2
                + text_box.getPosition().y);
        }
    }
}

void FocusController::setFocusObject(TextBox* cur_obj) {
    if (m_object == cur_obj) {
        return;
    }
    m_object = cur_obj;
}