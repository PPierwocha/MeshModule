#include <string>
#include "..\Mesh\Mesh.h"





int main()
{
    std::string file_name = "..\\data\\square.msh";
    Mesh test_mesh;

    test_mesh.readGmshFile(file_name);

    test_mesh.initFVMesh();
    
    test_mesh.printMeshInfo();
    return 0;
}