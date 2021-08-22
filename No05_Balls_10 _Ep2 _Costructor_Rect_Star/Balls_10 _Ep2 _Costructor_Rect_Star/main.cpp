#include <SFML/Graphics.hpp>
#include <time.h>
#include "MyVector2D.h"
#include "Ball.h"
#include "Rect.h"
#include "Star.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default, settings);
/***************Start Edit Section*******************/
    srand(time(NULL));
    sf::Vector2u window_size2 = window.getSize();

    class Ball** balls = new Ball*[10]; //สร้างอาเรย์ของพ้อยเตอร์ไปยัง class Ball (** หมายถึงแทน อาเรย์ 1ชั้นและพ้อยเตอร์ 1 ชั้น)

    for(int i =0;i<10;i++)
    {
       balls[i] = new Ball(window_size2.x,window_size2.y);
    }

    class Rect** rects = new Rect*[10]; //สร้างอาเรย์ของพ้อยเตอร์ไปยัง class Ball (** หมายถึงแทน อาเรย์ 1ชั้นและพ้อยเตอร์ 1 ชั้น)

    for(int i =0;i<10;i++)
    {
       rects[i] = new Rect(window_size2.x,window_size2.y);
    }

    class Star** stars = new Star*[10];
    for(int i =0;i<10;i++)
    {
       stars[i] = new Star(window_size2.x,window_size2.y);
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
            balls[i]->move(window_size.x,window_size.y);
        }

        for(int i = 0;i<10;i++)
        {
            balls[i]->draw(window);
        }

        for(int i=0;i<10;i++)
        {
            rects[i]->move(window_size.x,window_size.y);

        }
        for(int i = 0;i<10;i++)
        {
            rects[i]->draw(window);
        }

        for(int i=0;i<10;i++)
        {
            stars[i]->move(window_size.x,window_size.y);

        }
        for(int i = 0;i<10;i++)
        {
            stars[i]->draw(window);
        }
/***************End Edit Section********************/

        window.display();
    }
    for(int i = 0;i<10;i++)
    {
            delete balls[i];  //delete ลูกบอลจริงๆ
    }
    delete [] balls; // delete array ที่เก็บ poiter ไปยังลูกบอล

    for(int i = 0;i<10;i++)
    {
            delete rects[i];  //delete ลูกบอลจริงๆ
    }
    delete [] rects; // delete array ที่เก็บ poiter ไปยังลูกบอล

    for(int i = 0;i<10;i++)
    {
            delete stars[i];  //delete ลูกบอลจริงๆ
    }
    delete [] stars; // delete array ที่เก็บ poiter ไปยังลูกบอล
    return 0;
}
