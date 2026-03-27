#include "headers.h"


int main(void){
    SDLinit sdl("fuckass library",1280,720);
    uinter uic(sdl);
    SDL_Event event;
    int mode=0;
    bool running = true;
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                running=false;
            };
            uic.handel(event,mode);
        
        
        
        }
        sdl.clear();
        uic.layout(mode);
        sdl.present(); 
    }
    return 0;
}

//mode :
// 0 main menu
// 10 book add , 11 book delete,12 book search,13 book modify
// 20 author add , 21 author delete,12 author search,13 author modify
// 30 staff add , 21 staff delete,12 staff search,13 staff modify
