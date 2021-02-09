// #pragma once
#ifndef ELEMENT_H
#define ELEMENT_H
#include <vector>
#include <string>





class Element
{
    protected:
    int element_ind_;
    std::vector<int> points_;
    std::vector<int> faces_;
    std::vector<int> neighbours_;
    std::vector<int> tags_;
    std::string type_;


    public:

    Element();
    ~Element();

    

};


#endif