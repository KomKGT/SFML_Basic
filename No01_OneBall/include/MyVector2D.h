#ifndef MYVECTOR2D_H
#define MYVECTOR2D_H


class MyVector2D
{
    public:
        double x,y;
        MyVector2D();
        MyVector2D(double x,double y);
        MyVector2D(const MyVector2D& v);

        MyVector2D add(MyVector2D v);
        MyVector2D sub(MyVector2D v);
        MyVector2D mul(double m);
        double dot(MyVector2D v);
        double size();
        MyVector2D unit();

        //Operator overload
        MyVector2D operator+(MyVector2D v);
        MyVector2D operator-(MyVector2D v);
        MyVector2D operator*(double m);
        double operator^(MyVector2D v);
};

#endif // MYVECTOR2D_H
