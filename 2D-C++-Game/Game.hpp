#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "Prototype.hpp"
#include "VitalManager.hpp"
#include "MotionManager.hpp"
#include "BattleManager.hpp"
#include "Renderer.hpp"
#include "Prototype.hpp"

//Put event handler somewhere in the Game, not in the Main you dummy ;d

class Game{
    std::vector<Unit*> _players;
    VitalManager _vitalManager;
    MotionManager _motionManager;
    BattleManager _battleManager;
    Renderer _renderer;
    Point _cursor_position;
    bool _running;
    void UpdateCursorPosition();
    void Draw();
public:
    Game(): _renderer{Renderer(1440,768)}{}
    void Update();
    int Players(){return _players.size();}
    void CreatePlayer(string name, Point p);
    void RemovePlayer(string name);
    bool Running(){return _running;}
    void Quit(){_running = false;}
    ~Game();
};

#endif
