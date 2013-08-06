// Copyright 2013, Samuel Pauls

#include <cstdlib>
#include <string>
#include <GL/gl.h>
#include <SFML/Window.hpp>
#include "rose.h"

int main (int argc, char *argv[])
{
    static const unsigned int WIDTH = 800;
    static const unsigned int HEIGHT = 600;
    static const unsigned int BITS_PER_PIXEL = 32;
    sf::VideoMode video_mode (WIDTH, HEIGHT, BITS_PER_PIXEL);
    static const std::string TITLE ("Flowers");
    sf::Window window (video_mode, TITLE);

    Rose rose;

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
            }
        }

        glClear (GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        rose.draw();

        window.display();
    }

    return EXIT_SUCCESS;
}
