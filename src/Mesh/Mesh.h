#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <regex>
// #include <Element.h>
// #include <Triangle.h>
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
    int node_number_;
    std::vector<Point<double>> points_cords_;
    // std::vector<Element<T>> elements_;

    void readPointsFromLine(std::string line_);

    public:

    Mesh(){};
    ~Mesh(){};

    void readGmshFile(std::string file_name);
    


};
