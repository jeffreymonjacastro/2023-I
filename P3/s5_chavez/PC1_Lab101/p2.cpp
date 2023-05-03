#include <iostream>
#include <vector>

using namespace std;

// Implemente aqui las clases y su relacion de herencia , si
// es que existe :
// - Figure ( Clase Base )
// - Circle
// - Rectangle
// - Triangle
// - Point2d

class Point2d {
public:
    int x;
    int y;

    Point2d(int n, int m): x(n), y(m){}

    ~Point2d() = default;
};

class Figure {
protected:
    int lados = 0;
    vector<Point2d> puntos;
public:
    virtual void print() = 0;
};

class Circle: public Figure {
private:
    int radio;
public:
    Circle(Point2d punto, int r){
        puntos.push_back(punto);
        radio = r;
    }

    void print(){
        cout<<"Circle: ("<<puntos[0].x<<", "<<puntos[0].y<<"), radio: "<<radio<<endl;
    }

    virtual ~Circle() = default;
};

class Rectangle: public Figure {
public:
    Rectangle(Point2d p1, Point2d p2){
        lados = 4;
        puntos.push_back(p1);
        puntos.push_back(p2);
    }

    void print(){
        cout<<"Rectangle: ("<<puntos[0].x<<", "<<puntos[0].y<<"), "<<"("<<puntos[1].x<<", "<<puntos[1].y<<")"<<endl;
    }

    virtual ~Rectangle() = default;
};


class Triangle: public Figure {
private:
public:
    Triangle(Point2d p1, Point2d p2, Point2d p3){
        puntos.push_back(p1);
        puntos.push_back(p2);
        puntos.push_back(p3);
    }

    void print(){
        cout<<"Triangle: ("<<puntos[0].x<<", "<<puntos[0].y<<"), "<<"("<<puntos[1].x<<", "<<puntos[1].y<<"), "<<"("<<puntos[2].x<<", "<<puntos[2].y<<")"<<endl;
    }

    virtual ~Triangle() = default;
};

void print(Figure* f) {
    f -> print() ;
}

int main(){
    Figure* f[3];
    f[0] = new Circle(Point2d(1,2),3);
    f[1] = new Rectangle(Point2d(1,2),Point2d(3,4));
    f[2] = new Triangle (Point2d (1,2), Point2d (3, 4),Point2d (5 , 6) ) ;

    for (int i = 0; i < 3; i ++) {
        print (f [i]) ;
    }

    return 0;
}