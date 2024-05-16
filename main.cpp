#include <Graph.h>
#include <AStar.cpp>

#include <vector>
#include <iostream>


int main() {
    Graph graph = GraphFactory::create2DGridGraph(10,10);
    graph.removeEdge(55,65);
    graph.removeEdge(55,66);
    graph.removeEdge(56,66);
    graph.removeEdge(56,67);
    graph.removeEdge(54,65);
    graph.printGraph();
    int start = 0;
    int end = 99;
    AStar astar(graph, start, end);
    astar.run();
    auto path = astar.getShortestPath();
    
    for (auto it = path.rbegin(); it != path.rend(); it++) {
        std::cout << *it << " -> ";
    }
}