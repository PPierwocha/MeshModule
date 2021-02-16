#include "Element.h"


Element::Element(std::vector<int> points, std::vector<int> tags)
{
    points_ = points;
    tags_ = tags;
};

Element::~Element(){};


void Element::checkIfNeighbour(std::vector<Face> elm_face_2, int elm_ind)
{
    
    std::vector<int>::iterator neighbour_iter = neighbours_.begin();
    std::vector<Face>::iterator face_1_iter = faces_.begin();
    std::vector<Face>::iterator face_1_iter_end = faces_.end();
    std::vector<Face>::iterator face_2_iter;
    std::vector<Face>::iterator face_2_iter_end = elm_face_2.end();

    bool outer_break = false;
    
    
    for (face_1_iter; face_1_iter != face_1_iter_end; face_1_iter++)
    {

        for (face_2_iter = elm_face_2.begin(); face_2_iter != face_2_iter_end; face_2_iter++)
        {
            if ((*face_1_iter) == (*face_2_iter))
            {
                (*neighbour_iter) = elm_ind;
                outer_break = true;
                std::cout << "Found neighbour !" << (*neighbour_iter) << std::endl;
                // break;
            }
        }

        // if (outer_break)
        //     break;

        neighbour_iter++;
    }

    
}