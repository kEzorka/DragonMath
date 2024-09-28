#include "../app/game_window.h"

void GameWindow::setup() {
    //makeShtypaTexturesAndSprites();
    MakeNewTextures();
    if (*cur_textures_type_ == TexturesType::Shtypa) {
        makeShtypaTexturesAndSprites();
    } else if (*cur_textures_type_ == TexturesType::Std) {
        makeStdTexturesAndSprites();
    }
    makeQuestion();
    AskQuestion();
}

MainWindow* GameWindow::InteractingWithScreen() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 27) {
                return this;
            }
        }
        if (*cur_textures_type_ == TexturesType::Shtypa) {
            InteractingWithShtypa(event);
        } else if (*cur_textures_type_ == TexturesType::Std) {
            InteractingWithStd(event);
        }
    }
    return nullptr;
}

void GameWindow::setTexturesType(TexturesType* type) {
    cur_textures_type_ = type;
}

void GameWindow::updateTexturesAndSprites() {
    if (*cur_textures_type_ == TexturesType::Shtypa) {
        makeShtypaTexturesAndSprites();
        AskQuestion();
    } else if (*cur_textures_type_ == TexturesType::Std) {
        makeStdTexturesAndSprites();
        AskQuestion();
    }
}

void GameWindow::makeShtypaTexturesAndSprites() {
    black_dragon_txr->loadFromFile("frontend/assets/images/Shtypa/dragon.png");
    green_dragon_txr->loadFromFile("frontend/assets/images/Shtypa/dragon.png");
    red_dragon_txr->loadFromFile("frontend/assets/images/Shtypa/dragon.png");
    knight_first_txr->loadFromFile("frontend/assets/images/Shtypa/knight.jpg");
    background_first_txr->loadFromFile("frontend/assets/images/Shtypa/background.jpg");
    dragon_hp_txr->loadFromFile("frontend/assets/images/Shtypa/hp.png");
    knight_hp_txr->loadFromFile("frontend/assets/images/Shtypa/hp.png");
    dragon_attack_txr->loadFromFile("frontend/assets/images/Shtypa/dragon_attack.png");
    knight_attack_txr->loadFromFile("frontend/assets/images/Shtypa/knight_attack.png");

    black_dragon_spr->setTexture(*black_dragon_txr);
    green_dragon_spr->setTexture(*green_dragon_txr);
    red_dragon_spr->setTexture(*red_dragon_txr);
    knight_spr->setTexture(*knight_first_txr);
    cur_hero_txr = knight_first_txr;
    background_spr->setTexture(*background_first_txr);
    dragon_hp_spr->setTexture(*dragon_hp_txr);
    knight_hp_spr->setTexture(*knight_hp_txr);
    dragon_attack_spr->setTexture(*dragon_attack_txr);
    knight_attack_spr->setTexture(*knight_attack_txr);

    red_dragon_spr->setColor(sf::Color::Red);
    green_dragon_spr->setColor(sf::Color::Green);

    knight_spr->setPosition(sf::Vector2f(720, 300));
    knight_attack_spr->setPosition(sf::Vector2f(knight_spr->getPosition().x
        + knight_first_txr->getSize().x - 100,
        knight_spr->getPosition().y + knight_first_txr->getSize().y - 10));
    knight_hp_spr->setPosition(sf::Vector2f(knight_spr->getPosition().x + 10,
        knight_spr->getPosition().y + knight_first_txr->getSize().y));
    dragon_hp_spr->setPosition(sf::Vector2f(0, 0));
    dragon_attack_spr->setPosition(dragon_hp_spr->getPosition()
        + sf::Vector2f(10, 150));

    ///////////////////////////////
    ///////////////////////////////
    makeGameCharacters();
    ///////////////////////////////
    ///////////////////////////////

    int enhp = enemy_->getHp();
    dragon_hp_text->setString(sf::String(enhp == -1 ? "INF" : std::to_string(enhp)));
    dragon_hp_text->setFont(*cur_font);
    int endmg = enemy_->getDamage();
    dragon_attack_text->setString(sf::String(endmg == -1 ? "INF" : std::to_string(endmg)));
    dragon_attack_text->setFont(*cur_font);
    int hehp = hero_->getHp();
    knight_hp_text->setString(sf::String(hehp == -1 ? "INF" : std::to_string(hehp)));
    knight_hp_text->setFont(*cur_font);
    int hedmg = hero_->getDamage();
    knight_attack_text->setString(sf::String(hedmg == -1 ? "INF" : std::to_string(hedmg)));
    knight_attack_text->setFont(*cur_font);

    int character_size = 100;
    dragon_hp_text->setCharacterSize(character_size);
    dragon_attack_text->setCharacterSize(character_size);
    knight_hp_text->setCharacterSize(character_size);
    knight_attack_text->setCharacterSize(character_size);

    dragon_hp_text->setPosition(dragon_hp_spr->getPosition()
        + sf::Vector2f(0.f, static_cast<float>(dragon_hp_txr->getSize().y)) + sf::Vector2f(10.f, -35.f));
    dragon_attack_text->setPosition(dragon_attack_spr->getPosition()
        + sf::Vector2f(0.f, static_cast<float>(dragon_attack_txr->getSize().y)) + sf::Vector2f(0.f, -30.f));
    knight_hp_text->setPosition(knight_hp_spr->getPosition()
        + sf::Vector2f(static_cast<float>(knight_hp_txr->getSize().x) / 2,
            static_cast<float>(knight_hp_txr->getSize().y))
        - sf::Vector2f(knight_hp_text->getLocalBounds().getSize().x / 2, 30.f));
    knight_attack_text->setPosition(sf::Vector2f(knight_attack_spr->getPosition().x
        + knight_attack_txr->getSize().x / 2
        - knight_attack_text->getLocalBounds().getSize().x / 2, knight_hp_text->getPosition().y));

    sf::Color attack_color = sf::Color::Red;
    sf::Color hp_color = sf::Color::Blue;
    dragon_hp_text->setFillColor(hp_color);
    dragon_attack_text->setFillColor(attack_color);
    knight_hp_text->setFillColor(hp_color);
    knight_attack_text->setFillColor(attack_color);

}

void GameWindow::makeStdTexturesAndSprites() {
    black_dragon_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/black_dragon_first.png");
    green_dragon_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/green_dragon_first.png");
    red_dragon_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/red_dragon_first.png");
    knight_first_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/knight_first.png");
    knight_second_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/knight_second.png");
    knight_third_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/knight_third.png");
    background_first_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/background_first.png");
    background_second_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/background_second.png");
    background_third_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/background_third.png");
    dragon_hp_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/heart.png");
    knight_hp_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/heart.png");
    dragon_attack_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/damage.png");
    knight_attack_txr->loadFromFile("frontend/assets/images/DragonsAndKnights/damage.png");

    black_dragon_spr->setTexture(*black_dragon_txr);
    green_dragon_spr->setTexture(*green_dragon_txr);
    red_dragon_spr->setTexture(*red_dragon_txr);
    knight_spr->setTexture(*knight_second_txr);
    cur_hero_txr = knight_second_txr;
    background_spr->setTexture(*background_first_txr);
    dragon_hp_spr->setTexture(*dragon_hp_txr);
    knight_hp_spr->setTexture(*knight_hp_txr);
    dragon_attack_spr->setTexture(*dragon_attack_txr);
    knight_attack_spr->setTexture(*knight_attack_txr);

    knight_hp_spr->setPosition(sf::Vector2f(1200.f - 10.f - knight_attack_txr->getSize().x, 10.f));
    knight_attack_spr->setPosition(sf::Vector2f(1200.f - knight_hp_txr->getSize().x,
        knight_hp_spr->getPosition().y + 160.f));
    dragon_hp_spr->setPosition(sf::Vector2f(10, 10));
    dragon_attack_spr->setPosition(dragon_hp_spr->getPosition()
        + sf::Vector2f(10, 160));

    chooseNewBackground();

    ///////////////////////////////
    ///////////////////////////////
    makeGameCharacters();
    ///////////////////////////////
    ///////////////////////////////

    int enhp = enemy_->getHp();
    dragon_hp_text->setString(sf::String(enhp == -1 ? "INF" : std::to_string(enhp)));
    dragon_hp_text->setFont(*cur_font);
    int endmg = enemy_->getDamage();
    dragon_attack_text->setString(sf::String(endmg == -1 ? "INF" : std::to_string(endmg)));
    dragon_attack_text->setFont(*cur_font);
    int hehp = hero_->getHp();
    knight_hp_text->setString(sf::String(hehp == -1 ? "INF" : std::to_string(hehp)));
    knight_hp_text->setFont(*cur_font);
    int hedmg = hero_->getDamage();
    knight_attack_text->setString(sf::String(hedmg == -1 ? "INF" : std::to_string(hedmg)));
    knight_attack_text->setFont(*cur_font);

    dragon_hp_text->setOutlineColor(sf::Color::Black);
    dragon_attack_text->setOutlineColor(sf::Color::Black);
    knight_hp_text->setOutlineColor(sf::Color::Black);
    knight_attack_text->setOutlineColor(sf::Color::Black);

    dragon_hp_text->setOutlineThickness(2);
    dragon_attack_text->setOutlineThickness(2);
    knight_hp_text->setOutlineThickness(2);
    knight_attack_text->setOutlineThickness(2);

    int character_size = 100;
    dragon_hp_text->setCharacterSize(character_size);
    dragon_attack_text->setCharacterSize(character_size);
    knight_hp_text->setCharacterSize(character_size);
    knight_attack_text->setCharacterSize(character_size);

    dragon_hp_text->setPosition(dragon_hp_spr->getPosition()
        + sf::Vector2f(0.f, static_cast<float>(dragon_hp_txr->getSize().y)) + sf::Vector2f(10.f, -25.f));
    dragon_attack_text->setPosition(dragon_attack_spr->getPosition()
        + sf::Vector2f(0.f, static_cast<float>(dragon_attack_txr->getSize().y)) + sf::Vector2f(0.f, -30.f));
    knight_hp_text->setPosition(sf::Vector2f(1180 - knight_hp_text->getLocalBounds().getSize().x, 
        dragon_hp_text->getPosition().y));
    knight_attack_text->setPosition(sf::Vector2f(1180 - knight_attack_text->getLocalBounds().getSize().x,
        dragon_attack_text->getPosition().y));

    sf::Color attack_color = sf::Color::Red;
    sf::Color hp_color = sf::Color::Blue;
    dragon_hp_text->setFillColor(hp_color);
    dragon_attack_text->setFillColor(attack_color);
    knight_hp_text->setFillColor(hp_color);
    knight_attack_text->setFillColor(attack_color);

}

void GameWindow::InteractingWithStd(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        TextBox* focus = cur_focus->getFocusObject();
        if (focus != nullptr) {
            if (focus == answer_tb_) {
                focus->Event(event);
                if (focus->isEntered()) {
                    focus->setEnterFalse();
                    if (enemy_->checkAnswer(std::stoi(focus->getText()))) {
                        hero_->attack(*enemy_);
                        if (!enemy_->isAlive()) {
                            callNewEnemy();
                            chooseNewBackground();
                            hero_->setExperience(hero_->getExperience() + 25);
                            UpdateExperiencePosition();
                        }
                    } else {
                        enemy_->attack(*hero_);
                        if (!hero_->isAlive()) {
                            window->close();
                        }
                    }
                    UpdateStdHpAndDamage();
                    AskQuestion();
                    focus->clear();
                }
            }
        }
    }
}

void GameWindow::InteractingWithShtypa(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        TextBox* focus = cur_focus->getFocusObject();
        if (focus != nullptr) {
            if (focus == answer_tb_) {
                focus->Event(event);
                if (focus->isEntered()) {
                    focus->setEnterFalse();
                    if (enemy_->checkAnswer(std::stoi(focus->getText()))) {
                        hero_->attack(*enemy_);
                        if (!enemy_->isAlive()) {
                            callNewEnemy();
                        }
                    } else {
                        enemy_->attack(*hero_);
                        if (!hero_->isAlive()) {
                            window->close();
                        }
                    }
                    UpdateShtypaHpAndDamage();
                    AskQuestion();
                    focus->clear();
                }
            }
        }
    }
}

void GameWindow::drawShtypa() {
    window->draw(*background_spr);
    window->draw(*cur_enemy_spr);
    window->draw(*knight_spr);

    window->draw(*knight_attack_spr);
    window->draw(*knight_hp_spr);
    window->draw(*dragon_hp_spr);
    window->draw(*dragon_attack_spr);

    window->draw(*dragon_hp_text);
    window->draw(*dragon_attack_text);
    window->draw(*knight_hp_text);
    window->draw(*knight_attack_text);

    window->draw(*question_rect_);
    window->draw(*question_text_);
    answer_tb_->draw();

    //window->draw(*experience_rect_);
    //window->draw(*experience_text_);
}

void GameWindow::drawStd() {
    window->draw(*background_spr);
    window->draw(*cur_enemy_spr);
    window->draw(*knight_spr);

    window->draw(*knight_attack_spr);
    window->draw(*knight_hp_spr);
    window->draw(*dragon_hp_spr);
    window->draw(*dragon_attack_spr);

    window->draw(*dragon_hp_text);
    window->draw(*dragon_attack_text);
    window->draw(*knight_hp_text);
    window->draw(*knight_attack_text);

    window->draw(*question_rect_);
    window->draw(*question_text_);
    answer_tb_->draw();

    window->draw(*experience_rect_);
    window->draw(*experience_text_);
}

void GameWindow::makeGameCharacters() {
    hero_ = new Hero();
    callNewEnemy();
}

void GameWindow::makeQuestion() {
    question_text_ = new sf::Text("", *cur_font, 50);
    answer_tb_ = new TextBox();
    question_rect_ = new sf::RectangleShape();
    cur_focus = new FocusController();

    experience_rect_ = new sf::RectangleShape();
    experience_text_ = new sf::Text("exp: 0", *cur_font);
    question_rect_->setFillColor(sf::Color(224, 224, 224, 100));

    cur_focus->setFocusObject(answer_tb_);
    question_rect_->setFillColor(sf::Color(224, 224, 224, 100));
    question_rect_->setSize(sf::Vector2f(400, 80));
    question_rect_->setPosition(sf::Vector2f((1200 - question_rect_->getSize().x) / 2, 0));

    experience_rect_->setSize(sf::Vector2f(600, 80));
    experience_rect_->setPosition(sf::Vector2f((1200 - experience_rect_->getSize().x) / 2,
        800 - question_rect_->getSize().y));
    experience_rect_->setFillColor(sf::Color(224, 224, 224, 100));

    UpdateExperiencePosition();

    answer_tb_->setLayout(window);

    question_text_->setString("1"); 
    UpdateQuestionTextPos();
    answer_tb_->setCharacterSize(question_text_->getCharacterSize());
    answer_tb_->setSize(question_rect_->getSize());
    answer_tb_->setFont(*cur_font);
    answer_tb_->setPosition(sf::Vector2f(question_rect_->getPosition().x,
        question_rect_->getPosition().y + question_rect_->getSize().y));
    answer_tb_->setFillColor(sf::Color(204, 204, 255, 150));
}

void GameWindow::AskQuestion() {
    std::pair<int, int> question = enemy_->question();
    question_text_->setString(
        std::to_string(question.first) + enemy_->getOperation()
        + std::to_string(question.second) + "?");
    UpdateQuestionTextPos();
}

void GameWindow::UpdateQuestionTextPos() {
    sf::Vector2f tmp_pos = question_rect_->getPosition();
    sf::Vector2f tmp_size = question_rect_->getSize();
    question_text_->setCharacterSize(static_cast<unsigned int>(question_rect_->getLocalBounds().height));
    float x = (tmp_pos.x + static_cast<float>(tmp_size.x / 2)) - (question_text_->getLocalBounds().width / 2);
    float y = (tmp_pos.y + static_cast<float>(tmp_size.y / 2.7)) - (question_text_->getLocalBounds().height / 1.3f);
    question_text_->setPosition(x, y);
}

void GameWindow::UpdateShtypaHpAndDamage() {
    int enhp = enemy_->getHp();
    dragon_hp_text->setString(sf::String(enhp == -1 ? "INF" : std::to_string(enhp)));
    int endmg = enemy_->getDamage();
    dragon_attack_text->setString(sf::String(endmg == -1 ? "INF" : std::to_string(endmg)));
    int hehp = hero_->getHp();
    knight_hp_text->setString(sf::String(hehp == -1 ? "INF" : std::to_string(hehp)));
    int hedmg = hero_->getDamage();
    knight_attack_text->setString(sf::String(hedmg == -1 ? "INF" : std::to_string(hedmg)));

    dragon_hp_text->setPosition(dragon_hp_spr->getPosition()
        + sf::Vector2f(0.f, static_cast<float>(dragon_hp_txr->getSize().y)) + sf::Vector2f(10.f, -35.f));
    dragon_attack_text->setPosition(dragon_attack_spr->getPosition()
        + sf::Vector2f(0.f, static_cast<float>(dragon_attack_txr->getSize().y)) + sf::Vector2f(0.f, -30.f));
    knight_hp_text->setPosition(knight_hp_spr->getPosition()
        + sf::Vector2f(static_cast<float>(knight_hp_txr->getSize().x) / 2,
            static_cast<float>(knight_hp_txr->getSize().y))
        - sf::Vector2f(knight_hp_text->getLocalBounds().getSize().x / 2, 30.f));
    knight_attack_text->setPosition(sf::Vector2f(knight_attack_spr->getPosition().x
        + knight_attack_txr->getSize().x / 2
        - knight_attack_text->getLocalBounds().getSize().x / 2, knight_hp_text->getPosition().y));
}

void GameWindow::UpdateStdHpAndDamage() {
    int enhp = enemy_->getHp();
    dragon_hp_text->setString(sf::String(enhp == -1 ? "INF" : std::to_string(enhp)));
    int endmg = enemy_->getDamage();
    dragon_attack_text->setString(sf::String(endmg == -1 ? "INF" : std::to_string(endmg)));
    int hehp = hero_->getHp();
    knight_hp_text->setString(sf::String(hehp == -1 ? "INF" : std::to_string(hehp)));
    int hedmg = hero_->getDamage();
    knight_attack_text->setString(sf::String(hedmg == -1 ? "INF" : std::to_string(hedmg)));

    dragon_hp_text->setPosition(dragon_hp_spr->getPosition()
        + sf::Vector2f(0.f, static_cast<float>(dragon_hp_txr->getSize().y)) + sf::Vector2f(10.f, -25.f));
    dragon_attack_text->setPosition(dragon_attack_spr->getPosition()
        + sf::Vector2f(0.f, static_cast<float>(dragon_attack_txr->getSize().y)) + sf::Vector2f(0.f, -30.f));
    knight_hp_text->setPosition(sf::Vector2f(1180 - knight_hp_text->getLocalBounds().getSize().x,
        dragon_hp_text->getPosition().y));
    knight_attack_text->setPosition(sf::Vector2f(1180 - knight_attack_text->getLocalBounds().getSize().x,
        dragon_attack_text->getPosition().y));
}

void GameWindow::callNewEnemy() {
    if (enemy_ != nullptr) {
        delete enemy_;
    }
    int rnm = RandNum() % 3;
    //rnm = 2;
    switch (rnm) {
    case(0): {
        GreenDragon* grdg = new GreenDragon();
        enemy_ = grdg;
        cur_enemy_spr = green_dragon_spr;
        break;
    }
    case(1): {
        RedDragon* rddg = new RedDragon();
        enemy_ = rddg;
        cur_enemy_spr = red_dragon_spr;
        break;
    }
    case(2): {
        BlackDragon* bldg = new BlackDragon();
        enemy_ = bldg;
        cur_enemy_spr = black_dragon_spr;
        break;
    }
    }
}

void GameWindow::chooseNewBackground() {
    int rnm = RandNum() % 3;

    switch (rnm) {
    case(0): {
        cur_hero_txr = knight_first_txr;
        knight_spr->setTexture(*cur_hero_txr);
        break;
    }
    case(1): {
        cur_hero_txr = knight_second_txr;
        knight_spr->setTexture(*cur_hero_txr);
        break;
    }
    case(2): {
        cur_hero_txr = knight_third_txr;
        knight_spr->setTexture(*cur_hero_txr);
        break;
    }
    }

    rnm = RandNum() % 3;
    switch (rnm) {
    case(0): {
        background_spr->setTexture(*background_first_txr);
        makeCharactersForFirstBackground();
        break;
    }
    case(1): {
        background_spr->setTexture(*background_second_txr);
        makeCharactersForSecondBackground();
        break;
    }
    case(2): {
        background_spr->setTexture(*background_third_txr);
        makeCharactersForThirdBackground();
        break;
    }
    }
}

void GameWindow::makeCharactersForFirstBackground() {
    black_dragon_spr->setPosition(sf::Vector2f(0.f, 800.f - black_dragon_txr->getSize().y));
    green_dragon_spr->setPosition(black_dragon_spr->getPosition());
    red_dragon_spr->setPosition(black_dragon_spr->getPosition());
    knight_spr->setPosition(sf::Vector2f(1200.f, 800.f) - static_cast<sf::Vector2f>(cur_hero_txr->getSize()));
}

void GameWindow::makeCharactersForSecondBackground() {
    black_dragon_spr->setPosition(sf::Vector2f(0.f, 730.f - black_dragon_txr->getSize().y));
    green_dragon_spr->setPosition(black_dragon_spr->getPosition());
    red_dragon_spr->setPosition(black_dragon_spr->getPosition());
    knight_spr->setPosition(sf::Vector2f(1200.f, 644.f) - static_cast<sf::Vector2f>(cur_hero_txr->getSize()));
}

void GameWindow::makeCharactersForThirdBackground() {
    black_dragon_spr->setPosition(sf::Vector2f(0.f, 750.f - black_dragon_txr->getSize().y));
    green_dragon_spr->setPosition(black_dragon_spr->getPosition());
    red_dragon_spr->setPosition(black_dragon_spr->getPosition());
    knight_spr->setPosition(sf::Vector2f(1200.f, 754.f) - static_cast<sf::Vector2f>(cur_hero_txr->getSize()));
}

void GameWindow::UpdateExperiencePosition() {
    experience_text_->setString("exp: " + std::to_string(hero_->getExperience()));
    sf::Vector2f tmp_pos = experience_rect_->getPosition();
    sf::Vector2f tmp_size = experience_rect_->getSize();
    experience_text_->setCharacterSize(static_cast<unsigned int>(experience_rect_->getLocalBounds().height));
    float x = (tmp_pos.x + static_cast<float>(tmp_size.x / 2)) - (experience_text_->getLocalBounds().width / 2);
    float y = (tmp_pos.y + static_cast<float>(tmp_size.y / 2.7)) - (experience_text_->getLocalBounds().height / 1.3f);
    experience_text_->setPosition(x, y);
}

void GameWindow::MakeNewTextures() {
    black_dragon_txr = new sf::Texture();
    green_dragon_txr = new sf::Texture();
    red_dragon_txr = new sf::Texture();
    knight_first_txr = new sf::Texture();
    knight_second_txr = new sf::Texture();
    knight_third_txr = new sf::Texture();
    background_first_txr = new sf::Texture();
    background_second_txr = new sf::Texture();
    background_third_txr = new sf::Texture();
    dragon_hp_txr = new sf::Texture();
    knight_hp_txr = new sf::Texture();
    dragon_attack_txr = new sf::Texture();
    knight_attack_txr = new sf::Texture();

    black_dragon_spr = new sf::Sprite();
    green_dragon_spr = new sf::Sprite();
    red_dragon_spr = new sf::Sprite();
    knight_spr = new sf::Sprite();
    background_spr = new sf::Sprite();
    dragon_hp_spr = new sf::Sprite();
    knight_hp_spr = new sf::Sprite();
    dragon_attack_spr = new sf::Sprite();
    knight_attack_spr = new sf::Sprite();

    dragon_attack_text = new sf::Text();
    dragon_hp_text = new sf::Text();
    knight_attack_text = new sf::Text();
    knight_hp_text = new sf::Text();
}

void GameWindow::setLayout(sf::RenderWindow* win) {
    window = win;
}

void GameWindow::setFont(sf::Font* font) {
    cur_font = font;
}

void GameWindow::draw() {
    if (*cur_textures_type_ == TexturesType::Shtypa) {
        drawShtypa();
    } else if (*cur_textures_type_ == TexturesType::Std) {
        drawStd();
    }
}
