#ifndef _UNIT_HPP_
#define _UNIT_HPP_

#include "Renderer.hpp"

using std::string;
using std::to_string;

/** Polymorphic type Unit, Base for every controllable/non-controllable Unit **/
enum class AttributeType{HEALTH, MANA, DAMAGE, ARMOR, GOLD, EXPERIENCE, SPEED};

class Unit{
    string _name;
    Point _location;
    Size _size;
    double _health;
    double _mana;
    double _armor;
    double _damage;
    double _gold;
    double _experience;
    double _speed;
    int _max_health;
    int _max_mana;
public:
    //virtual Point Direction(){return _direction;}
    Unit(string name, Point location, Size s, int health, int mana, int armor, int damage, int gold, int experience, int speed) :
        _name{name}, _location{location}, _size{s}, _health{(double)health}, _mana{(double)mana}, _armor{(double)armor}, _damage{(double)damage},
        _gold{(double)gold}, _experience{(double)experience}, _speed{(double)speed}, _max_health{health}, _max_mana{mana}{}
        //^OP c-tor
    string Name(){return _name;}
    void SetLocation(Point p){_location = p;}
    Point GetLocation() const {return _location;}
    void SetSize(Size s){_size = s;}
    Size GetSize() const {return _size;}
    virtual void Draw(Renderer* renderer);
    bool IncreaseLimit(AttributeType type, int ammount);
    bool Give(AttributeType type, double ammount);
    bool Take(AttributeType type, double ammount);
    double Get(AttributeType type);
    string Report(AttributeType type);
    virtual ~Unit(){}
};

#endif // _UNIT_HPP_
