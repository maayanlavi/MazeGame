#pragma once
#include <string>

class Observable;
class Observer
{
public:
    virtual void update(Observable& o) = 0;
};