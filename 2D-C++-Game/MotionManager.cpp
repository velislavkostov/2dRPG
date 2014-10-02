#include "MotionManager.hpp"

bool MotionRequest::Completed(){
    if(_unit->GetLocation() != _destination){
        if(_unit->GetLocation().x() > _destination.x()){
            _unit->SetLocation(Point(_unit->GetLocation().x() - 1, _unit->GetLocation().y()));
        }
        if(_unit->GetLocation().x() < _destination.x()){
            _unit->SetLocation(Point(_unit->GetLocation().x() + 1, _unit->GetLocation().y()));
        }
        if(_unit->GetLocation().y() > _destination.y()){
            _unit->SetLocation(Point(_unit->GetLocation().x(), _unit->GetLocation().y() - 1));
        }
        if(_unit->GetLocation().y() < _destination.y()){
            _unit->SetLocation(Point(_unit->GetLocation().x(), _unit->GetLocation().y() + 1));
        }
        return false;
    }
    return true;
}

void MotionManager::Update(){
    vector<MotionRequest>::iterator b, e;
    b = _pending.begin();
    e = _pending.end();
    for(;b != e; ++b){
        if((*b).Completed()){
            _pending.erase(b);
        }
    }
}

bool MotionManager::MakeRequest(Unit& unit, Point destination){
    if(unit.GetLocation() != destination){
        vector<MotionRequest>::iterator b, e;
        b = _pending.begin();
        e = _pending.end();
        bool duplicate_task = false;
        for(;b != e; b++){
            if(unit.Name() == (*b).UserName()){
                duplicate_task = true;
                break;
            }
        }
        if(duplicate_task){
            _pending.erase(b);
            _pending.insert(b, MotionRequest(&unit, destination));
        }
        else{
            _pending.push_back(MotionRequest(&unit, destination));
        }  
        return true;
    }
    return false;
}

bool MotionManager::CancelRequest(Unit& unit){
    vector<MotionRequest>::iterator b, e;
    b = _pending.begin();
    e = _pending.end();
    for(; b != e; ++b){
        if(unit.Name() == (*b).UserName()){
            _pending.erase(b);
            return true;
        }
    }
    return false;
}

MotionManager::~MotionManager(){
    vector<MotionRequest>::iterator b, e; 
    b = _pending.begin();
    e = _pending.end();
    for(; b != e; b++){
        _pending.erase(b);
    }
}
