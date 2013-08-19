// Copyright 2013, Samuel Pauls

#ifndef GARDEN_H
#define GARDEN_H

#include <vector>
#include "rose.h"

class Garden
{
private:
    typedef std::vector<Rose*> Roses;
    Roses roses;

public:
    Garden() throw();
    ~Garden() throw();

    void draw() const throw();
};

#endif // GARDEN_H
