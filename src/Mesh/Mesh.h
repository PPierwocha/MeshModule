#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <map>
#include "..\Element\Element.h"
#include "..\Element\Line.h"
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
    int nodes_number, int_elements_number, bnd_elements_number;
    std::vector<Point<double>> points_cords;
    std::vector<Element> interior_elements, boundary_elements;

    void readPointsFromLine(std::string line_);

    void readElementFromLine(std::string line_);

    void resizeElementNodesVar(std::vector<int> * elm_nodes_, int elm_type_int_);

    public:

    Mesh(){};
    ~Mesh(){};

    void readGmshFile(std::string file_name_);
    
    void printMeshInfo();

};
