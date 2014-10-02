#ifndef _RENDERER_
#define _RENDERER_

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include "Point.hpp"
#include "Size.hpp"
#include <string>
using std::string;

/* 
    Make Renderer completely functional class covering most of SDL_gfxPrimitives draw routines 
    for rich visual content INGAME
*/  

class Renderer{
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    const int _WIDTH;
    const int _HEIGHT;
    int _render_duration;
public:
    Renderer(int width, int height);
    void Render();
    //Primitives
    void Line(Point p, Point p2, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa);
    void ThickLine(Point p, Point p2, int width, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa);
    void Rectangle(Point p, Size s, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa);
    void RoundedRectangle(Point p, Size s, int radius, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa);
    void RoundedBox(Point p, Size s, int radius, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa);
    void Circle(Point p, int radius, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa);
    void FilledCircle(Point p, int radius, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa);
    void String(Point p, string s, Uint8 rr, Uint8 gg, Uint8 bb, Uint8 aa);
    //Complex resources
    SDL_Texture* CreateTexture(string name);
    void DrawTexture(SDL_Texture* texture, Point p, Size s);
    int RenderDuration(){return _render_duration;}
    int GetWidth(){return _WIDTH;}
    int GetHeight(){return _HEIGHT;}
    ~Renderer(){SDL_DestroyWindow(_window); SDL_DestroyRenderer(_renderer);}
};

#endif // _RENDERER_
