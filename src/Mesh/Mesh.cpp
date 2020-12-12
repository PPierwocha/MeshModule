#pragma once
#include "Mesh.h"


// template <typename T>
void Mesh::readGmshFile(std::string file_name)
{
    std::ifstream gmsh_file(file_name);
    std::string line;

    std::string points_start = "$Nodes";
    std::string points_end = "$EndNodes";
    std::regex node_number_regex("[0-9]+");
    std::smatch match_node_number;

    
    bool enable_points_reading = false;
    int iter = 0;

    if (gmsh_file.is_open())
    {
        while (getline(gmsh_file, line))
        {
            if (enable_points_reading)
            {
                this->readPointsFromLine(line);
                iter++;
            }
            if (line.find(points_start) != line.npos)
            {
                enable_points_reading = true;
                getline(gmsh_file, line);
                std::regex_search(line, match_node_number, node_number_regex);
                std::stringstream x_stream(match_node_number[0]);
                x_stream >> node_number_;
                points_cords_.resize(node_number_);
            }
            if (line.find(points_end) != line.npos)
                enable_points_reading = false;

            // if(iter > 5)
            //     break;
            
        }
        gmsh_file.close();
    }
}


// template <typename T>
void Mesh::readPointsFromLine(std::string line_)
{
    std::string line_init = line_;
    int node_ind = 0;
    int coordinate_ind = 1;
    long double node_coord = 0;
    Point<double> tmp_point;

    std::regex node_ind_regex("[0-9]+");
    // std::regex coordinate_regex(R"(^([-]?(?:[[:d:]]+\.?|[[:d:]]*\.[[:d:]]+))(?:[Ee][+-]?[[:d:]]+)?$)");
    std::regex coordinate_regex("( )[-]*[0-9]+[\\.]*[0-9]*");
    
    std::smatch match_node, match_cordinates;
    // std::

    std::regex_search(line_, match_node, node_ind_regex);
    

    std::cout << "String that matches the pattern:" << std::endl;
    for (auto x : match_node) 
    {
        std::stringstream x_stream(x);
        x_stream >> node_ind;
        std::cout << node_ind << " ";

        if (node_ind > points_cords_.size())
            std::cout << "WARNING !! Mesh::readPointsFromLine : node_ind is out of range !" << std::endl;
    }
    
    while (std::regex_search(line_, match_cordinates, coordinate_regex))
    {
        std::stringstream x_stream(match_cordinates[0]);
        x_stream >> node_coord;
        std::cout << node_coord << " ";
        line_ = match_cordinates.suffix();
        
        if (coordinate_ind == 1)
            tmp_point.x = node_coord;
        else if (coordinate_ind == 2)
            tmp_point.y = node_coord;
        else if (coordinate_ind == 3)
            tmp_point.z = node_coord;
        else
            std::cout << "WARNING !! Mesh::readPointsFromLine : coordinate_ind is out of range !" << std::endl;

        coordinate_ind++;
            
    }

    points_cords_[node_ind - 1] = tmp_point;
    
    std::cout << std::endl;
    std::cout << line_init << std::endl;
    std::cout << "***********************" << std::endl;
    
}