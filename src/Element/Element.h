#pragma once
// #ifndef ELEMENT_H
// #define ELEMENT_H
#include <vector>
#include <string>
#include <iostream>


struct Face
{
    std::vector<int> points;
    std::vector<double> versor;
    double surface;    
};



class Element
{
    public:
    int element_ind_;
    std::vector<int> points_;
    std::vector<Face> faces_;
    std::vector<int> neighbours_;
    std::vector<int> tags_;
    std::string type_;


    

    Element(std::vector<int> points, std::vector<int> tags);
    ~Element();

    

};


// #endif