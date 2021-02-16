// #pragma once
#include "Triangle.h"


Triangle::Triangle(std::vector<int> points, std::vector<int> tags):Element(points, tags)
{
    type_ = "triangle";
    neighbours_.resize(3);
    neighbours_ = {-1, -1, -1};
    initFaces();
}

Triangle::~Triangle(){};

void Triangle::initFaces()
{
    if (points_.size() == 3)
    {
        faces_.resize(3);
        faces_[0].points = {points_[0], points_[1]};
        faces_[1].points = {points_[1], points_[2]};
        faces_[2].points = {points_[2], points_[0]};
    }
    else
    {
        std::cout << "Faces were not initialized" << std::endl;
    }
    
}