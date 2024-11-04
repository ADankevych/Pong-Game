//
// Created by Данькевич Анастасія on 03.11.2024.
//

#ifndef PONG_GAME_BALL_H
#define PONG_GAME_BALL_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Ball {
private:
    float x, y, radius, speed;
    Color color;

public:
    Ball() = default;

    Ball(float x, float y, float radius, float speed, Color color) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->speed = speed;
        this->color = color;
    }

    CircleShape draw() {
        CircleShape ball(radius);
        ball.setPosition(x, y);
        ball.setFillColor(color);

        return ball;
    }

    void setSpeed(float speed) {
        this->speed = speed;
    }

    void setColor(Color color) {
        this->color = color;
    }

    void setSize(float radius) {
        this->radius = radius;
    }

    void setPos(float x, float y) {
        this->x = x;
        this->y = y;
    }

    float getRadius() {
        return radius;
    }

    void move() {
    }

};
#endif //PONG_GAME_BALL_H
