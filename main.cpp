#include <Graph.h>
#include <AStar.h>

#include <vector>
#include <iostream>


int main() {
    int numberOfRows = 100;
    int numberOfColumns = 100;
    Graph graph = GraphFactory::create2DGridGraph(numberOfRows, numberOfColumns);
    int start = 0;
    int end = 2020;
    AStar astar(graph, start, end, numberOfRows, numberOfColumns);
    astar.run();
    auto path = astar.getShortestPath();
    
    for (auto it = path.rbegin(); it != path.rend(); it++) {
        std::cout << *it << " -> ";
    }
}