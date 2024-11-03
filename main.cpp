#include "GameSettings.h"

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

    int playWithBorF = GameSettings::welcomePage(window);
    string playerName;
    string player2Name;
    if (playWithBorF == 1) {
        GameSettings::nameEntering(window, "Enter your name:", playerName);
        player2Name = "Bot";
    } else if (playWithBorF == 2) {
        GameSettings::nameEntering(window, "Enter player 1 name:", playerName);
        GameSettings::nameEntering(window, "Enter player 2 name:", player2Name);
    }

    int difficulty = GameSettings::chooseDifficulty(window);

    int mode = GameSettings::chooseMode(window);

    return 0;
}