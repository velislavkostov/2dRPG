#include "Unit.hpp"

void Unit::Draw(Renderer* renderer){
    renderer->Circle(_location,_size.h(),0,128,0,255);
}

bool Unit::IncreaseLimit(AttributeType type, int ammount){
    bool result = false;
    if(ammount > 0){
        switch(type){
        case AttributeType::HEALTH:
            _max_health += ammount;
            result = true;
            break;
        
        case AttributeType::MANA:
            _max_mana += ammount;
            result = true;
            break;
            
        default:
            break;
        }
    }
    return result;  
}

bool Unit::Give(AttributeType type, double ammount){
    bool result = false;
    if(ammount > 0){
        switch(type){
        case AttributeType::HEALTH:
            if(_health + ammount <= _max_health){
                _health += ammount;
                result = true;
            }
            else{
                _health = _max_health;
                result = true;
            }
            break;
            
        case AttributeType::MANA:
            if(_mana + ammount <= _max_mana){
                _mana += ammount;
                result = true;
            }    
            else{
                _mana = _max_mana;
                result = true;
            }
            break;
            
        case AttributeType::ARMOR:
            _armor += ammount;
            result = true;
            break;
            
        case AttributeType::DAMAGE:
            _damage += ammount;
            result = true;
            break;
            
        case AttributeType::GOLD:
            _gold += ammount;
            result = true;
            break;
        
        case AttributeType::EXPERIENCE:
            _experience += ammount;
            result = true;
            break;
        
        case AttributeType::SPEED:
            _speed += ammount;
            result = true;
            break;
        
        default:
            break;
        }
    }
    return result;
}

bool Unit::Take(AttributeType type, double ammount){
    bool result = false;
    if(ammount > 0){
        switch(type){
        case AttributeType::HEALTH:
            if(_health - ammount >= 1){
                _health -= ammount;
                result = true;
            }
            else{
                _health = 0;
                result = true;
            }
            break;
            
        case AttributeType::MANA:
            if(_mana - ammount >= 1){
                _mana -= ammount;
                result = true;
            }
            else{
                _mana = 0;
                result = true;
            }
            break;
            
        case AttributeType::ARMOR:
            if(_armor - ammount >= 1){
                _armor -= ammount;
                result = true;
            }
            else{
                _armor = 0;
                result = true;
            }
            break;

        case AttributeType::DAMAGE:
            if(_damage - ammount >= 1){
                _damage -= ammount;
                result = true;
            }
            else{
                _damage = 0;
                result = true;
            }
            break;
        
        //I'll give gold if I had one :D
        //Gold take mechanism for Shop
        case AttributeType::GOLD:
            if(_gold - ammount >= 1){
                _gold -= ammount;
                result = true;
            }
            break;
        
        case AttributeType::SPEED:
            if(_speed - ammount >= 1){
                _speed -= ammount;
                result = true;
            }
            break;
       
        //No need for take Experience because experience will only be given, not taken :) Yeeey !
        default:
            //Handling remaining switch values 
            break;    
        }
    }
    return result;
}

double Unit::Get(AttributeType type){
    double result = -1;
    switch(type){
    case AttributeType::HEALTH:
        result = _health;
        break;
        
    case AttributeType::MANA:
        result = _mana;
        break;
        
    case AttributeType::ARMOR:
        result = _armor;
        break;

    case AttributeType::DAMAGE:
        result = _damage;
        break;
    
    case AttributeType::GOLD:
        result = _gold;
        break;
    
    case AttributeType::EXPERIENCE:
        result = _experience;
        break;
        
    case AttributeType::SPEED:
        result = _speed;
        break;
    
    }
    return result;
}

string Unit::Report(AttributeType type){
    string result = "Report failed";
    switch(type){
    case AttributeType::HEALTH:
        result = to_string((int)_health);
        break;
        
    case AttributeType::MANA:
        result = to_string((int)_mana);
        break;

    case AttributeType::ARMOR:
        result = to_string((int)_armor);
        break;
        
    case AttributeType::DAMAGE:
        result = to_string((int)_damage);
        break;
        
    case AttributeType::GOLD:
        result = to_string((int)_gold);
        break;
        
    case AttributeType::EXPERIENCE:
        result = to_string((int)_experience);
        break;
        
    case AttributeType::SPEED:
        result = to_string((int)_speed);
        break;
    }
    return result;
}
