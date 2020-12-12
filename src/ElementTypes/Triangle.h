#pragma once
#include <Element.h>

template <typename T>
class Triangle : public Element<T>
{
    public:
    Triangle()
    {
        type_ = 'triangle';
    }
};