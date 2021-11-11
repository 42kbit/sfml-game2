#include "SFML/Graphics.hpp"

int main()
{
    const uint32_t width = 512u, height = 512u;
    sf::RenderWindow window(sf::VideoMode(width, height), "Interpolation!", sf::Style::Default);
    sf::Event ev;

    float points[4] = 
    {
        128.f, 0.5f, 0.1f, 0.7f // up-left, up-right, down-right, down-left
    };

    sf::Image img;
    img.create(width, height, sf::Color::Transparent);

    for(uint32_t i = 0; i < width; i++)
        for(uint32_t j = 0; j < height; j++)
        {
            float pointWeightX = (float)i / width;
            float h1 = points[0] * (1.f - pointWeightX) + points[1] * pointWeightX;
            float h2 = points[3] * (1.f - pointWeightX) + points[2] * pointWeightX;

            float pointWeightY = (float)j / height;
            float pointHeight = h1 * pointWeightY + h2 * (1.f - pointWeightY);

            img.setPixel(i, height - j, sf::Color(pointHeight, pointHeight, pointHeight));
        }

    sf::Texture texture;
    texture.loadFromImage(img);
    sf::Sprite sprite(texture);

    while(window.isOpen())
    {
        while(window.pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed) 
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}