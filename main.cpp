#include <Graph.h>
#include <AStar.h>

#include <vector>
#include <iostream>


int main() {
    int numberOfRows = 10000;
    int numberOfColumns = 10000;
    Graph graph = GraphFactory::create2DGridGraph(numberOfRows, numberOfColumns);
    graph.removeEdge(55,65);
    graph.removeEdge(55,66);
    graph.removeEdge(56,66);
    graph.removeEdge(56,67);
    graph.removeEdge(54,65);
    // graph.printGraph();
    int start = 0;
    int end = 99;
    AStar astar(graph, start, end, numberOfRows, numberOfColumns);
    astar.run();
    auto path = astar.getShortestPath();
    
    // for (auto it = path.rbegin(); it != path.rend(); it++) {
    //     std::cout << *it << " -> ";
    // }
}