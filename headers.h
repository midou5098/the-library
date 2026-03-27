#ifndef HEADERS_H
#define HEADERS_H

#include <vector>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>

class book{
    private:
        int id;
        std::string name;
        std::string author;
        int pages;
        bool isbrwd;
    public:
        book(int id=-1,const std::string&name="",const std::string&author="",int pages=-1,bool isbrwd=false  );
}
class author{
    private:
        int id;
        std::string name;
        int buknb;
        int age;
        std::string skin;
    public:
        author(int id=-1,const std::string&name="",int buknb=-1,int age=-1,const std::string&skin=""  );
}
class staff{
    private:
        int id;
        std::string name;
        int rank;
        int age;
        int salary;
    public:
        staff(int id=-1,const std::string&name="",int rank=-1,int age=-1,int salary=-1  );
}
class SDLinit{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        void SDLinit(std::string &title,int w,int h)
        void ~SDLinit(void);
        SDL_Renderer* SDLgetrender(void){return renderer;}
        void clear();
        void present();
        bool handel_event();
}
SDLinit::SDLinit(std::string &title,int w,int h):window(nullptr),renderer(nullptr){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window=SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);         
}
SDLinit::~SDLinit(void){
    if(window){
        SDL_DestroyWindow(window);}
    if(renderer){
        SDL_DestroyRenderer(renderer);
    }
}
void SDL::clear(void){
    if(renderer){
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
    }
}
void SDL::present(void){
    if(renderer){
        SDL_RenderPresent(renderer);
    }
}
bool SDL::handel_event(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type==SDL_QUIT){
            return false
        }
    }
    SDL_RenderPresent(renderer);
}
#endif
