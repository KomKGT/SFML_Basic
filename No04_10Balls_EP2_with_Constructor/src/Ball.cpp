#include "Ball.h"

Ball::Ball(int window_width,int window_height)
{
        vel.x = rand()%10-5;
        vel.y = rand()%10-5;
        acc.x = 0;
        acc.y = 0.4;

        circle.setPosition(rand()%window_width,rand()%window_height);
        circle.setRadius(rand()%100);
        sf::Color color;
        color.r = rand()%255;
        color.g = rand()%255;
        color.b = rand()%255;
        circle.setFillColor(color);
}
void Ball::draw(sf::RenderWindow& window)
{
    window.draw(circle);
}

void Ball::move(int window_width,int window_height)
{
    sf::Vector2f p = circle.getPosition();
    class MyVector2D pos(p.x,p.y);
    vel = vel.add(acc); //OR Can use  vel + acc;
            pos = pos + vel;

            if(pos.x + 2*circle.getRadius()>window_width)
            {
                pos.x = window_width -  2*circle.getRadius();
                vel.x = -1*vel.x;
            }
            if(pos.y+ 2*circle.getRadius()>window_height)
            {
                pos.y = window_height-  2*circle.getRadius();
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
            circle.setPosition(pos_now);
}
