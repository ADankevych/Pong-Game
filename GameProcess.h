//
// Created by Данькевич Анастасія on 03.11.2024.
//

#ifndef PONG_GAME_GAMEPROCESS_H
#define PONG_GAME_GAMEPROCESS_H

#include "Player.h"
#include "Ball.h"

class GameProcess {
private:
    Player player1;
    Player player2;
    Ball ball;
    int mode;
    int difficulty;
    Color colorBackground, colorPaddle, colorBall, colorMenu;
    Texture texture;

public:
    GameProcess() = default;

    void setNamePlayer1(string name) {
        player1 = Player(name);
    }

    void setNamePlayer2(string name) {
        player2 = Player(name);
    }

    void setModeAndDifficulty(int difficulty, int mode) {
        this->mode = mode;
        this->difficulty = difficulty;
        colorBackground = Color(190, 190, 190);
        switch (mode) {
            case 1:
                colorPaddle = Color::Black;
                colorBall = Color::Black;
                colorMenu = Color(190, 190, 190);
                break;
            case 2:
                colorPaddle = Color(255, 105, 180);
                colorBall = Color(255, 105, 180);
                colorMenu = Color(255, 105, 180);
                texture.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/images/Hello_Kitty.png");
                break;
            case 3:
                colorPaddle = Color::Black;
                colorBall = Color(255, 165, 0);
                colorMenu = Color(255, 165, 0);
                texture.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/images/Halloween.png");
                break;
            case 4:
                colorPaddle = Color::White;
                colorBall = Color::Red;
                colorMenu = Color::White;
                texture.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/images/Christmas.png");
                break;
        }
        ball.setColor(colorBall);
        setDif();
        ball.setPos(player1.getPaddle().getXPos() - 2 * ball.getRadius(), BOARD_HEIGHT / 2 - ball.getRadius());
        return;
    }

    void setDif() {
        switch (difficulty) {
            case 1:
                player1.setPaddle(Paddle((BOARD_WIDTH - 40) / 5 * 4, (BOARD_HEIGHT - 200) / 2, 40, 200, 20, "", colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - 40) / 5, (BOARD_HEIGHT - 200) / 2, 40, 200, 20, "", colorPaddle, colorPaddle));
                player1.setSpeed(2);
                player2.setSpeed(2);
                ball.setSpeed(0.5);
                ball.setRadius(50);
                break;
            case 2:
                player1.setPaddle(Paddle((BOARD_WIDTH - 30) / 5 * 4, (BOARD_HEIGHT - 150) / 2, 30, 150, 10, "", colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - 30) / 5, (BOARD_HEIGHT - 150) / 2, 30, 150, 10, "", colorPaddle, colorPaddle));
                player1.setSpeed(1.5);
                player2.setSpeed(1.5);
                ball.setSpeed(1);
                ball.setRadius(40);
                break;
            case 3:
                player1.setPaddle(Paddle((BOARD_WIDTH - 20) / 5 * 4, (BOARD_HEIGHT - 75) / 2, 20, 75, 10, "", colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - 20) / 5, (BOARD_HEIGHT - 75) / 2, 20, 75, 10, "", colorPaddle, colorPaddle));
                player1.setSpeed(1);
                player2.setSpeed(1);
                ball.setSpeed(2);
                ball.setRadius(30);
                break;
        }
    }

    void draw(RenderWindow &window) {
        bool isBallMoving = false;
        while (window.isOpen()) {
            window.clear(colorBackground);
            if (mode != 1) {
                Sprite sprite(texture);
                window.draw(sprite);
            }
            Event event{};

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
            }

            RectangleShape dash(Vector2f(2, 10));
            dash.setFillColor(Color::Black);
            for (int i = 0; i < BOARD_HEIGHT; i += 20) {
                dash.setPosition((BOARD_WIDTH - 10) / 2, i);
                window.draw(dash);
            }

            if (Keyboard::isKeyPressed(Keyboard::W)) {
                player2.moveUp();
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                player2.moveDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                player1.moveUp();
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                player1.moveDown();
            }

            if (!isBallMoving) {
                if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down) ||
                    Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S)) {
                    isBallMoving = true;
                }
            }

            if (isBallMoving) {
                ball.move();
            }

            if (ball.getY() <= 0 || ball.getY() + ball.getRadius() * 2 >= BOARD_HEIGHT) {
                ball.reverseY();
            }

            if (ball.getX() < player2.getPaddle().getXPos() + player2.getPaddle().getWidth()) {
                player1.setScore(player1.getScore() + 1);
                player1.setPaddle(Paddle((BOARD_WIDTH - player1.getPaddle().getWidth()) / 5 * 4, (BOARD_HEIGHT - player1.getPaddle().getHeight())/2, player1.getPaddle().getWidth(), player1.getPaddle().getHeight(), player1.getPaddle().getSpeed(), player1.getName(), colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - player2.getPaddle().getWidth()) / 5, (BOARD_HEIGHT - player2.getPaddle().getHeight())/2, player2.getPaddle().getWidth(), player2.getPaddle().getHeight(), player2.getPaddle().getSpeed(), player2.getName(), colorPaddle, colorPaddle));
                ball.setPos(player2.getPaddle().getXPos() + player2.getPaddle().getWidth(), BOARD_HEIGHT / 2 - ball.getRadius());
                isBallMoving = false;
            } else if (ball.getX() + ball.getRadius() * 2 > player1.getPaddle().getXPos() + player1.getPaddle().getWidth()) {
                player2.setScore(player2.getScore() + 1);
                player1.setPaddle(Paddle((BOARD_WIDTH - player1.getPaddle().getWidth()) / 5 * 4, (BOARD_HEIGHT - player1.getPaddle().getHeight())/2, player1.getPaddle().getWidth(), player1.getPaddle().getHeight(), player1.getPaddle().getSpeed(), player1.getName(), colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - player2.getPaddle().getWidth()) / 5, (BOARD_HEIGHT - player2.getPaddle().getHeight())/2, player2.getPaddle().getWidth(), player2.getPaddle().getHeight(), player2.getPaddle().getSpeed(), player2.getName(), colorPaddle, colorPaddle));
                ball.setPos(player1.getPaddle().getXPos() - 2 * ball.getRadius(), BOARD_HEIGHT / 2 - ball.getRadius());
                isBallMoving = false;
            }

            if (ball.getX() <= player2.getPaddle().getXPos() + player2.getPaddle().getWidth() &&
                ball.getY() + ball.getRadius() >= player2.getPaddle().getYPos() &&
                ball.getY() <= player2.getPaddle().getYPos() + player2.getPaddle().getHeight()) {
                ball.reverseX();
            }
            if (ball.getX() + ball.getRadius() * 2 >= player1.getPaddle().getXPos() &&
                ball.getY() + ball.getRadius() >= player1.getPaddle().getYPos() &&
                ball.getY() <= player1.getPaddle().getYPos() + player1.getPaddle().getHeight()) {
                ball.reverseX();
            }

            window.draw(player1.draw());
            window.draw(player2.draw());
            window.draw(ball.draw());

            window.draw(Paddle(10, 10, 30, BOARD_HEIGHT - 20, 0, player2.getName(), colorMenu, Color::Black).draw());
            window.draw(Paddle(10, 10, 30, BOARD_HEIGHT - 20, 0, player2.getName(), colorMenu, Color::Black).drawMenu());
            window.draw(Paddle(BOARD_WIDTH - 40, 10, 30, BOARD_HEIGHT - 20, 0, player1.getName(), colorMenu, Color::Black).draw());
            window.draw(Paddle(BOARD_WIDTH - 40, 10, 30, BOARD_HEIGHT - 20, 0, player1.getName(), colorMenu, Color::Black).drawMenu());
            window.draw(Paddle(10, BOARD_HEIGHT - 60, 30, 30, 0, to_string(player2.getScore()), colorMenu, Color::Black).drawText());
            window.draw(Paddle(BOARD_WIDTH - 40, BOARD_HEIGHT - 60, 30, 30, 0, to_string(player1.getScore()), colorMenu, Color::Black).drawText());
            window.display();
        }
    }

};

#endif //PONG_GAME_GAMEPROCESS_H
