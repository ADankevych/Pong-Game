//
// Created by Данькевич Анастасія on 02.11.2024.
//

#ifndef PONG_GAME_GAMESETTINGS_H
#define PONG_GAME_GAMESETTINGS_H

#include "Paddle.h"

float BOARD_WIDTH = 1080;
float BOARD_HEIGHT = 760;

class GameSettings {
public:
    static string nameEntering(RenderWindow &window, const string &message) {
        Font font;
        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

        string playerName;
        Text nameText;
        nameText.setFont(font);
        nameText.setCharacterSize(30);
        nameText.setFillColor(Color::Black);

        Text text;
        text.setFont(font);
        text.setString(message);
        text.setCharacterSize(30);
        text.setFillColor(Color::Black);
        text.setPosition((BOARD_WIDTH - text.getLocalBounds().width) / 2, BOARD_HEIGHT / 3);

        Event event{};

        while (window.isOpen()) {
            window.clear(Color(190, 190, 190));
            window.draw(text);

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == Event::TextEntered) {
                    if (event.text.unicode < 128) {
                        if (event.text.unicode == '\b') {
                            if (!playerName.empty())
                                playerName.pop_back();
                        } else if (event.text.unicode == '\n') {
                            return playerName;
                        } else {
                            playerName += static_cast<char>(event.text.unicode);
                        }
                    }
                }
            }

            nameText.setString(playerName);
            nameText.setPosition((BOARD_WIDTH - nameText.getLocalBounds().width) / 2, BOARD_HEIGHT / 3 + 150);

            window.draw(nameText);
            window.display();
        }
        return "";
    }

    static int welcomePage(RenderWindow &window) {
        Paddle paddle1(BOARD_WIDTH / 4, 450, 200, 50, 0, "Play with bot", Color::Black, Color::White);
        Paddle paddle2(BOARD_WIDTH / 4 + 325, 450, 200, 50, 0, "Play with friend", Color::Black, Color::White);

        Font font;
        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

        Text textWelcome;
        textWelcome.setFont(font);
        textWelcome.setString("Welcome to Pong game!");
        textWelcome.setCharacterSize(40);
        textWelcome.setFillColor(Color::Black);
        textWelcome.setPosition((BOARD_WIDTH - textWelcome.getLocalBounds().width) / 2,
                                BOARD_HEIGHT / 3); // textPaddle.getLocalBounds().width - width of the textPaddle

        Text textChoose;
        textChoose.setFont(font);
        textChoose.setString("Choose one option:");
        textChoose.setCharacterSize(30);
        textChoose.setFillColor(Color::Black);
        textChoose.setPosition((BOARD_WIDTH - textChoose.getLocalBounds().width) / 2, BOARD_HEIGHT / 3 + 100);

        while (window.isOpen()) {
            window.clear(Color(190, 190, 190));

            window.draw(textWelcome);
            window.draw(textChoose);

            window.draw(paddle1.draw(window));
            window.draw(paddle1.drawText(window));

            window.draw(paddle2.draw(window));
            window.draw(paddle2.drawText(window));

            Event event{};

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == Event::MouseButtonPressed) {
                    if (event.mouseButton.button == Mouse::Left) {
                        Vector2i mousePos = Mouse::getPosition(window);
                        if (paddle1.isMouseOver(mousePos)) {
                            return 1;
                        } else if (paddle2.isMouseOver(mousePos)) {
                            return 2;
                        }
                    }
                }
            }
            window.display();
        }
        return 0;
    }

    static int chooseDifficulty(RenderWindow &window) {
        Paddle paddle1((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 100, 200, 45, 0, "Easy", Color::Black, Color::White);
        Paddle paddle2((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 200, 200, 45, 0, "Medium", Color::Black,
                       Color::White);
        Paddle paddle3((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 300, 200, 45, 0, "Hard", Color::Black, Color::White);

        Font font;
        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

        Text textDifficulty;
        textDifficulty.setFont(font);
        textDifficulty.setString("Choose difficulty:");
        textDifficulty.setCharacterSize(35);
        textDifficulty.setFillColor(Color::Black);
        textDifficulty.setPosition((BOARD_WIDTH - textDifficulty.getLocalBounds().width) / 2, BOARD_HEIGHT / 3);

        while (window.isOpen()) {
            window.clear(Color(190, 190, 190));

            window.draw(textDifficulty);

            window.draw(paddle1.draw(window));
            window.draw(paddle1.drawText(window));

            window.draw(paddle2.draw(window));
            window.draw(paddle2.drawText(window));

            window.draw(paddle3.draw(window));
            window.draw(paddle3.drawText(window));

            Event event{};

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == Event::MouseButtonPressed) {
                    if (event.mouseButton.button == Mouse::Left) {
                        Vector2i mousePos = Mouse::getPosition(window);
                        if (paddle1.isMouseOver(mousePos)) {
                            return 1;
                        } else if (paddle2.isMouseOver(mousePos)) {
                            return 2;
                        } else if (paddle3.isMouseOver(mousePos)) {
                            return 3;
                        }
                    }
                }
            }
            window.display();
        }
        return 0;
    }

    static int chooseMode(RenderWindow &window) {
        Paddle paddle1((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 100, 200, 50, 0, "Default", Color::Black,
                       Color::White);
        Paddle paddle2((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 200, 200, 50, 0, "Hello Kitty", Color(255, 105, 180),
                       Color::Black);
        Paddle paddle3((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 300, 200, 50, 0, "Halloween", Color::Black,
                       Color(255, 165, 0));
        Paddle paddle4((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 400, 200, 50, 0, "Christmas", Color::Blue,
                       Color::White);

        Font font;
        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

        Text textMode;
        textMode.setFont(font);
        textMode.setString("\t Cool!\nChoose mode:");
        textMode.setCharacterSize(35);
        textMode.setFillColor(Color::Black);
        textMode.setPosition((BOARD_WIDTH - textMode.getLocalBounds().width) / 2, BOARD_HEIGHT / 3);

        while (window.isOpen()) {
            window.clear(Color(190, 190, 190));

            window.draw(textMode);

            window.draw(paddle1.draw(window));
            window.draw(paddle1.drawText(window));

            window.draw(paddle2.draw(window));
            window.draw(paddle2.drawText(window));

            window.draw(paddle3.draw(window));
            window.draw(paddle3.drawText(window));

            window.draw(paddle4.draw(window));
            window.draw(paddle4.drawText(window));

            Event event{};

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == Event::MouseButtonPressed) {
                    if (event.mouseButton.button == Mouse::Left) {
                        Vector2i mousePos = Mouse::getPosition(window);
                        if (paddle1.isMouseOver(mousePos)) {
                            return 1;
                        } else if (paddle2.isMouseOver(mousePos)) {
                            return 2;
                        } else if (paddle3.isMouseOver(mousePos)) {
                            return 3;
                        } else if (paddle4.isMouseOver(mousePos)) {
                            return 4;
                        }
                    }
                }
            }
            window.display();
        }
        return 0;
    }
};

#endif //PONG_GAME_GAMESETTINGS_H
