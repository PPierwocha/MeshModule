#pragma once
#include "Element.h"


class Line : public Element
{
    public:

        Line(std::vector<int> points, std::vector<int> tags);
        ~Line();
};