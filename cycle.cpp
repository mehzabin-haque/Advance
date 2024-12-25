#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// Global variables
int numNodes, numEdges;
const int MAX_NODES = 1e5 + 1;
vector<int> adjacencyList[MAX_NODES];
int visited[MAX_NODES] = {};  // Visited states: 0 = unvisited, 1 = visiting, 2 = completely processed
int parent[MAX_NODES] = {};  // Tracks the parent node in DFS
int minCycleSum = INT_MAX;   // Stores the minimum sum of nodes in a cycle
vector<int> smallestCycle;   // Stores the nodes of the smallest cycle by sum

// Depth First Search (DFS) function to detect cycles
void dfs(int currentNode) {
    visited[currentNode] = 1;  // Mark the current node as visiting (in progress)
    
    for (int neighbor : adjacencyList[currentNode]) {
        if (visited[neighbor] == 0) {  // If the neighbor is unvisited
            parent[neighbor] = currentNode;  // Set the parent of the neighbor
            dfs(neighbor);  // Recursively call DFS on the neighbor
        } 
        else if (visited[neighbor] == 1) {  // If the neighbor is currently being visited, a cycle is detected
            vector<int> cycleNodes;
            int cycleSum = 0;

            // Start forming the cycle
            cycleNodes.push_back(currentNode);
            cycleSum += currentNode;

            int traceBack = currentNode;
            while (traceBack != neighbor) {
                traceBack = parent[traceBack];
                cycleNodes.push_back(traceBack);
                cycleSum += traceBack;
            }

            // Sort the cycle nodes in ascending order
            sort(cycleNodes.begin(), cycleNodes.end());

            // Update the smallest cycle if the current cycle has a smaller sum
            if (cycleSum < minCycleSum) {
                minCycleSum = cycleSum;
                smallestCycle = cycleNodes;
            }
        }
    }

    visited[currentNode] = 2;  // Mark the current node as completely processed
}

int main() {
    // Input the number of nodes and edges
    cin >> numNodes >> numEdges;

    // Input the edges
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cin >> from >> to;
        adjacencyList[from].push_back(to);  // Add the edge from 'from' to 'to'
    }

    // Perform DFS for all unvisited nodes
    for (int i = 1; i <= numNodes; ++i) {
        if (visited[i] == 0) {
            parent[i] = i;  // Set the parent of the starting node to itself
            dfs(i);
        }
    }
    
    // Output the smallest cycle
    if (smallestCycle.empty()) {
        cout << "No cycle found" << endl;
    } else {
        for (int node : smallestCycle) {
            cout << node << ' ';
        }
        cout << endl;
    }

    return 0;
}
