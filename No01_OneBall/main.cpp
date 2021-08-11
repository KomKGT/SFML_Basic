#include <SFML/Graphics.hpp>
#include <time.h>
#include "MyVector2D.h"
#include "Ball.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Default, settings);
/***************Start Edit Section*******************/
    srand(time(NULL));
    sf::Vector2u window_size2 = window.getSize();

    class Ball balls;


        balls.vel.x = rand()%10-5;
        balls.vel.y = rand()%10-5;
        balls.acc.x = 0;
        balls.acc.y = 0.5;

        balls.circle.setPosition(rand()%window_size2.x,rand()%window_size2.y);
        balls.circle.setRadius(rand()%100);
        sf::Color color;
        color.r = rand()%255;
        color.g = rand()%255;
        color.b = rand()%255;
        balls.circle.setFillColor(color);


/***************End Edit Section*********************/
    while (window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
/***************Start Edit Section*******************/
        sf::Vector2u window_size = window.getSize();

        balls.move(window_size.x,window_size.y);



        balls.draw(&window);


/***************End Edit Section********************/

        window.display();
    }

    return 0;
}
