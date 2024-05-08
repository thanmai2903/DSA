# Prim's Algorithm

-   Prim's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a weighted, undirected, and connected graph.
-   An MST is a subset of edges that connects all vertices in the graph with the minimum total edge weight while avoiding cycles.
-   Prim's algorithm grows a minimum spanning tree from a starting node, adding the cheapest edge at each step until all nodes are connected.

## Steps

1. Choose an arbitrary starting node.
2. Add it to the MST and mark it as visited.
3. Repeat until all nodes are visited:
   a. Among the edges that connect visited and unvisited nodes(all edges in current MST), choose the one with the minimum weight.
   b. Add the selected edge to the MST and mark its endpoint as visited.

```cpp
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> key(V, INF);//key[] to store the weight of the minimum edge connecting a vertex to the MST
    vector<bool> visited(V, false);

    int minCost = 0;

    key[0] = 0; // Start from the first node

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        // Find the vertex with the minimum key value
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        visited[u] = true; // Mark the selected vertex as visited

        // Update key values of adjacent vertices
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
                key[v] = graph[u][v];
        }
    }

    // Calculate the minimum cost
    for (int v = 0; v < V; ++v)
        minCost += key[v];

    return minCost;
}

int main() {
    // Example graph representation (adjacency matrix)
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    cout << "Minimum Cost: " << primMST(graph) << endl;

    return 0;
}
```

**Time Complexity (TC):** O(V^2)
**Space Complexity (SC):** O(V)

## Optimized Prim's Algorithm with Priority Queue and Fibonacci Heap (Advanced):

-   To optimize Prim's algorithm, we can use a priority queue to efficiently select the next vertex with the minimum key value. Additionally, we can use Fibonacci heaps for the priority queue to achieve better performance.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;

int primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> key(V, INF);
    vector<bool> visited(V, false);
    int minCost = 0;

    // Priority queue to store vertices with key values
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 0}); // Start from the first node

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        minCost += cost;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
            }
        }
    }

    return minCost;
}

int main() {
    // Example graph representation (adjacency matrix)
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    cout << "Minimum Cost: " << primMST(graph) << endl;

    return 0;
}
```

**TC** -> O(E \* log(V))
**SC** -> O(V)

-   We use a priority queue to efficiently select the next vertex with the minimum key value.
-   The priority queue stores pairs (key, vertex) where key is the minimum key value and vertex is the corresponding vertex.
-   We start from the first vertex and push it into the priority queue with key = 0.
-   At each step, we pop the vertex u with the minimum key value from the priority queue.
-   We update the key[] values of adjacent vertices of u if they are not yet visited and if the weight of the edge is less than the current key[] value. If updated, we push the updated values into the priority queue.
-   We continue this process until the priority queue is empty, and then we return the sum of all key[] values as the minimum cost of the MST.
-   Using a priority queue reduces the time complexity to O(E log V), where E is the number of edges and V is the number of vertices. This is a significant improvement over the basic version of Prim's algorithm, especially for dense graphs. If further optimization is needed, Fibonacci heaps can be used for the priority queue, achieving even better performance in terms of time complexity. However, implementing Fibonacci heaps is more complex and may not be necessary for many practical applications.

## Using Fibonacci Heap

```cpp
void primMST_FibonacciHeap(vector<vector<int>>& graph) {
  // ... initialization
  fh.insert(starting_vertex, 0); // Insert starting vertex with key 0
  while (!fh.isEmpty()) {
    int u = fh.extract-min(); // Extract vertex with minimum key
    visited[u] = true;
    // ... iterate through adjacent edges and update keys/parents
    for (int v : adjacent_vertices(u)) {
      // ... update key/parent logic using fh.decrease-key() or fh.insert()
    }
  }
}
```

**TC** -> O(E\*log(log(v)))
**SC** -> O(V)

**Summary**

| Approach       | Time Complexity (for `V` vertices and `E` edges) | Space Complexity |
| -------------- | ------------------------------------------------ | ---------------- |
| Naive          | O(V^2)                                           | O(V)             |
| Min Heap       | O((V + E) \* log(V))                             | O(V)             |
| Fibonacci Heap | O(V \* log(V) + E)                               | O(V)             |

**Naive Approach:**
**Time Complexity:** For each vertex, we need to check all edges, leading to O(V^2).
**Space Complexity:** O(V) for storing vertices.

**Min Heap:**
**Time Complexity:** Each decrease-key operation in the min heap takes O(log V) time, and we perform it for each vertex once, resulting in O(V _ log(V)). Additionally, extracting the minimum element and updating the adjacent vertices takes O(E _ log(V)) time.
**Space Complexity:** O(V) for storing vertices.

**Fibonacci Heap:**
**Time Complexity**: Decrease-key operation in Fibonacci heap takes O(1) amortized time, leading to a total of O(V \* log(V)) for all vertices. The extraction of minimum element and updating adjacent vertices takes O(E) time.
**Space Complexity:** O(V) for storing vertices.
It's important to note that while Fibonacci heaps theoretically have better time complexity than min heaps, they come with higher constant factors and are more complex to implement. In practice, for most graph sizes and densities, the difference in performance between min heaps and Fibonacci heaps may not be significant. Hence, min heaps are preferred due to their simplicity.
