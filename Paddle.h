//
// Created by Данькевич Анастасія on 02.11.2024.
//

#ifndef PONG_GAME_PADDLE_H
#define PONG_GAME_PADDLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Paddle { // it will be all in one - players' paddles, buttons design, etc.
    // Unfortunately, I am not sure how to make rounded edges without making them look awful.
private:
    float x, y, width, height, speed;
    string textPaddle;
    Color colorPaddle, colorText;

public:
    Paddle() = default;

    Paddle(float x, float y, float width, float height, float speed, string textPaddle, Color colorPaddle, Color colorText) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->speed = speed;
        this->textPaddle = textPaddle;
        this->colorPaddle = colorPaddle;
        this->colorText = colorText;
    }

    void draw(RenderWindow &window) {
        RectangleShape paddle(Vector2f(width, height));
        paddle.setPosition(x, y);
        paddle.setFillColor(colorPaddle);

        Font font;
        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

        Text text;
        text.setFont(font);
        text.setString(this->textPaddle);
        text.setCharacterSize(20);
        text.setFillColor(colorText);
        text.setPosition(x + (width - text.getLocalBounds().width)/2, y + (height - text.getLocalBounds().height)/2);

        window.draw(paddle);
        window.draw(text);
    }

    bool isMouseOver(Vector2i mousePos) {
        return mousePos.x >= x && mousePos.x <= x + width &&
               mousePos.y >= y && mousePos.y <= y + height;
    }

    void moveUp() {
        y -= speed;
    }

    void moveDown() {
        y += speed;
    }
};

#endif //PONG_GAME_PADDLE_H
