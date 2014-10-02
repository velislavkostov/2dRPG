#include <iostream>

#include "Game.hpp"

using namespace std;

int main(int argc, char* argv[]){
    Game game;
    SDL_Event event;
    while(game.Running()){
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.scancode){
                case SDL_SCANCODE_ESCAPE:
                    game.Quit();
                    break; 
                default:
                    break;
                }   
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                if(event.button.button == SDL_BUTTON_LEFT){
                    game.CreatePlayer("Vili" + to_string(rand() % 100), Point(event.button.x, event.button.y));
                }
                else{
                    //game.RemovePlayer("Vili");
                }
            }
        }
        game.Update();
    }
    SDL_Quit();
    return 0;
}
