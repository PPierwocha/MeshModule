#pragma once
#include <vector>
#include <algorithm>


class Face
{
    public:
    std::vector<int> points;
    std::vector<double> versor;
    double surface;

    Face();
    ~Face();

    bool operator==(const Face& face_);
    bool operator|=(const Face& face_);
};

