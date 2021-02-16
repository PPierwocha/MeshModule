// #pragma once
#include "Element.h"


class Triangle : public Element
{
    public:
    Triangle(std::vector<int> points, std::vector<int> tags);
    ~Triangle();

    protected:
    void initFaces();
};