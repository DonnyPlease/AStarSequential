#include <AStar.h>

#include <limits>
#include <iostream>
#include <cmath>

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

        if (closedSet[neighborId]) { 
             continue; 
        }
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

    int vertexRow = vertex / numberOfColumns;
    int vertexCol = vertex % numberOfColumns;
    int endRow = endVertex / numberOfColumns;
    int endCol = endVertex % numberOfColumns;

    // Chebyshev metric
    //return std::max(std::abs(vertexRow - endRow), std::abs(vertexCol - endCol));
    
    //euclidean
    // return std::sqrt(std::pow(vertexRow - endRow, 2) + std::pow(vertexCol - endCol, 2))*9.9;

    // chebyshev adjusted
    int dx = std::abs(vertexRow - endRow);
    int dy = std::abs(vertexCol - endCol);
    
    return 10 * (dx + dy) + (14 - 2 * 10) * std::min(dx, dy);
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