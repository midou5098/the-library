#include "headers.h"


int main(void){
    SDLinit sdl("fuckass library",1280,720);


    bool running = true;
    while(running){
        if(sdl.handel_event()==false){
            running=false;
        };
        sdl.clear();
        sdl.present(); 
    }
    return 0;
}

