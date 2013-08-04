// Copyright 2013, Samuel Pauls

#include <cstdlib>
#include <cassert>
#include <string>
#include <GL/gl.h>
#include <SFML/Window.hpp>

int main (int argc, char *argv[])
{
    static const unsigned int WIDTH = 800;
    static const unsigned int HEIGHT = 600;
    static const unsigned int BITS_PER_PIXEL = 32;
    sf::VideoMode video_mode (WIDTH, HEIGHT, BITS_PER_PIXEL);
    static const std::string TITLE ("Flowers");
    sf::Window window (video_mode, TITLE);

    bool is_running = true;
    while (is_running)
    {
        sf::Event event;
        while (window.pollEvent (event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                is_running = false;
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::LostFocus:
                break;
            default:
                assert ("Unknown window event type!");
            }
        }

        glClear (GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        glBegin (GL_LINES);
            glVertex2f(0.0F, 0.0F);
            glVertex2f(1.0F, 1.0F);
        glEnd();

        window.display();
    }

    return EXIT_SUCCESS;
}
