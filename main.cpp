#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int BOARD_WIDTH = 1080;
int BOARD_HEIGHT = 760;

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

        window.display();
    }
}
