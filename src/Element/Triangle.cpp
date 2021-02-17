// #pragma once
#include "Triangle.h"


Triangle::Triangle(std::vector<int> points, std::vector<int> tags):Element(points, tags)
{
    type_ = "triangle";
    this -> initFaces();
}

Triangle::~Triangle(){};

void Triangle::initFaces()
{
    if ((*this).points_.size() == 3)
    {
        this -> faces_.resize(3);
        (*this).faces_[0].points = {this->points_[0], this->points_[1]};
        (*this).faces_[1].points = {this->points_[1], this->points_[2]};
        (*this).faces_[2].points = {this->points_[2], this->points_[0]};
    }
    else
    {
        std::cout << "Faces were not initialized" << std::endl;
    }
    
}