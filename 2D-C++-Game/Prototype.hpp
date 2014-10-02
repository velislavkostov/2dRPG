#ifndef _PROTOTYPE_HPP_
#define _PROTOTYPE_HPP_

#include "Unit.hpp"

class Prototype: public Unit{
    
public:
    Prototype(string name, Point p) : Unit(name, p, Size(50,50), 675, 675 / 3, 15, 80, 375, 0, 50){}
    void Draw(Renderer* renderer){
        /*
        renderer->Circle(Point(GetLocation().x(), GetLocation().y() - 20), 10, 255, 255, 255, 255);
        renderer->Line(Point(GetLocation().x(), GetLocation().y() - 10), Point(GetLocation().x(), GetLocation().y() + 20), 255, 0, 0, 255);
        renderer->Line(Point(GetLocation().x(), GetLocation().y() - 10), Point(GetLocation().x() - 10, GetLocation().y() + 10), 255, 0, 0, 255); 
        renderer->Line(Point(GetLocation().x(), GetLocation().y() - 10), Point(GetLocation().x() + 10, GetLocation().y() + 10), 255, 0, 0, 255);
        renderer->Line(Point(GetLocation().x(), GetLocation().y() + 20), Point(GetLocation().x() - 10, GetLocation().y() + 30), 255, 0, 0, 255); 
        renderer->Line(Point(GetLocation().x(), GetLocation().y() + 20), Point(GetLocation().x() + 10, GetLocation().y() + 30), 255, 0, 0, 255);  
        
        //renderer->Image("pic2.png", GetLocation(), GetSize());
        */
        renderer->RoundedRectangle(GetLocation() , GetSize(), 15, rand() % 256, rand() % 256, rand() % 256, 255);
        renderer->RoundedBox(Point(GetLocation().x() + GetSize().w() / 2, GetLocation().y() + GetSize().h() / 2), Size(GetSize().w() / 4, GetSize().h() / 4), 5, rand() % 256, rand() % 256, rand() % 256, 255);    
    }
    ~Prototype(){}
};

#endif 
