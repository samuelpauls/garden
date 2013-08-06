// Copyright 2013, Samuel Pauls

#include <cmath>
#include <GL/gl.h>
#include "rose.h"

void Rose::draw() const throw()
{
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
}
