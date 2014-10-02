#ifndef _VITAL_MANAGER_HPP_
#define _VITAL_MANAGER_HPP_

#include "Unit.hpp"
#include <vector>
#include <iterator>

using std::vector;

class VitalManager{
    vector<Unit*> _units;
public:
    VitalManager(){}
    void Update();
    void AddUnit(Unit& unit){_units.push_back(&unit);}
    void RemoveUnit(string name);
    ~VitalManager(){}
};

#endif
