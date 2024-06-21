# Floyd-Warshal

**Algorithm:**

1. Initialize the distance matrix: If there's an edge between nodes i and j, set the distance to the weight of the edge. If there's no edge, set the distance to infinity (or a large value). The distance from any node to itself is 0.
2. Iterate through all possible intermediate nodes: For each pair of nodes i and j, check if a path through an intermediate node k offers a shorter path. If it does, update the distance matrix.

```cpp
for each k in nodes:
    for each i in nodes:
        for each j in nodes:
            if distance[i][k] + distance[k][j] < distance[i][j]:
                distance[i][j] = distance[i][k] + distance[k][j]
```

## Code

```cpp
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF INT_MAX

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) dist[i][j] = 0;
            else if (graph[i][j] != 0) dist[i][j] = graph[i][j];
        }
    }

    // Update the solution matrix by considering all vertices as intermediate vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) cout << "INF" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix (use 0 for no edge and positive values for weights):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    floydWarshall(graph, V);

    return 0;
}
```

**TimeComplexity** : O(V^3)
**SpaceComplexity** : O(V^2)
