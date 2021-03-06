#ifndef RECT_H
#define RECT_H

#include <SFML/Graphics.hpp>
#include "MyVector2D.h"
class Rect
{
    public:
        sf::RectangleShape shape;
        MyVector2D vel;
        MyVector2D acc;

        Rect(int window_width,int window_height);

        void draw(sf::RenderWindow& window);
        void move(int window_width,int window_height);
};


#endif // RECT_H
