#include "Mesh.h"


// template <typename T>
void Mesh::readGmshFile(std::string file_name_)
{
    std::ifstream gmsh_file(file_name_);
    std::string line;

    //Points
    std::string points_start = "$Nodes";
    std::string points_end = "$EndNodes";
    std::regex node_number_regex("[0-9]+");
    std::smatch match_node_number;

    // Elements
    std::string elements_start = "$Elements";
    std::string elements_end = "$EndElements";
    std::regex elements_number_regex("[0-9]+");
    std::smatch match_elements_number;
    
    bool enable_points_reading = false;
    bool enable_elements_reading = false;
    int iter_points = 0;

    if (gmsh_file.is_open())
    {
        while (getline(gmsh_file, line))
        {
            // Reading Points
            if (enable_points_reading)
            {
                this->readPointsFromLine(line);
                iter_points++;
            }
            if (line.find(points_start) != line.npos)
            {
                enable_points_reading = true;
                getline(gmsh_file, line);
                std::regex_search(line, match_node_number, node_number_regex);
                std::stringstream x_stream(match_node_number[0]);
                x_stream >> nodes_number;
                points_cords.resize(nodes_number);
            }
            if (line.find(points_end) != line.npos)
                enable_points_reading = false;

            // Reading Elements
            if (enable_elements_reading)
            {
                this->readElementFromLine(line);
            }
            if (line.find(elements_start) != line.npos)
            {
                // std::cout << line;
                enable_elements_reading = true;
                getline(gmsh_file, line);
                std::regex_search(line, match_elements_number, elements_number_regex);
                std::stringstream x_stream(match_elements_number[0]);
                x_stream >> int_elements_number;
            }
            if (line.find(elements_end) != line.npos)
                enable_elements_reading = false;
            
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
    

    //std::cout << "String that matches the pattern:" << std::endl;
    for (auto x : match_node) 
    {
        std::stringstream x_stream(x);
        x_stream >> node_ind;
        //std::cout << node_ind << " ";

        if (node_ind > points_cords.size())
            std::cout << "WARNING !! Mesh::readPointsFromLine : node_ind is out of range !" << std::endl;
    }
    
    while (std::regex_search(line_, match_cordinates, coordinate_regex))
    {
        std::stringstream x_stream(match_cordinates[0]);
        x_stream >> node_coord;
        //std::cout << node_coord << " ";
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

    points_cords[node_ind - 1] = tmp_point;
    
    // std::cout << std::endl;
    // std::cout << line_init << std::endl;
    // std::cout << "***********************" << std::endl;
    
}



void Mesh::readElementFromLine(std::string line_)
{
    // $Elements
    // number-of-elements
    // elm-number elm-type number-of-tags < tag > … node-number-list
    // …
    // $EndElements
    // elm-type:
    // 15 - 1-node point
    // 1 - 2-node line
    // 2 - 3-node triangle

    std::string line_init = line_;
    int elm_ind, elm_type_int, num_of_tags;
    std::vector<int> elm_tags, elm_nodes, elm_neighb_;

    int col_ctr = 1;
    int node_ctr = 0;

    std::regex elm_int_regex("[0-9]+");
    std::smatch match_int;

    

    while (std::regex_search(line_, match_int, elm_int_regex))
    {
        std::stringstream x_stream(match_int[0]);

        if (col_ctr == 1) // Element ind
            x_stream >> elm_ind;
        else if (col_ctr == 2) // Element type
        {
            x_stream >> elm_type_int;
            this -> resizeElementNodesVar(&elm_nodes, elm_type_int);
            
        }
        else if (col_ctr == 3) // number of element tags
        {
            x_stream >> num_of_tags;
            elm_tags.resize(num_of_tags);
        }
        else if (col_ctr > 3 and col_ctr <= 3+num_of_tags)
            x_stream >> elm_tags[col_ctr-4];
        else
        {
            x_stream >> elm_nodes[node_ctr];
            node_ctr++;
        }
        
        line_ = match_int.suffix();
        
        

        col_ctr++;
            
    }

    // for (auto x : elm_nodes)
    //     std::cout << x << " ";
    
    // std::cout << "\n";

    // instating an Element
    switch (elm_type_int)
    {
    case 15:
        break;
    case 1: // 2-node line
        boundary_elements.push_back(Line(elm_nodes, elm_tags)); 
        break;
    case 2: // 3-node triangle
        interior_elements.push_back(Triangle(elm_nodes, elm_tags));
        break;
    default:
        break;
    }
}


void Mesh::printMeshInfo()
{
    std::cout << "Boundary elements: " << boundary_elements.size() << std::endl;
    std::cout << "Interior elements: " << interior_elements.size() << std::endl;
}

void Mesh::resizeElementNodesVar(std::vector<int> * elm_nodes_, int elm_type_int_)
{
    switch (elm_type_int_)
    {
    case 15:
        elm_nodes_ -> resize(1); // 1-node point
        break;
    case 1:
        elm_nodes_ -> resize(2); // 2-node line
        break;
    case 2:
        elm_nodes_ -> resize(3); // 3-node triangle
        break;
    default:
        break;
    }
}

void Mesh::initFVMesh()
{
    this -> findNeighbours();
}

void Mesh::findNeighbours()
{
    std::vector<Element>::iterator elm_iter_start = interior_elements.begin();
    std::vector<Element>::iterator elm_iter_end = interior_elements.end();
    std::vector<Element>::iterator elm_iter_1 = elm_iter_start;
    int elm_ind_2, elm_ind_2_end;
    elm_ind_2_end = interior_elements.size();

    int neighbour_ctr = 0;
    int neighbour_err;

    std::vector<Face> elm_faces_1, elm_faces_2;

    for (elm_iter_1; elm_iter_1 != elm_iter_end; elm_iter_1++)
    {

        for (elm_ind_2 = 0; elm_ind_2 < elm_ind_2_end; elm_ind_2++)
        {
            elm_faces_2 = interior_elements[elm_ind_2].faces_;

            elm_iter_1 -> checkIfNeighbour(elm_faces_2, elm_ind_2);
        }
    }

    
    for (elm_iter_1 = elm_iter_start; elm_iter_1 != elm_iter_end; elm_iter_1++)
    {

        for (int ind = 0; ind < 3; ind++)
        {
            if ((*elm_iter_1).neighbours_[ind] > -1)
                neighbour_ctr++;
        }
    }
    neighbour_err = 3*interior_elements.size() - boundary_elements.size() - neighbour_ctr;

    std::cout << "Neighbour error: " << neighbour_err << std::endl;
}


