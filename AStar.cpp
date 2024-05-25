#include <AStar.h>

#include <limits>
#include <iostream>

AStar::AStar(Graph graph, int start, int end, int numberOfRows, int numberOfColumns) :
        graph(graph),
        startVertex(start),
        endVertex(end),
        numberOfRows(numberOfRows), 
        numberOfColumns(numberOfColumns) {
    initializeVariables();
};

void AStar::initializeVariables() {
    countOfExpansions = 0;
    adjacencyLists = graph.getAdjList();
    numberOfVertices = graph.getNumberOfVertices();
    closedSet = std::vector<bool>(numberOfVertices, false);
    gScore = std::vector<double>(numberOfVertices, std::numeric_limits<double>::infinity());
    cameFrom = std::vector<int>(numberOfVertices, -1); 
    gScore[startVertex] = 0;
    openSet.push({startVertex, 0});
}

void AStar::findPathFromStartTo(int goal) {
    shortestPath.clear();
    int currentVertex = goal;
    while (currentVertex != -1) {
        shortestPath.emplace_back(currentVertex);
        currentVertex = cameFrom[currentVertex];
    } 
}

int AStar::expandNextVertex(){
    countOfExpansions++;
    int currentVertex = openSet.top().first;
    openSet.pop();
    closedSet[currentVertex] = true;
    return currentVertex;
}

void AStar::exploreAllNeighbors(int currentVertex) {
    for (const auto& neighbor : adjacencyLists[currentVertex]) {
        int neighborId = neighbor.first;
        double edgeCost = neighbor.second;

        // if (closedSet[neighborId]) { 
        //     continue; 
        // }
        double tentativeGScore = gScore[currentVertex] + edgeCost;

        if (tentativeGScore < gScore[neighborId]) {
            cameFrom[neighborId] = currentVertex;
            gScore[neighborId] = tentativeGScore;
            double h = heuristicFunction(neighborId);
            openSet.push({neighborId, tentativeGScore + h});
        }
    }
}

int AStar::heuristicFunction(int vertex) {
    // Chebyshev metric
    return std::max(std::abs(vertex % 1000 - endVertex % 1000), std::abs(vertex / 1000 - endVertex / 1000));
}

void AStar::run() {
    initializeVariables();
    while (!openSet.empty()) {
        int currentVertex = expandNextVertex();
        if (currentVertex == endVertex) {
            std::cout << countOfExpansions << "\n";
            findPathFromStartTo(currentVertex); 
            return;
        }
        exploreAllNeighbors(currentVertex); 
    }
    return;
}

std::vector<int> AStar::getShortestPath() {
    return shortestPath;
}