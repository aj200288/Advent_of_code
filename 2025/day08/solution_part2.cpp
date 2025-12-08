#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

struct Point3D {
    int x, y, z;
};

struct Edge {
    int u, v;
    double distance;
    
    bool operator<(const Edge& other) const {
        return distance < other.distance;
    }
};

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> size;
    
public:
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false;
        }
        
        if (size[rootX] < size[rootY]) {
            std::swap(rootX, rootY);
        }
        
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        return true;
    }
    
    int getSize(int x) {
        return size[find(x)];
    }
    
    std::vector<int> getAllComponentSizes() {
        std::vector<int> componentSizes;
        for (int i = 0; i < parent.size(); i++) {
            if (find(i) == i) {
                componentSizes.push_back(size[i]);
            }
        }
        return componentSizes;
    }
};

double (calculateDistance)(const Point3D& a, const Point3D& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    std::ifstream file("input.txt");
    std::vector<Point3D> points;
    std::string line;
    
    // Read all junction boxes
    while (std::getline(file, line)) {
        Point3D p;
        std::replace(line.begin(), line.end(), ',', ' ');
        std::stringstream ss(line);
        ss >> p.x >> p.y >> p.z;
        points.push_back(p);
    }
    file.close();
    
    int n = points.size();
    int numEdgesToProcess = (n == 20) ? 10 : 1000;  // 10 for test, 1000 for real input
    std::cout << "Number of junction boxes: " << n << std::endl;
    std::cout << "Edges to process: " << numEdgesToProcess << std::endl;
    
    // Create all possible edges
    std::vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Edge e;
            e.u = i;
            e.v = j;
            e.distance = calculateDistance(points[i], points[j]);
            edges.push_back(e);
        }
    }
    
    std::cout << "Total possible edges: " << edges.size() << std::endl;
    
    // Sort edges by distance
    std::sort(edges.begin(), edges.end());
    
    // Use Union-Find to track connected components
    UnionFind uf(n);
    
    int edgesProcessed = 0;
    int connectionsAdded = 0;
    for (const auto& edge : edges) {
        if (edgesProcessed >= numEdgesToProcess) {
            break;
        }
        
        edgesProcessed++;
        if (uf.unite(edge.u, edge.v)) {
            connectionsAdded++;
            if (connectionsAdded <= 20 || edgesProcessed == numEdgesToProcess) {
                std::cout << "Edge " << edgesProcessed << " (Connection " << connectionsAdded << "): " 
                         << edge.u << " <-> " << edge.v 
                         << " (distance: " << edge.distance << ")" << std::endl;
            }
        } else {
            if (edgesProcessed <= 20 || edgesProcessed == numEdgesToProcess) {
                std::cout << "Edge " << edgesProcessed << ": " 
                         << edge.u << " <-> " << edge.v 
                         << " (already connected, distance: " << edge.distance << ")" << std::endl;
            }
        }
    }
    
    std::cout << "\nEdges processed: " << edgesProcessed << std::endl;
    std::cout << "Connections added: " << connectionsAdded << std::endl;
    
    // Get all component sizes
    std::vector<int> componentSizes = uf.getAllComponentSizes();
    
    // Sort in descending order to find the three largest
    std::sort(componentSizes.begin(), componentSizes.end(), std::greater<int>());
    
    std::cout << "\nNumber of circuits: " << componentSizes.size() << std::endl;
    std::cout << "Component sizes (largest first): ";
    for (int i = 0; i < std::min(10, (int)componentSizes.size()); i++) {
        std::cout << componentSizes[i] << " ";
    }
    std::cout << std::endl;
    
    // Multiply the three largest
    if (componentSizes.size() >= 3) {
        long long result = (long long)componentSizes[0] * 
                          componentSizes[1] * 
                          componentSizes[2];
        std::cout << "\nThree largest circuits: " 
                 << componentSizes[0] << " * " 
                 << componentSizes[1] << " * " 
                 << componentSizes[2] 
                 << " = " << result << std::endl;
    }
    
    return 0;
}


//123234
