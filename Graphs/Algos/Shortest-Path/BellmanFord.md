# Bellman-Ford

#### Somthing b/w Dijkstra and Bellman Ford

1. Both gives shortest path from one node to all other nodes.
2. Bellman works on graph with **negative weights**, But Dijkstra not. And Both Doesn't work on **Negative Cycles.**
3. Dijkstra = greedy, Belman Ford != greedy

-   In Bellamn-Ford, there could be at most |V| - 1 edges in one of our paths. (|V| is No of vertices).
-   That means >= |V| edges => repeated vertex => Cycle.
-   **Algo**

1. Initialize the distance to the source vertex as 0 and all other vertices as infinity.
2. Relax all the edges up to V−1 times, where V is the number of vertices. This means for each edge (u,v) with weight w, if the distance to v through u is less than the current distance to v, update the distance to v.
3. Check all the edges again to see if any distance can be further reduced. If it can, it means there is a negative weight cycle in the graph.

```cpp
#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

struct Edge {
    int src, dest, weight;
};

void printDistances(const vector<int>& dist, int V) {
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

void bellmanFord(const vector<Edge>& edges, int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges |V| - 1 times.
    for (int i = 1; i < V; ++i) {
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles.
    for (const auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    printDistances(dist, V);
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter the edges (source destination weight):\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(edges, V, src);

    return 0;
}
```
