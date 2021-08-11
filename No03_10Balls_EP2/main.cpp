#include <SFML/Graphics.hpp>
#include <time.h>
#include "MyVector2D.h"
#include "Ball.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);
/***************Start Edit Section*******************/
    srand(time(NULL));
    sf::Vector2u window_size2 = window.getSize();

    class Ball balls[10];

    for(int i =0;i<10;i++)
    {
        balls[i].vel.x = rand()%10-5;
        balls[i].vel.y = rand()%10-5;
        balls[i].acc.x = 0;
        balls[i].acc.y = 0.4;

        balls[i].circle.setPosition(rand()%window_size2.x,rand()%window_size2.y);
        balls[i].circle.setRadius(rand()%100);
        sf::Color color;
        color.r = rand()%255;
        color.g = rand()%255;
        color.b = rand()%255;
        balls[i].circle.setFillColor(color);

    }
/***************End Edit Section*********************/
/***************Start Edit Section*******************/



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
        for(int i = 0;i<10;i++)
        {
            balls[i].move(window_size.x,window_size.y);
        }

        for(int i = 0;i<10;i++)
        {
            balls[i].draw(window);
        }

/***************End Edit Section********************/

        window.display();
    }

    return 0;
}
