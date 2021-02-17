#include "Line.h"

Line::Line(std::vector<int> points_, std::vector<int> tags_) : Element(points_, tags_)
{
    type_ = "line";
}

Line::~Line(){};
