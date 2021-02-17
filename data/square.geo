// Gmsh project created on Mon Oct 05 19:13:21 2020
SetFactory("OpenCASCADE");
//+
Rectangle(1) = {-0.5, -0.5, 0, 1, 1, 0};
//+
Physical Point(1) = {1};
//+
Physical Point(2) = {2};
//+
Physical Point(3) = {3};
//+
Physical Point(4) = {4};
//+
Physical Curve("south") = {1};
//+
Physical Curve("east") = {2};
//+
Physical Curve("north") = {3};
//+
Physical Curve("west") = {4};
//+
Physical Surface("interior") = {1};
