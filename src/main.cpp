#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Window", sf::Style::Default);
    sf::Event ev;
    while(window.isOpen())
    {
        while(window.pollEvent(ev))
        {
            if(ev.type == ev.Closed)
            window.close();
        }

        window.clear();
        
        window.display();
    }
}