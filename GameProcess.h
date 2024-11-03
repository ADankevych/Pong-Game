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
};

#endif //PONG_GAME_GAMEPROCESS_H
