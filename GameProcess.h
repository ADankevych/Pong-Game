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



    void setDif() {
        switch (difficulty) {
            case 1:
                player1.setPaddle(Paddle((BOARD_WIDTH - 40) / 4 * 3, (BOARD_HEIGHT - 200) / 2, 40, 200, 20, "", colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - 40) / 4, (BOARD_HEIGHT - 200) / 2, 40, 200, 20, "", colorPaddle, colorPaddle));
                ball.setSpeed(10);
                ball.setSize(50);
                break;
            case 2:
                player1.setPaddle(Paddle((BOARD_WIDTH - 30) / 4 * 3, (BOARD_HEIGHT - 150) / 2, 30, 150, 10, "", colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - 30) / 4, (BOARD_HEIGHT - 150) / 2, 30, 150, 10, "", colorPaddle, colorPaddle));
                ball.setSpeed(20);
                ball.setSize(40);
                break;
            case 3:
                player1.setPaddle(Paddle((BOARD_WIDTH - 20) / 4 * 3, (BOARD_HEIGHT - 75) / 2, 20, 75, 10, "", colorPaddle, colorPaddle));
                player2.setPaddle(Paddle((BOARD_WIDTH - 20) / 4, (BOARD_HEIGHT - 75) / 2, 20, 75, 10, "", colorPaddle, colorPaddle));
                ball.setSpeed(30);
                ball.setSize(30);
                break;
        }
    }

    void draw(RenderWindow &window) {
        while (window.isOpen()) {


            Event event{};

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
            }




            window.draw(player1.draw(window));
            window.draw(player2.draw(window));
            window.draw(ball.draw(window));

            window.display();
        }
    }

};

#endif //PONG_GAME_GAMEPROCESS_H
