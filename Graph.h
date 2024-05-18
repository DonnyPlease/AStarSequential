#pragma once

#include <vector>

class Graph {
private:
    int numberOfVertices; // Number of vertices
    std::vector<std::vector<std::pair<int, double>>> adjacencyLists; // Adjacency list

public:
    Graph(int vertices);

public:
    void addEdge(int u, int v, int cost = 0);
    void removeEdge(int u, int v);
    std::vector<std::pair<int, double>> getNeighbors(int vertex);
    std::vector<std::vector<std::pair<int, double>>> getAdjList();
    int getNumberOfVertices();
    void printGraph();
    int getCost(int u, int v);
};

class GraphFactory {
public:
    static Graph createFullyConnectedGraph(int vertices);
    static Graph create2DGridGraph(int rows, int columns);
};