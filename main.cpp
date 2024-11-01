#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int BOARD_WIDTH = 1080;
int BOARD_HEIGHT = 760;

class Paddle { // it will be all in one - players' paddles, buttons design, etc.
    // Unfortunately, I am not sure how to make rounded edges without making them look awful.
private:
    int x, y, width, height, speed;
    string text;
    Color color;

public:
    Paddle(int x, int y, int width, int height, int speed, string text, Color color) {
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
        font.loadFromFile("/Users/anastasia_d/CLionProjects/asmt-5-game-engine-ADankevych/times-new-roman.ttf");
        text.setFont(font);
        text.setString(this->text);
        text.setCharacterSize(20);
        text.setFillColor(Color::White);
        text.setPosition(x + (width - text.getLocalBounds().width)/2, y + (height - text.getLocalBounds().height)/2);
        window.draw(text);
    }

};

int main()
{
    RenderWindow window(VideoMode(BOARD_WIDTH, BOARD_HEIGHT), "Pong");

    while (window.isOpen())
    {
        Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(190, 190, 190));
        Text text;
        Font font;
        font.loadFromFile("/Users/anastasia_d/CLionProjects/asmt-5-game-engine-ADankevych/times-new-roman.ttf");
        text.setFont(font);
        string textMessage = "Welcome to Pong game!";
        text.setString(textMessage);
        text.setCharacterSize(40);
        text.setFillColor(Color::Black);
        text.setPosition((BOARD_WIDTH - text.getLocalBounds().width)/2, BOARD_HEIGHT/3); // text.getLocalBounds().width - width of the text
        window.draw(text);

        textMessage = "Choose one option:";
        text.setString(textMessage);
        text.setCharacterSize(30);
        text.setPosition((BOARD_WIDTH - text.getLocalBounds().width)/2, BOARD_HEIGHT/3 + 100);
        window.draw(text);

        Paddle paddle1(BOARD_WIDTH/4, 450, 200, 50, 0, "Play with bot", Color::Black);
        Paddle paddle2(BOARD_WIDTH/4 + 325, 450, 200, 50, 0, "Play with friend", Color::Black);
        paddle1.draw(window);
        paddle2.draw(window);

        window.display();
    }
}
