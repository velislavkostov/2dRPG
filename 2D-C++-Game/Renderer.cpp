#include "Renderer.hpp"

Renderer::Renderer(int width, int height) : _window{nullptr}, _renderer{nullptr}, _WIDTH{width}, _HEIGHT{height}, _render_duration{0}{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_ShowCursor(0);
    SDL_CreateWindowAndRenderer(_WIDTH, _HEIGHT, SDL_WINDOW_BORDERLESS | SDL_RENDERER_ACCELERATED, &_window, &_renderer);
}

void Renderer::Render(){
    Uint32 start = SDL_GetTicks();
    SDL_RenderPresent(_renderer);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    _render_duration = (SDL_GetTicks() - start);
}

void Renderer::Line(Point p, Point p2, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa){
    aalineRGBA(_renderer, p.x(), p.y(), p2.x(), p2.y(), rr, gg, bb, aa);
}

void Renderer::ThickLine(Point p, Point p2, int width, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa){
    thickLineRGBA(_renderer, p.x(), p.y(), p2.x(), p2.y(), width, rr, gg, bb, aa);
}

void Renderer::Rectangle(Point p, Size s, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa){
    rectangleRGBA(_renderer, p.x(), p.y(), p.x() + s.w(), p.y() + s.h(), rr, gg, bb, aa);
}

void Renderer::RoundedRectangle(Point p, Size s, int radius, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa){
    roundedRectangleRGBA(_renderer, p.x(), p.y(), p.x() + s.w(), p.y() + s.h(), radius, rr, gg, bb, aa);
}   

void Renderer::RoundedBox(Point p, Size s, int radius, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa){
    roundedBoxRGBA(_renderer, p.x(), p.y(), p.x() + s.w(), p.y() + s.h(), radius, rr, gg, bb, aa);
}

void Renderer::Circle(Point p0, int radius, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa){
    aacircleRGBA(_renderer, p0.x(), p0.y(), radius, rr, gg, bb, aa);
}

void Renderer::FilledCircle(Point p0, int radius, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa){
    filledCircleRGBA(_renderer, p0.x(), p0.y(), radius, rr, gg, bb, aa);
}

void Renderer::String(Point p, string s, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa){
    stringRGBA(_renderer, p.x(), p.y(), s.c_str(), rr, gg, bb, aa);
}

SDL_Texture* Renderer::CreateTexture(string name){
    SDL_Surface* surface = IMG_Load(name.c_str());
    if(!surface){
        return (SDL_Texture*)nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FreeSurface(surface);
    if(!texture){
        return (SDL_Texture*)nullptr;
    }
    return texture;
}

void Renderer::DrawTexture(SDL_Texture* texture, Point p, Size s){
    if(!texture){
        return;
    }
    SDL_Rect rect;
    rect.x = p.x();
    rect.y = p.y();
    rect.w = s.w();
    rect.h = s.h();
    SDL_RenderCopy(_renderer, texture, nullptr, &rect); 
}

