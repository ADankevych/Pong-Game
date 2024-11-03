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

    Player(string name, Paddle paddle) {
        this->name = name;
        this->paddle = paddle;
        this->score = 0;
    }

    void draw(RenderWindow &window) {
        paddle.draw(window);
    }

    void moveUp() {
        paddle.moveUp();
    }

    void moveDown() {
        paddle.moveDown();
    }


};
#endif //PONG_GAME_PLAYER_H
