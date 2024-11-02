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

    int playWithBorF = welcomePage(window);
    string playerName;
    string player2Name;
    if (playWithBorF == 1) {
        nameEntering(window, "Enter your name:", playerName);
        player2Name = "Bot";
    } else if (playWithBorF == 2) {
        nameEntering(window, "Enter player 1 name:", playerName);
        nameEntering(window, "Enter player 2 name:", player2Name);
    }

    int difficulty = chooseDifficulty(window);

    int mode = chooseMode(window);

    return 0;
}