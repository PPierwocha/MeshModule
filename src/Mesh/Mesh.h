#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <map>
#include "..\Element\Element.h"
#include "..\Element\Triangle.h"
// #include <Quad.h>

template <typename T>
struct Point
{
    T x, y, z;
};

// template <typename T>
class Mesh
{   
    private:
    int nodes_number_, elements_number_;
    std::vector<Point<double>> points_cords_;
    std::vector<Element> elements_;

    void readPointsFromLine(std::string line_);

    void readElementFromLine(std::string line_);

    public:

    Mesh(){};
    ~Mesh(){};

    void readGmshFile(std::string file_name);
    


};
