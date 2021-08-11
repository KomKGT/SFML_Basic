#include <SFML/Graphics.hpp>
#include <time.h>
#include "MyVector2D.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);
/***************Start Edit Section*******************/
    srand(time(NULL));
    sf::Vector2u window_size2 = window.getSize();

    sf::CircleShape circle[10];
    class MyVector2D vel[10];
    class MyVector2D acc[10];

    for(int i =0;i<10;i++)
    {
        vel[i].x = rand()%10-5;
        vel[i].y = rand()%10-5;
        acc[i].x = 0;
        acc[i].y = 0.4;

        circle[i].setPosition(rand()%window_size2.x,rand()%window_size2.y);
        circle[i].setRadius(rand()%100);
        sf::Color color;
        color.r = rand()%255;
        color.g = rand()%255;
        color.b = rand()%255;
        circle[i].setFillColor(color);

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
            sf::Vector2f p = circle[i].getPosition();
            class MyVector2D pos(p.x,p.y);
            vel[i] = vel[i].add(acc[i]); //OR Can use  vel[i] + acc[i];
            pos = pos + vel[i];

            if(pos.x + 2*circle[i].getRadius()>window_size.x)
            {
                pos.x = window_size.x -  2*circle[i].getRadius();
                vel[i].x = -1*vel[i].x;
            }
            if(pos.y+ 2*circle[i].getRadius()>window_size.y)
            {
                pos.y = window_size.y-  2*circle[i].getRadius();
                vel[i].y = -1*vel[i].y;
            }
            if(pos.x<0)
            {
                pos.x = 0;
                vel[i].x = -1*vel[i].x;
            }
            if(pos.y<0)
            {
                pos.y = 0;
                vel[i].y = -1*vel[i].y;
            }
            sf::Vector2f pos_now(pos.x,pos.y);
            circle[i].setPosition(pos_now);

            window.draw(circle[i]);
        }

/***************End Edit Section********************/

        window.display();
    }

    return 0;
}
