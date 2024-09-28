#include "../app/paused_window.h"
#include "../app/game_window.h"
#include "../app/main_window.h"
#include <iostream>


void MainWindow::setup() {
    cur_textures_type_ = new TexturesType(Std);
    event_ = new sf::Event();
    cur_font = new sf::Font();
    cur_font->loadFromFile("frontend/assets/fonts/pixelFont.ttf");
    normal_font = new sf::Font();
    normal_font->loadFromFile("frontend/assets/fonts/baseFont.ttf");
    window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Let's Math!", sf::Style::Close);
    makePausedWindow();
    makeGameWindow();
    cur_window_ = game_window_;
}

void MainWindow::exec() {
    setup();
    while (window->isOpen()) {
        TexturesType tmp_textures_type = *cur_textures_type_;
        if (cur_window_->InteractingWithScreen() != nullptr) {
            if (cur_window_ == paused_window_) {
                cur_window_ = game_window_;
            } else if (cur_window_ == game_window_) {
                cur_window_ = paused_window_;
            }
        }

        window->clear(sf::Color(102, 102, 153, 180));
        if (cur_window_ == paused_window_) {
            game_window_->draw();
            paused_window_->draw();
        } else {
            cur_window_->draw();
        }
        if (tmp_textures_type != *cur_textures_type_) {
            game_window_->updateTexturesAndSprites();
            paused_window_->updateTexturesAndSprites();
        }
        window->display();
    }
}

MainWindow* MainWindow::InteractingWithScreen() {
    while (window->pollEvent(*event_)) {
        if (event_->type == sf::Event::Closed) {
            window->close();
        }

    }
    return nullptr;
}

void MainWindow::makePausedWindow() {
    paused_window_ = new PausedWindow();
    paused_window_->setLayout(window);
    paused_window_->setFont(normal_font);
    paused_window_->setTexturesType(cur_textures_type_);
    paused_window_->setup();
}

void MainWindow::makeGameWindow() {
    game_window_ = new GameWindow();
    game_window_->setLayout(window);
    game_window_->setFont(cur_font);
    game_window_->setTexturesType(cur_textures_type_);
    game_window_->setup();
}

void MainWindow::draw() {

}
