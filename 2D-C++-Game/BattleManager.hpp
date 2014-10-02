#include "Unit.hpp"
#include <vector>
#include <iterator>
#include <SDL2/SDL_timer.h>

using std::vector;

class AttackRequest{
    Unit* _attacker;
    Unit* _target;
public:
    //BattleManager creates the requests so no argument checking needed (i.e. no NULLPTR exception)
    AttackRequest(Unit* attacker, Unit* target) : _attacker{attacker}, _target{target}{}
    void Apply();
    string AttackerName(){return _attacker->Name();}
    ~AttackRequest(){}
};

class BattleManager{
    vector<AttackRequest> _pending;
public:
    BattleManager(){}
    void MakeRequest(Unit& attacker, Unit& target);
    void Update();
    ~BattleManager(){}
};
