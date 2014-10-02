#ifndef _MOTION_MANAGER_HPP_
#define _MOTION_MANAGER_HPP_

#include "Unit.hpp"
#include <vector>
#include <iterator>
#include "Renderer.hpp"

using std::vector;

class MotionRequest{
    Unit* _unit;
    Point _destination;
public:
    MotionRequest(Unit* unit, Point destination) : _unit{unit}, _destination{destination}{}
    string UserName(){return _unit->Name();}
    bool Completed();
    ~MotionRequest(){}
};

class MotionManager{
    vector<MotionRequest> _pending;
public:
    MotionManager(){}
    bool MakeRequest(Unit& unit, Point destination);
    bool CancelRequest(Unit& unit);
    void Update();
    ~MotionManager();
};

#endif
