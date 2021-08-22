#include "Rect.h"
#include <time.h>

Rect::Rect(int window_width,int window_height)
{
        vel.x = rand()%10-5;
        vel.y = rand()%10-5;
        acc.x = 0;
        acc.y = 0.4;

        shape.setPosition(rand()%window_width,rand()%window_height);

        sf::Vector2f size((rand()%155),(rand()%155));
        shape.setSize(size);
        sf::Color color;
        color.r = rand()%255;
        color.g = rand()%255;
        color.b = rand()%255;
        shape.setFillColor(color);
}
void Rect::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Rect::move(int window_width,int window_height)
{
    sf::Vector2f p = shape.getPosition();
    class MyVector2D pos(p.x,p.y);
    vel = vel.add(acc); //OR Can use  vel + acc;
            pos = pos + vel;

            if(pos.x + shape.getSize().x>window_width)
            {
                pos.x = window_width -  shape.getSize().x;
                vel.x = -1*vel.x;
            }
            if(pos.y+ shape.getSize().y>window_height)
            {
                pos.y = window_height-  shape.getSize().y;
                vel.y = -1*vel.y;
            }
            if(pos.x<0)
            {
                pos.x = 0;
                vel.x = -1*vel.x;
            }
            if(pos.y<0)
            {
                pos.y = 0;
                vel.y = -1*vel.y;
            }
            sf::Vector2f pos_now(pos.x,pos.y);
            shape.setPosition(pos_now);
}
