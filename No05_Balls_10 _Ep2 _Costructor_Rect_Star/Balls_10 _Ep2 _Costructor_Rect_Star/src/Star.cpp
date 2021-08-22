#include "Star.h"
#include <cmath>

#define PI 3.1415926
#define TWO_PI 2*3.1415926


Star::Star(int window_width,int window_height)
{
        N = 5;
        size = rand()%85;
        vel.x = rand()%10-5;
        vel.y = rand()%10-5;
        acc.x = 0;
        acc.y = 0.4;

        for(int i = 0;i<N;i++)
        {
            shape[i].setPointCount(4);
            shape[i].setPoint(0,sf::Vector2f(0,0));

            double Angle_now = TWO_PI/N*i;
            double Angle_half_step = TWO_PI/N/2.0;
            shape[i].setPoint(1,sf::Vector2f(size/2*cos(Angle_now - Angle_half_step),size/2 * sin(Angle_now-Angle_half_step)));
            shape[i].setPoint(2,sf::Vector2f(size*cos(Angle_now),size*sin(Angle_now)));
            shape[i].setPoint(1,sf::Vector2f(size/2*cos(Angle_now + Angle_half_step),size/2 * sin(Angle_now+Angle_half_step)));

        }
        sf::Color color;
        color.r = rand()%255;
        color.g = rand()%255;
        color.b = rand()%255;

        for(int i =0;i<N;i++)
        {
          shape[i].setFillColor(color);

        }
        for(int i=0;i<N;i++)
        {
          shape[i].setPosition(rand()%window_width,rand()%window_height);

        }
}
void Star::draw(sf::RenderWindow& window)
{
    for(int i =0;i<N;i++)
        {
          window.draw(this->shape[i]);

        }
}

void Star::move(int window_width,int window_height)
{
    sf::Vector2f p = shape[0].getPosition();
    class MyVector2D pos(p.x,p.y);
    vel = vel.add(acc); //OR Can use  vel + acc;
            pos = pos + vel;

            if(pos.x + size>window_width)
            {
                pos.x = window_width -  size;
                vel.x = -1*vel.x;
            }
            if(pos.y+ size>window_height)
            {
                pos.y = window_height-  size;
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
            for(int i = 0;i<N;i++)
            {
                shape[i].setPosition(pos_now);

            }

}
