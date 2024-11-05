//
// Created by Данькевич Анастасія on 03.11.2024.
//

#ifndef PONG_GAME_PLAYER_H
#define PONG_GAME_PLAYER_H
#include "Paddle.h"
#include "Ball.h"

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

    Paddle getPaddle() {
        return paddle;
    }

    RectangleShape draw() {
        return paddle.draw();
    }

    string getName() {
        return name;
    }

    int getScore() {
        return score;
    }

    void moveUp() {
        paddle.moveUp();
    }

    void moveDown() {
        paddle.moveDown();
    }

    void moveBot(Ball ball) {
        if (ball.getY() + ball.getRadius() > getPaddle().getYPos() + getPaddle().getHeight() / 2) {
            moveDown();
        } else if (ball.getY() < getPaddle().getYPos() + getPaddle().getHeight() / 2) {
            moveUp();
        }
    }

    void setSpeed(float speed) {
        paddle.setSpeed(speed);
    }

    void setScore(int score) {
        this->score = score;
    }

};
#endif //PONG_GAME_PLAYER_H
