#include "GameSettings.h"
#include "GameProcess.h"

void gameProcessFriends(RenderWindow &window) {
    while (window.isOpen()) {
        window.clear(Color(190, 190, 190));
        window.display();
    }
}

void gameProcessBot(RenderWindow &window) {
    while (window.isOpen()) {
        window.clear(Color(190, 190, 190));
        window.display();
    }
}


int main() {
    RenderWindow window(VideoMode(BOARD_WIDTH, BOARD_HEIGHT), "Pong");
    GameProcess gameProcess;

    int playWithBorF = GameSettings::welcomePage(window);
    gameProcess.setModeAndDifficulty(1, 1);

    if (playWithBorF == 1) {
        gameProcess.setNamePlayer1(GameSettings::nameEntering(window, "Enter your name:"));
        gameProcess.setNamePlayer2("Bot");
    } else if (playWithBorF == 2) {
        gameProcess.setNamePlayer1(GameSettings::nameEntering(window, "Enter player 1 name:"));
        gameProcess.setNamePlayer2(GameSettings::nameEntering(window, "Enter player 2 name:"));
    }

    gameProcess.setModeAndDifficulty(GameSettings::chooseDifficulty(window), GameSettings::chooseMode(window));
    gameProcess.draw(window);
    return 0;
}