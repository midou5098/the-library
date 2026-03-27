#ifndef HEADERS_H
#define HEADERS_H

#include <vector>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>













class book{
    private:
        int id;
        std::string name;
        std::string author;
        int pages;
        bool isbrwd;
    public:
        book(int id=-1,const std::string&name="",const std::string&author="",int pages=-1,bool isbrwd=false );
};
class author{
    private:
        int id;
        std::string name;
        int buknb;
        int age;
        std::string skin;
    public:
        author(int id=-1,const std::string&name="",int buknb=-1,int age=-1,const std::string&skin=""  );
};
class staff{
    private:
        int id;
        std::string name;
        int rank;
        int age;
        int salary;
    public:
        staff(int id=-1,const std::string&name="",int rank=-1,int age=-1,int salary=-1  );
};
class SDLinit{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        TTF_Font* font;
    public:
        SDLinit(const std::string &title,int w,int h);
        ~SDLinit();
        SDL_Renderer* SDLgetrender(){return renderer;}
        void clear();
        void present();
        bool handel_event();
        void drawbut(int x,int y,int w,int h,int r,int g,int b,const std::string &text);
};
SDLinit::SDLinit(const std::string &title,int w,int h):window(nullptr),renderer(nullptr){
    SDL_Init(SDL_INIT_VIDEO);
    window=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);         
    TTF_Init();
    font = TTF_OpenFont("font.ttf",20);    
}
SDLinit::~SDLinit(){
    if(window){
        SDL_DestroyWindow(window);}
    if(renderer){
        SDL_DestroyRenderer(renderer);
    }
    TTF_CloseFont(font);
    TTF_Quit();
}
void SDLinit::clear(){
    if(renderer){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderClear(renderer);
    }
}
void SDLinit::present(){
    if(renderer){
        SDL_RenderPresent(renderer);
    }
}
bool SDLinit::handel_event(){
    SDL_Event event;
    std::string s;
    while(SDL_PollEvent(&event)){
        if(event.type==SDL_QUIT){
            return false;
        else if(event.type==SDL_KEYDOWN){
            if(event.key.keysym.sym=SDL_ENTER ){
                if(len(s)<4){
                    SDL_Rect rect={500,680,200,40};
                    SDL_Surface* surf=TTF_RenderText_Solid(font," name gotta be 4 letters long twin",white);
                    SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
                    SDL_RenderCopy(renderer,tex,NULL,&rect2);

                }

            }
        }
        }
    }
    return true;}
void SDLinit::drawbut(int x,int y,int w,int h,int r,int g,int b,const std::string &text){
    
    SDL_SetRenderDrawColor(renderer,r,g,b,255);
    SDL_Rect rect={x,y,w,h};
    SDL_RenderFillRect(renderer,&rect);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderDrawRect(renderer,&rect);
    SDL_Color white = {120,120,120,255};
    SDL_Surface* surf=TTF_RenderText_Solid(font,text.c_str(),white);
    SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_Rect rect2={x+27,y+10,w-50,h-30};
    SDL_RenderCopy(renderer,tex,NULL,&rect2);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
    
}
void SDLinit::drawtextarea(int x,int y,int w,int h,int r,int g,int b){
    SDL_SetRenderDrawColor(renderer,r,g,b,255);
    SDL_Rect rect={x,y,w,h};
    SDL_RenderFillRect(renderer,&rect);
}

class uinter{
    private:
        SDLinit& sdl;
    public:
        void layout();
        uinter(SDLinit& s):sdl(s){}
};
void uinter::layout(int mode){
    if(mode==0){
        sdl.drawbut(50,50,200,100,150,150,150,"books");
        sdl.drawbut(50,240,200,100,80,80,80,"add");
        sdl.drawbut(50,360,200,100,80,80,80,"delete");
        sdl.drawbut(50,480,200,100,80,80,80,"search");
        sdl.drawbut(50,600,200,100,80,80,80,"modify");
        
        sdl.drawbut(550,50,200,100,150,150,150,"authors");
        sdl.drawbut(550,240,200,100,80,80,80,"add");
        sdl.drawbut(550,360,200,100,80,80,80,"delete");
        sdl.drawbut(550,480,200,100,80,80,80,"search");
        sdl.drawbut(550,600,200,100,80,80,80,"modify");
        
        sdl.drawbut(1000,50,200,100,150,150,150,"STAFF");
        sdl.drawbut(1000,240,200,100,80,80,80,"add");
        sdl.drawbut(1000,360,200,100,80,80,80,"delete");
        sdl.drawbut(1000,480,200,100,80,80,80,"search");
        sdl.drawbut(1000,600,200,100,80,80,80,"modify");
        
    }else if mode==10){

    }

}






































































































#endif
