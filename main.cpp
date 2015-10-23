#include <iostream>
#include "display.h"

#define DISPLAY_WIDTH 1080
#define DISPLAY_HEIGHT 900

using namespace std;

int main(int argc, char** argv)
{

    SDL_Init(SDL_INIT_EVERYTHING);
    glutInit(&argc,argv);

    Display display(DISPLAY_WIDTH,DISPLAY_HEIGHT,"JAMPA BUS RACING");

    while(!display.isClosed())
    {
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        display.SwapBuffers();
    }

    SDL_Quit();
    return 0;
}
