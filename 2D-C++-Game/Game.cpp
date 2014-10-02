#include "Game.hpp"

void Game::UpdateCursorPosition(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    _cursor_position = Point(x, y);
}

void Game::CreatePlayer(string name, Point p){
    //Resolve conflicting names on creation
    _players.push_back(new Prototype(name, p));
    _vitalManager.AddUnit(*_players.back());
    _motionManager.MakeRequest(*_players.back(), Point(rand() % _renderer.GetWidth(), rand() % _renderer.GetHeight()));
}

void Game::RemovePlayer(string name){
    vector<Unit*>::iterator b, e;
    b = _players.begin();
    e = _players.end();
    for(; b != e; ++b){
        if((*b)->Name() == name){
            _vitalManager.RemoveUnit(name);
            _motionManager.CancelRequest(*(*b));
            (*b)->~Unit();
            _players.erase(b);
            //Delete first occurance
            //Multiple deletion causes segfault due to vector reallocation/move (consistent memory)
            break;
        }
    }
}

void Game::Draw(){
    _renderer.String(Point(0,20), "Players: " + to_string(Players()), 0, 255, 0, 255);
    _renderer.String(Point(0,0), "Rendered in: " + to_string(_renderer.RenderDuration()) + " ms", 0, 0, 255, 255);
    vector<Unit*>::iterator b, e;
    b = _players.begin();
    e = _players.end();
    for(; b != e; ++b)
        (*b)->Draw(&_renderer);
    //_renderer.Image("cursor.png", _cursor_position, Size(25, 25));
    _renderer.Render();
}

void Game::Update(){
    if(Running()){
        UpdateCursorPosition();
        _motionManager.Update();
        _vitalManager.Update();
        _battleManager.Update();
        Draw();
    }
}

Game::~Game(){
    vector<Unit*>::iterator b, e;
    b = _players.begin();
    e = _players.end();
    for(; b != e; ++b)
        (*b)->~Unit();      
}
