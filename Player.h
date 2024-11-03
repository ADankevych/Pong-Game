//
// Created by Данькевич Анастасія on 03.11.2024.
//

#ifndef PONG_GAME_PLAYER_H
#define PONG_GAME_PLAYER_H
#include "Paddle.h"

class Player {
private:
    string name;
    Paddle paddle;
    int score;

public:
    Player() = default;

    Player(string name) {
        this->name = name;
        this->paddle = Paddle();
        this->score = 0;
    }

    void setPaddle(Paddle paddle) {
        this->paddle = paddle;
    }

    RectangleShape draw(RenderWindow &window) {
        return paddle.draw(window);
    }

    void moveUp() {
        paddle.moveUp();
    }

    void moveDown() {
        paddle.moveDown();
    }


};
#endif //PONG_GAME_PLAYER_H
