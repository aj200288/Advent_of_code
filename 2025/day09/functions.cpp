#include "functions.h"
#include <iostream>


bool Edge::is_vertical() {
    return u.x == v.x;
}



// sam zameni imeni, da bo bl pregledno
bool intersect_two_edges(Edge edge1, Edge edge2) {
    if (edge1.is_vertical() == edge2.is_vertical()) return false; // sta vzporedna me sploh ne zanima
    else if (edge1.is_vertical()) {
        long long VedgeX = edge1.u.x;
        long long VedgeY1 = std::min(edge1.u.y, edge1.v.y);
        long long VedgeY2 = std::max(edge1.u.y, edge1.v.y);

        long long HedgeX1 = std::min(edge2.u.x, edge2.v.x);
        long long HedgeX2 = std::max(edge2.u.x, edge2.v.x);
        long long HedgeY = edge2.u.y;

        if (HedgeX1 < VedgeX && VedgeX < HedgeX2 && VedgeY1 < HedgeY && HedgeY < VedgeY2)
            return true;
    }
    else if (edge2.is_vertical()) {
        long long VedgeX = edge2.u.x;
        long long VedgeY1 = std::min(edge2.u.y, edge2.v.y);
        long long VedgeY2 = std::max(edge2.u.y, edge2.v.y);

        long long HedgeX1 = std::min(edge1.u.x, edge1.v.x);
        long long HedgeX2 = std::max(edge1.u.x, edge1.v.x);
        long long HedgeY = edge1.u.y;
        
        if (HedgeX1 < VedgeX && VedgeX < HedgeX2 && VedgeY1 < HedgeY && HedgeY < VedgeY2)
            return true;
    }
    return false;
}



// žarek od point do point y do max X + 1
// zanimajo nas samo navpični edgi -> bomo že v main podal
bool intersect_edge(Point point, Edge edge) {
    long long edgeX = edge.u.x; // ker podamo samo navpične (mogoče bo treba spremenit za preverjanje sekanja stranic kvadrata)
    long long edgeY1 = std::min(edge.u.y, edge.v.y);
    long long edgeY2 = std::max(edge.u.y, edge.v.y);

    long long pointX = point.x;
    long long pointY = point.y;

    // Use half-open interval [edgeY1, edgeY2) to handle vertices consistently
    if (pointX < edgeX && edgeY1 <= pointY && pointY < edgeY2) //okej zej če dam edgeY1 <= pointY namest < del a??? why
        return true;
    return false;
}


bool on_edge(Point point, Edge edge) {
    // Check vertical edge
    if (edge.is_vertical()) {
        long long edgeX = edge.u.x;
        long long edgeY1 = std::min(edge.u.y, edge.v.y);
        long long edgeY2 = std::max(edge.u.y, edge.v.y);
        
        if (point.x == edgeX && edgeY1 <= point.y && point.y <= edgeY2)
            return true;
    }
    // Check horizontal edge
    else {
        long long edgeY = edge.u.y;
        long long edgeX1 = std::min(edge.u.x, edge.v.x);
        long long edgeX2 = std::max(edge.u.x, edge.v.x);
        
        if (point.y == edgeY && edgeX1 <= point.x && point.x <= edgeX2)
            return true;
    }
    return false;
}
// mogoče kle vzameš dva pointa + edge, kjer sta v primeru prewverjanja točke ali je znotraj poligona
// točki točka ki jo perverjamo in točka proti kateri gre žarek
// edge je v obeh primerih vask edge
// razlika je da v prvem primeru nas zanimajo samo navpični edgi
// v drugem primeru pa vsi