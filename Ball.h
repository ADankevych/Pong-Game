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
    float x, y;
    float radius;
    float speedX, speedY;
    Color color;

public:
    Ball() = default;

    Ball(float x, float y, float radius, float speed, Color color) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->speedX = speed;
        this->speedY = speed;
        this->color = color;
    }

    CircleShape draw() {
        CircleShape ball(radius);
        ball.setPosition(x, y);
        ball.setFillColor(color);
        return ball;
    }

    void setSpeed(float speed) {
        this->speedX = speed;
        this->speedY = speed;
    }

    void setColor(Color color) {
        this->color = color;
    }

    void setRadius(float radius) {
        this->radius = radius;
    }

    float getRadius() {
        return radius;
    }

    void setPos(float x, float y) {
        this->x = x;
        this->y = y;
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    void move() {
        x += speedX;
        y += speedY;
    }

    void reverseX() {
        speedX = -speedX;
    }

    void reverseY() {
        speedY = -speedY;
    }
};

#endif //PONG_GAME_BALL_H
