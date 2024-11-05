//
// Created by Данькевич Анастасія on 03.11.2024.
//

#ifndef PONG_GAME_GAMEPROCESS_H
#define PONG_GAME_GAMEPROCESS_H

#include "Player.h"
#include "Ball.h"

class GameProcess {
private:
    int BotOrFriend;
    Player player1;
    Player player2;
    Ball ball;
    int mode;
    int difficulty;
    Color colorBackground, colorPaddle, colorBall, colorMenu;
    Texture texture;

public:
    GameProcess() = default;

    void setModeAndDifficulty() {
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
        setDifficulty();
        ball.setPos(player1.getPaddle().getXPos() - 2 * ball.getRadius(), BOARD_HEIGHT / 2 - ball.getRadius());
    }

    void setDifficulty() {
        switch (difficulty) {
            case 1:
                player1.setPaddle(Paddle((BOARD_WIDTH - 40) / 5 * 4, (BOARD_HEIGHT - 200) / 2, 40,
                                         200, 20, "", colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - 40) / 5, (BOARD_HEIGHT - 200) / 2, 40,
                                         200, 20, "", colorPaddle, colorPaddle));
                player1.setSpeed(2);
                player2.setSpeed(2);
                ball.setSpeed(0.5);
                ball.setRadius(50);
                break;
            case 2:
                player1.setPaddle(Paddle((BOARD_WIDTH - 30) / 5 * 4, (BOARD_HEIGHT - 120) / 2, 30,
                                         120, 10, "", colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - 30) / 5, (BOARD_HEIGHT - 120) / 2, 30,
                                         120, 10, "", colorPaddle, colorPaddle));
                player1.setSpeed(1.25);
                player2.setSpeed(1.25);
                ball.setSpeed(1);
                ball.setRadius(35);
                break;
            case 3:
                player1.setPaddle(Paddle((BOARD_WIDTH - 20) / 5 * 4, (BOARD_HEIGHT - 75) / 2, 20,
                                         75, 10, "", colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - 20) / 5, (BOARD_HEIGHT - 75) / 2, 20,
                                         75, 10, "", colorPaddle, colorPaddle));
                player1.setSpeed(1);
                player2.setSpeed(1);
                ball.setSpeed(1.25);
                ball.setRadius(20);
                break;
        }
    }

    void startNewGame(RenderWindow &window) {
        BotOrFriend = GameSettings::welcomePage(window);

        if (BotOrFriend == 1) {
            player1 = Player(GameSettings::nameEntering(window, "Enter your name:"));
            player2 = Player("Bot");
        } else if (BotOrFriend == 2) {
            player1 = Player(GameSettings::nameEntering(window, "Enter player 1 name:"));
            player2 = Player(GameSettings::nameEntering(window, "Enter player 2 name:"));
        }

        difficulty = GameSettings::chooseDifficulty(window);
        mode = GameSettings::chooseMode(window);

        setModeAndDifficulty();
        draw(window);
    }

    void winnerPage(RenderWindow &window, string winner) {
        Paddle paddlePlayAgain(BOARD_WIDTH / 4, 450, 200, 50, 0, "Play again",
                               Color::Black, Color::White);
        Paddle paddleExit(BOARD_WIDTH / 4 + 325, 450, 200, 50, 0, "Exit",
                          Color::Black, Color::White);
        Paddle paddleMenu(BOARD_WIDTH / 4 + 140, 650, 250, 50, 0,
                          "Restart whole program",Color::Black, Color::White);

        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

        Text textWinner;
        textWinner.setFont(font);
        textWinner.setString("Winner is " + winner + "!");
        textWinner.setCharacterSize(40);
        textWinner.setFillColor(Color::Black);
        textWinner.setPosition((BOARD_WIDTH - textWinner.getLocalBounds().width) / 2,
                                BOARD_HEIGHT / 3);

        Text textChoose;
        textChoose.setFont(font);
        textChoose.setString("Choose one option:");
        textChoose.setCharacterSize(30);
        textChoose.setFillColor(Color::Black);
        textChoose.setPosition((BOARD_WIDTH - textChoose.getLocalBounds().width) / 2, BOARD_HEIGHT / 3 + 100);

        while (window.isOpen()) {
            window.clear(colorBackground);
            if (mode != 1) {
                Sprite sprite(texture);
                window.draw(sprite);
            }

            window.draw(textWinner);
            window.draw(textChoose);

            window.draw(paddlePlayAgain.draw());
            window.draw(paddlePlayAgain.drawText());

            window.draw(paddleExit.draw());
            window.draw(paddleExit.drawText());

            window.draw(paddleMenu.draw());
            window.draw(paddleMenu.drawText());

            Event event{};

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == Event::MouseButtonPressed) {
                    if (event.mouseButton.button == Mouse::Left) {
                        Vector2i mousePos = Mouse::getPosition(window);
                        if (paddlePlayAgain.isMouseOver(mousePos)) {
                            player1.setScore(0);
                            player2.setScore(0);
                            setDifficulty();
                            ball.setPos(player1.getPaddle().getXPos() - 2 * ball.getRadius(),
                                        BOARD_HEIGHT / 2 - ball.getRadius());
                            return;
                        } else if (paddleExit.isMouseOver(mousePos)) {
                            window.close();
                        } else if (paddleMenu.isMouseOver(mousePos)) {
                            startNewGame(window);
                        }
                    }
                }

            }
            window.display();
        }
    }

    void menu(RenderWindow &window) {
        Paddle paddlePlay(BOARD_WIDTH / 4, 350, 200, 50, 0, "Continue",
                          colorMenu, Color::Black);
        Paddle paddleExit(BOARD_WIDTH / 4 + 140, 550, 200, 50, 0, "Exit",
                          colorMenu, Color::Black);
        Paddle paddleRestart(BOARD_WIDTH / 4 + 325, 350, 200, 50, 0, "Restart",
                             colorMenu, Color::Black);
        Paddle paddleReturn(BOARD_WIDTH / 4 + 90, 450, 300, 50, 0,
                            "Return to welcome page",colorMenu, Color::Black);

        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

        Text textMenu;
        textMenu.setFont(font);
        textMenu.setString("Menu");
        textMenu.setCharacterSize(30);
        textMenu.setFillColor(Color::Black);
        textMenu.setPosition((BOARD_WIDTH - textMenu.getLocalBounds().width) / 2,BOARD_HEIGHT / 4);

        while (window.isOpen()) {
            window.clear(colorBackground);
            if (mode != 1) {
                Sprite sprite(texture);
                window.draw(sprite);
            }

            Event event{};

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == Event::MouseButtonPressed) {
                    if (event.mouseButton.button == Mouse::Left) {
                        Vector2i mousePos = Mouse::getPosition(window);
                        if (paddlePlay.isMouseOver(mousePos)) {
                            return;
                        } else if (paddleExit.isMouseOver(mousePos)) {
                            window.close();
                        } else if (paddleRestart.isMouseOver(mousePos)) {
                            player1.setScore(0);
                            player2.setScore(0);
                            setDifficulty();
                            ball.setPos(player1.getPaddle().getXPos() - 2 * ball.getRadius(),
                                        BOARD_HEIGHT / 2 - ball.getRadius());
                            draw(window);
                        } else if (paddleReturn.isMouseOver(mousePos)) {
                            startNewGame(window);
                        }
                    }
                }
            }

            window.draw(textMenu);

            window.draw(paddlePlay.draw());
            window.draw(paddlePlay.drawText());

            window.draw(paddleExit.draw());
            window.draw(paddleExit.drawText());

            window.draw(paddleRestart.draw());
            window.draw(paddleRestart.drawText());

            window.draw(paddleReturn.draw());
            window.draw(paddleReturn.drawText());

            window.display();
        }
    };

    void bounce() { // bounce the ball off the walls and paddles
        if (ball.getY() <= 0 || ball.getY() + ball.getRadius() * 2 >= BOARD_HEIGHT) {
            ball.reverseY();
        }

        if (ball.getX() <= player2.getPaddle().getXPos() + player2.getPaddle().getWidth() &&
            ball.getY() + ball.getRadius() >= player2.getPaddle().getYPos() &&
            ball.getY() <= player2.getPaddle().getYPos() + player2.getPaddle().getHeight()) {
            ball.reverseX();
            ball.setPos(player2.getPaddle().getXPos() + player2.getPaddle().getWidth() + 1, ball.getY());
        }

        if (ball.getX() + ball.getRadius() * 2 >= player1.getPaddle().getXPos() &&
            ball.getY() + ball.getRadius() >= player1.getPaddle().getYPos() &&
            ball.getY() <= player1.getPaddle().getYPos() + player1.getPaddle().getHeight()) {
            ball.reverseX();
            ball.setPos(player1.getPaddle().getXPos() - ball.getRadius() * 2 - 1, ball.getY());
        }

    }

    void moving(bool &isBallMoving) { // moving paddles and ball
        if (BotOrFriend == 1) {
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                player1.moveUp();
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                player1.moveDown();
            }
            if (isBallMoving) {
                player2.moveBot(ball);
            }
        } else {
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
    }

    void scored(bool &isBallMoving) { // check if the ball is scored
        if (ball.getX() < player2.getPaddle().getXPos() + player2.getPaddle().getWidth()) {
            player1.setScore(player1.getScore() + 1);
            player1.setPaddle(Paddle((BOARD_WIDTH - player1.getPaddle().getWidth()) / 5 * 4,
                                     (BOARD_HEIGHT - player1.getPaddle().getHeight())/2,
                                     player1.getPaddle().getWidth(),player1.getPaddle().getHeight(),
                                     player1.getPaddle().getSpeed(),player1.getName(),
                                     colorPaddle, colorPaddle));
            player2.setPaddle(Paddle((BOARD_WIDTH - player2.getPaddle().getWidth()) / 5,
                                     (BOARD_HEIGHT - player2.getPaddle().getHeight())/2,
                                     player2.getPaddle().getWidth(), player2.getPaddle().getHeight(),
                                     player2.getPaddle().getSpeed(), player2.getName(),
                                     colorPaddle, colorPaddle));
            ball.setPos(player2.getPaddle().getXPos() + player2.getPaddle().getWidth(),
                        BOARD_HEIGHT / 2 - ball.getRadius());
            isBallMoving = false;
        } else if (ball.getX() + ball.getRadius() * 2 > player1.getPaddle().getXPos() + player1.getPaddle().getWidth()) {
            player2.setScore(player2.getScore() + 1);
            player1.setPaddle(Paddle((BOARD_WIDTH - player1.getPaddle().getWidth()) / 5 * 4,
                                     (BOARD_HEIGHT - player1.getPaddle().getHeight())/2,
                                     player1.getPaddle().getWidth(), player1.getPaddle().getHeight(),
                                     player1.getPaddle().getSpeed(), player1.getName(),
                                     colorPaddle, colorPaddle));
            player2.setPaddle(Paddle((BOARD_WIDTH - player2.getPaddle().getWidth()) / 5,
                                     (BOARD_HEIGHT - player2.getPaddle().getHeight())/2,
                                     player2.getPaddle().getWidth(), player2.getPaddle().getHeight(),
                                     player2.getPaddle().getSpeed(), player2.getName(),
                                     colorPaddle, colorPaddle));
            ball.setPos(player1.getPaddle().getXPos() - 2 * ball.getRadius(),
                        BOARD_HEIGHT / 2 - ball.getRadius());
            isBallMoving = false;
        }
    }

    void draw(RenderWindow &window) {
        Paddle menuButton((BOARD_WIDTH - 75) / 2, 10, 75, 25, 0, "Menu",
                          colorMenu, Color::Black);

        Paddle player2NameMenu(10, 10, 30, BOARD_HEIGHT - 20, 0,
                               player2.getName(), colorMenu, Color::Black);
        Paddle player1NameMenu(BOARD_WIDTH - 40, 10, 30, BOARD_HEIGHT - 20, 0,
                               player1.getName(), colorMenu, Color::Black);

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

                if (event.type == Event::MouseButtonPressed) {
                    if (event.mouseButton.button == Mouse::Left) {
                        Vector2i mousePos = Mouse::getPosition(window);
                        if (menuButton.isMouseOver(mousePos)) {
                            menu(window);
                        }
                    }
                }
            }

            RectangleShape dash(Vector2f(2, 10));
            dash.setFillColor(Color::Black);
            for (int i = 0; i < BOARD_HEIGHT; i += 20) {
                dash.setPosition((BOARD_WIDTH - 10) / 2, i);
                window.draw(dash);
            }

            moving(isBallMoving);

            scored(isBallMoving);

            if (player1.getScore() == 5 || player2.getScore() == 5) {
                winnerPage(window, player1.getScore() == 5 ? player1.getName() : player2.getName());
            }

            bounce();

            window.draw(player1.draw());
            window.draw(player2.draw());
            window.draw(ball.draw());

            window.draw(menuButton.draw());
            window.draw(menuButton.drawText(15));

            window.draw(player2NameMenu.draw());
            window.draw(player2NameMenu.drawAsMenu());
            window.draw(player1NameMenu.draw());
            window.draw(player1NameMenu.drawAsMenu());
            window.draw(Paddle(10, BOARD_HEIGHT - 60, 30, 30, 0,
                               to_string(player2.getScore()),colorMenu,
                               Color::Black).drawText());
            window.draw(Paddle(BOARD_WIDTH - 40, BOARD_HEIGHT - 60, 30, 30, 0,
                               to_string(player1.getScore()),colorMenu,
                               Color::Black).drawText());
            window.display();
        }
    }

};

#endif //PONG_GAME_GAMEPROCESS_H
