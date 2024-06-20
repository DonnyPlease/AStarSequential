#pragma once

#include <Graph.h>

#include <vector>
#include <queue>

template<typename T>
struct PairComparator {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs.second > rhs.second;
    }
};


class AStar {
private:
    Graph               graph;
    int                 startVertex;
    int                 endVertex;
    std::vector<int>    shortestPath;
    int                 numberOfRows;
    int                 numberOfColumns;

private:
    int countOfExpansions;
    std::vector<std::vector<std::pair<int,double>>> adjacencyLists;
    int numberOfVertices;
    std::priority_queue<std::pair<int, double>, std::vector<std::pair<int, double>>, PairComparator<std::pair<int, double>>> openSet;
    
    std::vector<bool>   closedSet;
    std::vector<double> gScore;
    std::vector<int>    cameFrom;

public:
    AStar(Graph graph, int start, int end, int numberOfRows, int numberOfColumns);

public:
    void run();
    std::vector<int> getShortestPath();

private:
    void initializeVariables();
    void findPathFromStartTo(int goal);
    int  expandNextVertex();
    void exploreAllNeighbors(int currentVertex);
    int  heuristicFunction(int vertex);
};


