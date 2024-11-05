#include "GameSettings.h"
#include "GameProcess.h"

int main() {
    RenderWindow window(VideoMode(BOARD_WIDTH, BOARD_HEIGHT), "Pong");
    GameProcess gameProcess;

    gameProcess.startNewGame(window);

    return 0;
}