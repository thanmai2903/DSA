-   Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a weighted, undirected, and connected graph.
-   Kruskal's algorithm grows the MST by adding the edges with the smallest weights, while ensuring that no cycles are formed in the process. It utilizes the disjoint-set data structure to efficiently check for cycles.
-   It starts by sorting all the edges in non-decreasing order of their weights and then iteratively adds the edges to the MST, ensuring that adding an edge does not create a cycle.

**Steps**

1. **Sort all edges:** Arrange the edges in non-decreasing order of their weights. This crucial step ensures efficient selection of edges during the algorithm.
2. **Initialization:**
    - Create a disjoint-set data structure (DSU) to efficiently keep track of connected components formed as the algorithm progresses.
    - Each vertex initially belongs to its own set in the DSU.
3. **Main Loop:**

-   Iterate through the sorted edges:
    -   For each edge (u, v):
        -   Use the **find** function of the DSU to determine the sets containing vertices u and v.
        -   If the two vertices belong to different sets (indicating no cycle formation):
            -   Merge the sets containing u and v using the **union** function of the DSU. This effectively combines them into a single connected component.
            -   Add the current edge (u, v) to the MST.

4. **Output:**
   The edges included in the MST represent the minimum spanning tree of the graph.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else if (rank[pv] > rank[pu])
            parent[pu] = pv;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> MST;
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(V);

    for (const Edge& edge : edges) {
        int srcParent = ds.find(edge.src);
        int destParent = ds.find(edge.dest);
        if (srcParent != destParent) {
            MST.push_back(edge);
            ds.merge(srcParent, destParent);
        }
    }

    return MST;
}

int main() {
    int V = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> MST = kruskalMST(edges, V);

    // Print MST
    cout << "Edges in MST:\n";
    for (const auto& edge : MST) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
```

**TC** -> O(Elog(E))
**SC** -> O(V)

[Visualize](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)
