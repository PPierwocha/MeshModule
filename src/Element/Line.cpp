#include "Line.h"

Line::Line(std::vector<int> points_, std::vector<int> tags_) : Element(points_, tags_)
{
    type_ = "line";
    faces_.resize(1);
    faces_[0].points = {points_[0], points_[1]};
}

Line::~Line(){};
