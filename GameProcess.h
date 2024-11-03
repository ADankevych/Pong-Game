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

public:
    GameProcess() = default;

    GameProcess(Player player1, Player player2, Ball ball, int mode, int difficulty) {
        this->player1 = player1;
        this->player2 = player2;
        this->ball = ball;
        this->mode = mode;
        this->difficulty = difficulty;
    }

    void setNamePlayer1(string name) {
        player1 = Player(name);
    }

    void setNamePlayer2(string name) {
        player2 = Player(name);
    }

    void setModeAndDifficulty(int difficulty, int mode) {
        this->mode = mode;
        this->difficulty = difficulty;
        switch (mode) {
            case 1:
                switch (difficulty) {
                    case 1:
                        player1.setPaddle(Paddle(BOARD_WIDTH / 4 * 3, BOARD_HEIGHT / 2, 50, 200, 10, "Player 1", Color::Black, Color::White));
                        player2.setPaddle(Paddle(BOARD_WIDTH / 4, BOARD_HEIGHT / 2, 50, 200, 10, "Player 2", Color::Black, Color::White));
                        return;
                    case 2:
                        break;
                    case 3:
                        break;
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
        }
    }

    void draw(RenderWindow &window) {
        window.clear(Color(190, 190, 190));

        while (window.isOpen()) {
            Event event{};

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
            }

            window.draw(player1.draw(window));
            window.draw(player2.draw(window));

            window.display();
        }
    }

};

#endif //PONG_GAME_GAMEPROCESS_H
