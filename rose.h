// Copyright 2013, Samuel Pauls

#ifndef ROSE_H
#define ROSE_H

class Rose
{
private:
    float x;
    float y;

public:
    Rose(float x, float y) throw();

    void draw() const throw();
};

#endif // ROSE_H
