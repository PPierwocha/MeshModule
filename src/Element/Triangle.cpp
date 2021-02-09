// #pragma once
#include "Triangle.h"


Triangle::Triangle(std::vector<int> points, std::vector<int> tags):Element(points, tags)
{
    type_ = "triangle";
}

Triangle::~Triangle(){};