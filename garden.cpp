// Copyright 2013, Samuel Pauls

#include <cstdlib>
#include <cmath>
#include "garden.h"

Garden::Garden() throw()
{
    static const int FLOWER_COUNT = 3;
    for (int i = 0; i < FLOWER_COUNT; ++i)
    {
        float x = (std::rand() % 100) / 99.0F;
        float y = (std::rand() % 100) / 99.0F;
        roses.push_back (new Rose (x, y));
    }
}

Garden::~Garden() throw()
{
    for (Roses::iterator i = roses.begin(); i != roses.end(); ++i)
    {
        delete *i;
        *i = NULL;
    }
}

void Garden::draw() const throw()
{
    for (Roses::const_iterator i = roses.begin(); i != roses.end(); ++i)
    {
        (*i)->draw();
    }
}
