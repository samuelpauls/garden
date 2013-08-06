// Copyright 2013, Samuel Pauls

#include <cstdlib>
#include <cmath>
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
            }
        }

        glClear (GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        glBegin (GL_LINE_LOOP);

            // Source of equations and more information:
            // https://en.wikipedia.org/wiki/Rose_(mathematics)
            int a = 3;
            float i_max = 0.0F;
            static const float PI = 3.14159F;
            if (a % 2 == 0) // even
            {
                i_max = PI * 2.0F;
            }
            else // odd
            {
                i_max = PI;
            }
            static const float I_STEP = 0.01F;
            for (float i = 0.0F; i < i_max; i += I_STEP)
            {
                float term_one = cos (a * i);
                float x = term_one * sin (i);
                float y = term_one * cos (i);
                glVertex2f (x, y);
            }

        glEnd();

        window.display();
    }

    return EXIT_SUCCESS;
}
