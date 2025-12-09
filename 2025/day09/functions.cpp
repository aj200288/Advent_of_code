#include "functions.h"
#include <iostream>


bool Edge::is_vertical() {
    if (u.x == v.x)
        return true;
    return false;
}



// žarek od point do point y do max X + 1
// zanimajo nas samo navpični edgi -> bomo že v main podal
bool intersect_edge(Point point, Edge edge) {
    int edgeX = edge.u.x; // ker podamo samo navpične (mogoče bo treba spremenit za preverjanje sekanja stranic kvadrata)
    int edgeY1 = std::min(edge.u.y, edge.v.y);
    int edgeY2 = std::max(edge.u.y, edge.v.y);


    int pointX1 = point.x;
    int pointX2 = 100000;
    int pointY = point.y;

    if (pointX1 <= edgeX && edgeX <= pointX2 && edgeY1 <= pointY && pointY <= edgeY2)
        return true;
    return false;
}


// mogoče kle vzameš dva pointa + edge, kjer sta v primeru prewverjanja točke ali je znotraj poligona
// točki točka ki jo perverjamo in točka proti kateri gre žarek
// edge je v obeh primerih vask edge
// razlika je da v prvem primeru nas zanimajo samo navpični edgi
// v drugem primeru pa vsi