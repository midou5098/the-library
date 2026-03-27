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
        SDL_Renderer* getrender(){return renderer;}
        TTF_Font* getFont() { return font; }
        void clear();
        void present();
        bool handel_event();
        void drawtextarea(int x,int y,int w,int h,int r,int g,int b);
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
        }
        return true;
    }
    return false;
    }
void SDLinit::drawbut(int x,int y,int w,int h,int r,int g,int b,const std::string &text){
    
    SDL_SetRenderDrawColor(renderer,r,g,b,255);
    SDL_Rect rect6={x,y,w,h};
    SDL_RenderFillRect(renderer,&rect6);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderDrawRect(renderer,&rect6);
    SDL_Color white = {120,120,120,255};
    SDL_Surface* surf=TTF_RenderText_Solid(font,text.c_str(),white);
    SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_Rect rect5={x+27,y+10,w-50,h-30};
    SDL_RenderCopy(renderer,tex,NULL,&rect5);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
    
}
void SDLinit::drawtextarea(int x,int y,int w,int h,int r,int g,int b){
    SDL_SetRenderDrawColor(renderer,r,g,b,255);
    SDL_Rect rect4={x,y,w,h};
    SDL_RenderDrawRect(renderer,&rect4);
}

class uinter{
    private:
        SDLinit& sdl;
        std::string s1="",s2="",s3="";
        int focused=-1;

    public:
        void layout(int mode);
        void handel(SDL_Event& event,int& mode);
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
        
    }else if (mode==10){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," book name  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);
        
        SDL_Surface* surf2=TTF_RenderText_Solid(font," book author  : ",black);
        SDL_Texture* tex2=SDL_CreateTextureFromSurface(renderer,surf2);
        int tw2 = surf2->w;
        int th2 = surf2->h;
        SDL_Rect rect2={350,300,tw2,th2};
        SDL_RenderCopy(renderer,tex2,NULL,&rect2);
        SDL_FreeSurface(surf2);
        SDL_DestroyTexture(tex2);
        
        sdl.drawtextarea(570,290,200,40,0,0,0);

        
        SDL_Surface* surf3=TTF_RenderText_Solid(font," book pages  : ",black);
        SDL_Texture* tex3=SDL_CreateTextureFromSurface(renderer,surf3);
        int tw3 = surf3->w;
        int th3 = surf3->h;
        SDL_Rect rect3={350,400,tw3,th3};
        SDL_RenderCopy(renderer,tex3,NULL,&rect3);
        SDL_FreeSurface(surf3);
        SDL_DestroyTexture(tex3);
        sdl.drawtextarea(570,390,200,40,0,0,0);

        
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
            }

        if(!s2.empty()){
            SDL_Surface* surf22=TTF_RenderText_Solid(font,s2.c_str(),black);
            SDL_Texture* tex22=SDL_CreateTextureFromSurface(renderer,surf22);
            int tw22 = surf22->w;
            int th22 = surf22->h;
            SDL_Rect rect22={575,300,tw22,th22};
            SDL_RenderCopy(renderer,tex22,NULL,&rect22);
            SDL_FreeSurface(surf22);
            SDL_DestroyTexture(tex22);
        }

        if(!s3.empty()){
            SDL_Surface* surf33=TTF_RenderText_Solid(font,s3.c_str(),black);
            SDL_Texture* tex33=SDL_CreateTextureFromSurface(renderer,surf33);
            int tw33 = surf33->w;
            int th33 = surf33->h;
            SDL_Rect rect33={575,400,tw33,th33};
            SDL_RenderCopy(renderer,tex33,NULL,&rect33);
            SDL_FreeSurface(surf33);
            SDL_DestroyTexture(tex33);
        }
    }else if (mode==11){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," book name  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);    
    
    
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
        }
    }else if (mode==12){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," book name  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);    
    
    
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
        }
    }else if (mode==13){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," book name  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);    
    
    
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
        }
    }






    else if (mode==20){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," author name  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);
        
        SDL_Surface* surf2=TTF_RenderText_Solid(font," author age  : ",black);
        SDL_Texture* tex2=SDL_CreateTextureFromSurface(renderer,surf2);
        int tw2 = surf2->w;
        int th2 = surf2->h;
        SDL_Rect rect2={350,300,tw2,th2};
        SDL_RenderCopy(renderer,tex2,NULL,&rect2);
        SDL_FreeSurface(surf2);
        SDL_DestroyTexture(tex2);
        
        sdl.drawtextarea(570,290,200,40,0,0,0);

        
        SDL_Surface* surf3=TTF_RenderText_Solid(font," author skin   : ",black);
        SDL_Texture* tex3=SDL_CreateTextureFromSurface(renderer,surf3);
        int tw3 = surf3->w;
        int th3 = surf3->h;
        SDL_Rect rect3={350,400,tw3,th3};
        SDL_RenderCopy(renderer,tex3,NULL,&rect3);
        SDL_FreeSurface(surf3);
        SDL_DestroyTexture(tex3);
        sdl.drawtextarea(570,390,200,40,0,0,0);

        
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
            }

        if(!s2.empty()){
            SDL_Surface* surf22=TTF_RenderText_Solid(font,s2.c_str(),black);
            SDL_Texture* tex22=SDL_CreateTextureFromSurface(renderer,surf22);
            int tw22 = surf22->w;
            int th22 = surf22->h;
            SDL_Rect rect22={575,300,tw22,th22};
            SDL_RenderCopy(renderer,tex22,NULL,&rect22);
            SDL_FreeSurface(surf22);
            SDL_DestroyTexture(tex22);
        }

        if(!s3.empty()){
            SDL_Surface* surf33=TTF_RenderText_Solid(font,s3.c_str(),black);
            SDL_Texture* tex33=SDL_CreateTextureFromSurface(renderer,surf33);
            int tw33 = surf33->w;
            int th33 = surf33->h;
            SDL_Rect rect33={575,400,tw33,th33};
            SDL_RenderCopy(renderer,tex33,NULL,&rect33);
            SDL_FreeSurface(surf33);
            SDL_DestroyTexture(tex33);
        }
    }else if (mode==21){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," author id  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);    
    
    
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
        }
    }else if (mode==22){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," author id  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);    
    
    
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
        }
    }else if (mode==23){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," author id  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);    
    
    
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
        }
    }else if (mode==30){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," staff name  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);
        
        SDL_Surface* surf2=TTF_RenderText_Solid(font," staff age  : ",black);
        SDL_Texture* tex2=SDL_CreateTextureFromSurface(renderer,surf2);
        int tw2 = surf2->w;
        int th2 = surf2->h;
        SDL_Rect rect2={350,300,tw2,th2};
        SDL_RenderCopy(renderer,tex2,NULL,&rect2);
        SDL_FreeSurface(surf2);
        SDL_DestroyTexture(tex2);
        
        sdl.drawtextarea(570,290,200,40,0,0,0);

        
        SDL_Surface* surf3=TTF_RenderText_Solid(font," staff position  : ",black);
        SDL_Texture* tex3=SDL_CreateTextureFromSurface(renderer,surf3);
        int tw3 = surf3->w;
        int th3 = surf3->h;
        SDL_Rect rect3={350,400,tw3,th3};
        SDL_RenderCopy(renderer,tex3,NULL,&rect3);
        SDL_FreeSurface(surf3);
        SDL_DestroyTexture(tex3);
        sdl.drawtextarea(570,390,200,40,0,0,0);

        
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
            }

        if(!s2.empty()){
            SDL_Surface* surf22=TTF_RenderText_Solid(font,s2.c_str(),black);
            SDL_Texture* tex22=SDL_CreateTextureFromSurface(renderer,surf22);
            int tw22 = surf22->w;
            int th22 = surf22->h;
            SDL_Rect rect22={575,300,tw22,th22};
            SDL_RenderCopy(renderer,tex22,NULL,&rect22);
            SDL_FreeSurface(surf22);
            SDL_DestroyTexture(tex22);
        }

        if(!s3.empty()){
            SDL_Surface* surf33=TTF_RenderText_Solid(font,s3.c_str(),black);
            SDL_Texture* tex33=SDL_CreateTextureFromSurface(renderer,surf33);
            int tw33 = surf33->w;
            int th33 = surf33->h;
            SDL_Rect rect33={575,400,tw33,th33};
            SDL_RenderCopy(renderer,tex33,NULL,&rect33);
            SDL_FreeSurface(surf33);
            SDL_DestroyTexture(tex33);
        }
    }else if (mode==31){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," staff name  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);    
    
    
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
        }
    }else if (mode==32){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," staff name  : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);    
    
    
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
        }
    }else if (mode==33){
        TTF_Font *font=sdl.getFont();
        SDL_Renderer* renderer=sdl.getrender();
        SDL_Color black = {0,0,0,255};
        SDL_Surface* surf=TTF_RenderText_Solid(font," staff name : ",black);
        int tw = surf->w;
        int th = surf->h;
        SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
        SDL_Rect rect={350,200,tw,th};
        SDL_RenderCopy(renderer,tex,NULL,&rect);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
        sdl.drawtextarea(570,190,200,40,0,0,0);    
    
    
        if(!s1.empty()){
            SDL_Surface* surf11=TTF_RenderText_Solid(font,s1.c_str(),black);
            SDL_Texture* tex11=SDL_CreateTextureFromSurface(renderer,surf11);
            int tw11 = surf11->w;
            int th11 = surf11->h;
            SDL_Rect rect11={575,200,tw11,th11};
            SDL_RenderCopy(renderer,tex11,NULL,&rect11);
            SDL_FreeSurface(surf11);
            SDL_DestroyTexture(tex11);
        }
    }


































































































































    
}
void uinter::handel(SDL_Event& event,int& mode){
    if (mode==0){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            int mouse_x=event.button.x;
            int mouse_y=event.button.y;
            if (50<mouse_x && mouse_x<250){
                    if(240<mouse_y && mouse_y<340){
                        mode=10;
                    }else if(360<mouse_y && mouse_y<480){
                        mode=11;
                    }else if(480<mouse_y && mouse_y<580){
                        mode=12;
                    }else if(600<mouse_y && mouse_y<700){
                        mode=13;
                    }
            }else if (550<mouse_x && mouse_x<750){
                    if(240<mouse_y && mouse_y<340){
                        mode=20;
                    }else if(360<mouse_y && mouse_y<480){
                        mode=21;
                    }else if(480<mouse_y && mouse_y<580){
                        mode=22;
                    }else if(600<mouse_y && mouse_y<700){
                        mode=23;
                    }
            }else if (1000<mouse_x && mouse_x<1200){
                    if(240<mouse_y && mouse_y<340){
                        mode=30;
                    }else if(360<mouse_y && mouse_y<480){
                        mode=31;
                    }else if(480<mouse_y && mouse_y<580){
                        mode=32;
                    }else if(600<mouse_y && mouse_y<700){
                        mode=33;
                    }
            }
        }
    }else if(mode==10){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }else if(300<event.button.y && event.button.y<340){
                    focused=2;
                }else if(400<event.button.y && event.button.y<440){
                    focused=3;
            }
        }}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                    else if (focused==2 && !s2.empty()) s2.pop_back();
                    else if(focused==3 && !s3.empty()) s3.pop_back();
                }
                else if(key==SDLK_RETURN) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;
}
                if (key>=32 && key<=126) {  
                    char c=(char)key;
                    bool shift=(event.key.keysym.mod & KMOD_SHIFT);
                    if (shift && c>='a' && c<= 'z') {
                        c=toupper(c);
                    }
                    if(focused==1 && s1.length()<20) s1+=c;

                else if(focused==2 && s2.length()<20) s2+=c;
                else if(focused==3 && s3.length()<20) s3+=c;}
                
                        }
                
        }if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    return;}
        }
          
        



    }else if (mode == 11){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    
                    focused=-1;
                    mode=0;
                    s1.clear();}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    return;}
        }
          }
    else if (mode == 12){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    return;}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    return;}}
    }else if (mode == 13){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    return;}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    return;}}
    }else if(mode==20){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }else if(300<event.button.y && event.button.y<340){
                    focused=2;
                }else if(400<event.button.y && event.button.y<440){
                    focused=3;
            }
        }}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                    else if (focused==2 && !s2.empty()) s2.pop_back();
                    else if(focused==3 && !s3.empty()) s3.pop_back();
                }
                else if(key==SDLK_RETURN) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;
}
                if (key>=32 && key<=126) {  
                    char c=(char)key;
                    bool shift=(event.key.keysym.mod & KMOD_SHIFT);
                    if (shift && c>='a' && c<= 'z') {
                        c=toupper(c);
                    }
                    if(focused==1 && s1.length()<20) s1+=c;

                else if(focused==2 && s2.length()<20) s2+=c;
                else if(focused==3 && s3.length()<20) s3+=c;}
                
                        }
                
        }if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}
        }
          
        



    }else if (mode == 21){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    
                    focused=-1;
                    mode=0;
                    s1.clear();}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}
        }
          }
    else if (mode == 22){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    return;}}
    }else if (mode == 23){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}}
    }else if(mode==10){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }else if(300<event.button.y && event.button.y<340){
                    focused=2;
                }else if(400<event.button.y && event.button.y<440){
                    focused=3;
            }
        }}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                    else if (focused==2 && !s2.empty()) s2.pop_back();
                    else if(focused==3 && !s3.empty()) s3.pop_back();
                }
                else if(key==SDLK_RETURN) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;
}
                if (key>=32 && key<=126) {  
                    char c=(char)key;
                    bool shift=(event.key.keysym.mod & KMOD_SHIFT);
                    if (shift && c>='a' && c<= 'z') {
                        c=toupper(c);
                    }
                    if(focused==1 && s1.length()<20) s1+=c;

                else if(focused==2 && s2.length()<20) s2+=c;
                else if(focused==3 && s3.length()<20) s3+=c;}
                
                        }
                
        }if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    return;}
        }
          
        



    }else if (mode == 11){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    
                    focused=-1;
                    mode=0;
                    s1.clear();}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    return;}
        }
          }
    else if (mode == 12){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    return;}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    return;}}
    }else if (mode == 13){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    return;}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    return;}}
    }else if(mode==30){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }else if(300<event.button.y && event.button.y<340){
                    focused=2;
                }else if(400<event.button.y && event.button.y<440){
                    focused=3;
            }
        }}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                    else if (focused==2 && !s2.empty()) s2.pop_back();
                    else if(focused==3 && !s3.empty()) s3.pop_back();
                }
                else if(key==SDLK_RETURN) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;
}
                if (key>=32 && key<=126) {  
                    char c=(char)key;
                    bool shift=(event.key.keysym.mod & KMOD_SHIFT);
                    if (shift && c>='a' && c<= 'z') {
                        c=toupper(c);
                    }
                    if(focused==1 && s1.length()<20) s1+=c;

                else if(focused==2 && s2.length()<20) s2+=c;
                else if(focused==3 && s3.length()<20) s3+=c;}
                
                        }
                
        }if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}
        }
          
        



    }else if (mode == 31){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}
        }
          }
    else if (mode == 32){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    return;}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}}
    }else if (mode == 33){
        if (event.type==SDL_MOUSEBUTTONDOWN){
            if (570<event.button.x && event.button.x<770){
                if(200<event.button.y && event.button.y<240){
                    focused=1;
                }}}
        if (focused!=-1){
            if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                char c=(char)key;
                if (key == SDLK_BACKSPACE) {
                    if (focused==1 && !s1.empty())s1.pop_back();
                }
                else if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}

                if(focused==1 && s1.length()<20) s1+=c;}}
        if (event.type==SDL_KEYDOWN){
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN || key==SDLK_ESCAPE) {
                    std::cout<<"Saving: "<<s1<<" by "<<s2<<", "<<s3<<" pages"<<std::endl;
                    focused=-1;
                    mode=0;
                    s1.clear();
                    s2.clear();
                    s3.clear();
                    return;}}
    }
                
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            }
                


































































































#endif
