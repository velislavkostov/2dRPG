#include "VitalManager.hpp"

void VitalManager::Update(){
    vector<Unit*>::iterator b, e;
    b = _units.begin();
    e = _units.end();
    for(; b != e; ++b){
        (*b)->Give(AttributeType::GOLD, 0.25 + rand() % 4 + 1);
        (*b)->Give(AttributeType::HEALTH, rand() % 5 + 2.5);
    }
}

void VitalManager::RemoveUnit(string name){
    vector<Unit*>::iterator b, e;
    b = _units.begin();
    e = _units.end();
    for(; b != e; ++b){
        if((*b)->Name() == name){
            _units.erase(b);
            break;
        }
    }
}
