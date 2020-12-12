#pragma once
#include <Element.h>

template <typename T>
class Quad : public Element<T>
{
    public:
    Quad()
    {
        type_ = 'quad';
    }
};