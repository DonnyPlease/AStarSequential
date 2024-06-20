#include <Graph.h>
#include <AStar.h>

#include <vector>
#include <iostream>


void removeVertices(Graph &graph) {
    graph.removeVertex(3055);
    graph.removeVertex(3155);
    graph.removeVertex(3255);
    graph.removeVertex(3355);
    graph.removeVertex(3455);
    graph.removeVertex(3555);
    graph.removeVertex(3655);
    graph.removeVertex(3755);
    graph.removeVertex(3855);
    graph.removeVertex(3955);
    graph.removeVertex(4055);
    graph.removeVertex(4155);
    graph.removeVertex(4255);
    graph.removeVertex(4355);
    graph.removeVertex(4455);
    graph.removeVertex(4555);
    graph.removeVertex(4655);
    graph.removeVertex(4755);
    graph.removeVertex(4855);
    graph.removeVertex(4955);
    graph.removeVertex(5055);
    graph.removeVertex(5155);
    graph.removeVertex(5255);
    graph.removeVertex(5355);
    graph.removeVertex(5455);
    graph.removeVertex(5555);
    
    graph.removeVertex(5554);
    graph.removeVertex(5553);
    graph.removeVertex(5552);
    graph.removeVertex(5551);
    graph.removeVertex(5550);
    graph.removeVertex(5549);
    graph.removeVertex(5548);
    graph.removeVertex(5547);
    graph.removeVertex(5546);
    graph.removeVertex(5545);
    graph.removeVertex(5544);
    graph.removeVertex(5543);
    graph.removeVertex(5542);
    graph.removeVertex(5541);
    graph.removeVertex(5540);
    graph.removeVertex(5539);
    graph.removeVertex(5538);
    graph.removeVertex(5537);
    graph.removeVertex(5536);
    graph.removeVertex(5535);
    graph.removeVertex(5534);
    graph.removeVertex(5533);
    graph.removeVertex(5532);
    graph.removeVertex(5531);
}

void removeVertices2(Graph&graph) {
    graph.removeVertex(55);
    graph.removeVertex(56);
    graph.removeVertex(57);
    graph.removeVertex(65);
    
}

void removeVertices3(Graph &graph) {
    graph.removeVertex(555555);
    graph.removeVertex(555554);
    graph.removeVertex(555553);
    graph.removeVertex(555552);
    graph.removeVertex(555551);
    graph.removeVertex(555550);
    graph.removeVertex(555549);
    graph.removeVertex(555548);
    graph.removeVertex(555547);
    graph.removeVertex(555546);

    graph.removeVertex(555555);
    graph.removeVertex(554555);
    graph.removeVertex(553555);
    graph.removeVertex(552555);
    graph.removeVertex(551555);
    graph.removeVertex(550555);
    graph.removeVertex(549555);
    graph.removeVertex(548555);
    graph.removeVertex(547555);
    graph.removeVertex(546555);
    graph.removeVertex(545555);
}

int main() {
    int numberOfRows = 1000;
    int numberOfColumns = 1000;
    Graph graph = GraphFactory::create2DGridGraph(numberOfRows, numberOfColumns);
    removeVertices3(graph);
    int start = 0;
    int end = 999999;
    AStar astar(graph, start, end, numberOfRows, numberOfColumns);
    astar.run();
    auto path = astar.getShortestPath();
    
    std::cout << "Path length: " << path.size() << '\n';
    for (auto it = path.rbegin(); it != path.rend(); it++) {
        std::cout << *it << " -> ";
    }
}