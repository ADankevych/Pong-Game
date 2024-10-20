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

        window.clear();
        window.display();
    }
}
