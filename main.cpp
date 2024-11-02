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
        window.draw(paddle);

        Text text;
        Font font;
        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");
        text.setFont(font);
        text.setString(this->text);
        text.setCharacterSize(20);
        text.setFillColor(Color::White);
        text.setPosition(x + (width - text.getLocalBounds().width)/2, y + (height - text.getLocalBounds().height)/2);
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


void gameProcessBot(RenderWindow &window) {
    while (window.isOpen()) {
        window.clear(Color(190, 190, 190));
        window.display();
    }
}

void playBot(RenderWindow &window) {
    string playerName;
    Text nameText;
    Font font;
    font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");

    nameText.setFont(font);
    nameText.setCharacterSize(30);
    nameText.setFillColor(Color::Black);

    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == '\b') {
                        if (!playerName.empty())
                            playerName.pop_back();
                    } else if (event.text.unicode == '\n') {
                        gameProcessBot(window);
                    } else {
                        playerName += static_cast<char>(event.text.unicode);
                    }
                }
            }
        }

        nameText.setString(playerName);
        nameText.setPosition((BOARD_WIDTH - nameText.getLocalBounds().width) / 2, BOARD_HEIGHT / 3 + 150);

        window.clear(Color(190, 190, 190));

        Text text;
        text.setFont(font);
        text.setString("Enter your name:");
        text.setCharacterSize(30);
        text.setFillColor(Color::Black);
        text.setPosition((BOARD_WIDTH - text.getLocalBounds().width) / 2, BOARD_HEIGHT / 3);
        window.draw(text);

        window.draw(nameText);

        window.display();
    }
}

void firstPage(RenderWindow &window){
    Paddle paddle1(BOARD_WIDTH / 4, 450, 200, 50, 0, "Play with bot", Color::Black);
    Paddle paddle2(BOARD_WIDTH / 4 + 325, 450, 200, 50, 0, "Play with friend", Color::Black);

    while (window.isOpen()) {
        window.clear(Color(190, 190, 190));

        Text text;
        Font font;
        font.loadFromFile("/Users/anastasia_d/CLionProjects/Pong-Game/timesnewromanpsmt.ttf");
        text.setFont(font);
        text.setString("Welcome to Pong game!");
        text.setCharacterSize(40);
        text.setFillColor(Color::Black);
        text.setPosition((BOARD_WIDTH - text.getLocalBounds().width)/2, BOARD_HEIGHT/3); // text.getLocalBounds().width - width of the text
        window.draw(text);

        text.setString("Choose one option:");
        text.setCharacterSize(30);
        text.setPosition((BOARD_WIDTH - text.getLocalBounds().width)/2, BOARD_HEIGHT/3 + 100);
        window.draw(text);

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
                        playBot(window);
                    } else if (paddle2.isMouseOver(mousePos)) {
                        // playFriend(window);
                    }
                }
            }
        }

        window.display();
    }

}

int main() {
    RenderWindow window(VideoMode(BOARD_WIDTH, BOARD_HEIGHT), "Pong");

    firstPage(window);
    return 0;
}