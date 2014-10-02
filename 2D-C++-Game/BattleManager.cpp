#include "BattleManager.hpp"

void AttackRequest::Apply(){
    if(_target->Get(AttributeType::ARMOR) >= 1){
        _target->Take(AttributeType::HEALTH, _attacker->Get(AttributeType::DAMAGE) - _target->Get(AttributeType::ARMOR));
    }
    else{
        _target->Take(AttributeType::HEALTH, _attacker->Get(AttributeType::DAMAGE));
    }
}

void BattleManager::MakeRequest(Unit& attacker, Unit& target){
    vector<AttackRequest>::iterator b, e;
    b = _pending.begin();
    e = _pending.end();
    bool duplicate_task = false;
    for(; b != e; b++){
        if(attacker.Name() == (*b).AttackerName()){
            duplicate_task = true;
            break;
        }
    }
    if(duplicate_task){
        _pending.erase(b);
        _pending.insert(b, AttackRequest(&attacker, &target));
    }
    else{
        _pending.push_back(AttackRequest(&attacker, &target));
    }
}

void BattleManager::Update(){
    vector<AttackRequest>::iterator b, e;
    b = _pending.begin();
    e = _pending.end();
    for(; b != e; b++){
        (*b).Apply();
        _pending.erase(b);
    }
}
