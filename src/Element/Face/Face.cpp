#include "Face.h"

Face::Face(){};

Face::~Face(){};

bool Face::operator==(const Face& face_)
{
    // bool output = std::is_permutation((*this).points.begin(), (*this).points.end(), face_.points.begin());
    bool output = (points[0] == face_.points[1]) && (points[1] == face_.points[0]);

    return output;
}