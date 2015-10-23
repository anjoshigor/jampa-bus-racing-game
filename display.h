#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <SDL/SDL.h>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>

class Display
{
    public:
        Display(int width, int height, const std::string& title);
        virtual ~Display();
        void SwapBuffers();
        bool isClosed();
    protected:
    private:
        Display(const Display& other);
        Display& operator=(const Display& other);

        SDL_Window* m_window;
        SDL_GLContext m_glContext;
        bool m_isClosed = false;
};

#endif // DISPLAY_H
