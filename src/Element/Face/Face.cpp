#include "Face.h"

Face::Face(){};

Face::~Face(){};

bool Face::operator==(const Face& face_)
{
    bool output = std::is_permutation(points.begin(), points.end(), face_.points.begin());
    output = output && !std::equal(points.begin(), points.end(), face_.points.begin());

    return output;
}