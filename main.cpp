#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

float BOARD_WIDTH = 1080;
float BOARD_HEIGHT = 760;

class Paddle { // it will be all in one - players' paddles, buttons design, etc.
    // Unfortunately, I am not sure how to make rounded edges without making them look awful.
private:
    float x, y, width, height, speed;
    string text;
    Color color;

public:
    Paddle(float x, float y, float width, float height, float speed, string text, Color color) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->speed = speed;
        this->text = text;
        this->color = color;
    }

    void draw(RenderWindow &window) {
        RectangleShape paddle(Vector2f(width, height));
        paddle.setPosition(x, y);
        paddle.setFillColor(color);

        Font font;
        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

        Text text;
        text.setFont(font);
        text.setString(this->text);
        text.setCharacterSize(20);
        text.setFillColor(Color::White);
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

void nameEntering(RenderWindow &window, string message, string &playerName) {
    Font font;
    font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

    Text nameText;
    nameText.setFont(font);
    nameText.setCharacterSize(30);
    nameText.setFillColor(Color::Black);

    Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(30);
    text.setFillColor(Color::Black);
    text.setPosition((BOARD_WIDTH - text.getLocalBounds().width) / 2, BOARD_HEIGHT / 3);

    Event event{};

    while (window.isOpen()) {
        window.clear(Color(190, 190, 190));
        window.draw(text);

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == '\b') {
                        if (!playerName.empty())
                            playerName.pop_back();
                    } else if (event.text.unicode == '\n') {
                        return;
                    } else {
                        playerName += static_cast<char>(event.text.unicode);
                    }
                }
            }
        }

        nameText.setString(playerName);
        nameText.setPosition((BOARD_WIDTH - nameText.getLocalBounds().width) / 2, BOARD_HEIGHT / 3 + 150);

        window.draw(nameText);
        window.display();
    }
}

int welcomePage(RenderWindow &window){
    Paddle paddle1(BOARD_WIDTH / 4, 450, 200, 50, 0, "Play with bot", Color::Black);
    Paddle paddle2(BOARD_WIDTH / 4 + 325, 450, 200, 50, 0, "Play with friend", Color::Black);

    Font font;
    font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

    Text textWelcome;
    textWelcome.setFont(font);
    textWelcome.setString("Welcome to Pong game!");
    textWelcome.setCharacterSize(40);
    textWelcome.setFillColor(Color::Black);
    textWelcome.setPosition((BOARD_WIDTH - textWelcome.getLocalBounds().width)/2, BOARD_HEIGHT/3); // text.getLocalBounds().width - width of the text

    Text textChoose;
    textChoose.setFont(font);
    textChoose.setString("Choose one option:");
    textChoose.setCharacterSize(30);
    textChoose.setFillColor(Color::Black);
    textChoose.setPosition((BOARD_WIDTH - textChoose.getLocalBounds().width)/2, BOARD_HEIGHT/3 + 100);

    while (window.isOpen()) {
        window.clear(Color(190, 190, 190));

        window.draw(textWelcome);
        window.draw(textChoose);

        paddle1.draw(window);
        paddle2.draw(window);

        Event event{};

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    if (paddle1.isMouseOver(mousePos)) {
                        return 1;
                    } else if (paddle2.isMouseOver(mousePos)) {
                        return 2;
                    }
                }
            }
        }
        window.display();
    }
    return 0;
}

int chooseDifficulty(RenderWindow &window) {
    Paddle paddle1((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 100, 200, 45, 0, "Easy", Color::Black);
    Paddle paddle2((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 200, 200, 45, 0, "Medium", Color::Black);
    Paddle paddle3((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 300, 200, 45, 0, "Hard", Color::Black);

    Font font;
    font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

    Text textDifficulty;
    textDifficulty.setFont(font);
    textDifficulty.setString("Choose difficulty:");
    textDifficulty.setCharacterSize(35);
    textDifficulty.setFillColor(Color::Black);
    textDifficulty.setPosition((BOARD_WIDTH - textDifficulty.getLocalBounds().width)/2, BOARD_HEIGHT/3);

    while (window.isOpen()) {
        window.clear(Color(190, 190, 190));

        window.draw(textDifficulty);

        paddle1.draw(window);
        paddle2.draw(window);
        paddle3.draw(window);

        Event event{};

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    if (paddle1.isMouseOver(mousePos)) {
                        return 1;
                    } else if (paddle2.isMouseOver(mousePos)) {
                        return 2;
                    } else if (paddle3.isMouseOver(mousePos)) {
                        return 3;
                    }
                }
            }
        }
        window.display();
    }
    return 0;
}

int chooseMode(RenderWindow &window) {
    Paddle paddle1((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 100, 200, 50, 0, "Default", Color::Black);
    Paddle paddle2((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 200, 200, 50, 0, "Hello Kitty", Color(255, 105, 180));
    Paddle paddle3((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 300, 200, 50, 0, "Halloween", Color::Black);
    Paddle paddle4((BOARD_WIDTH - 200) / 2, BOARD_HEIGHT / 3 + 400, 200, 50, 0, "Christmas", Color::Blue);

    Font font;
    font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

    Text textMode;
    textMode.setFont(font);
    textMode.setString("Cool!\nChoose mode:");
    textMode.setCharacterSize(35);
    textMode.setFillColor(Color::Black);
    textMode.setPosition((BOARD_WIDTH - textMode.getLocalBounds().width)/2, BOARD_HEIGHT/3);

    while (window.isOpen()) {
        window.clear(Color(190, 190, 190));

        window.draw(textMode);

        paddle1.draw(window);
        paddle2.draw(window);
        paddle3.draw(window);
        paddle4.draw(window);

        Event event{};

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    if (paddle1.isMouseOver(mousePos)) {
                        return 1;
                    } else if (paddle2.isMouseOver(mousePos)) {
                        return 2;
                    } else if (paddle3.isMouseOver(mousePos)) {
                        return 3;
                    } else if (paddle4.isMouseOver(mousePos)) {
                        return 4;
                    }
                }
            }
        }
        window.display();
    }
    return 0;
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