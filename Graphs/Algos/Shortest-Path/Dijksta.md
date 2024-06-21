# Dijkstra's Algorithm for Shortest Path in a Weighted Graph

```
Given a graph and a source vertex in the graph, find the shortest paths from source to all vertices in the given graph.
```

Dijkstra's algorithm is a variation of the BFS algorithm. In Dijkstra's Algorithm, a SPT(shortest path tree) is generated with given source as root. Each node at this SPT stores the value of the shortest path from the source vertex to the current vertex. We maintain two sets, one set contains vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree. At every step of the algorithm, we find a vertex which is in the other set (set of not yet included) and has a minimum distance from the source.

#### Algorithm

```
1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq. Every item
   of pq is a pair (weight, vertex). Weight (or
   distance) is used as the first item of pair
   as the first item is by default used to compare
   two pairs

3) Insert source vertex into pq and make its
   distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq.
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do
       following for every vertex v.

           // If there is a shorter path to v
           // through u.
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)

5) Print distance array dist[] to print all shortest
   paths.
```

#### Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

// Define the structure of the graph
typedef pair<int, int> pii; // pair<weight, node>

// Dijkstra's Algorithm
void dijkstra(int source, vector<vector<pii>>& graph, vector<int>& distances) {
    // Priority queue to select the edge with the smallest weight
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Initialize distances to infinity
    distances.assign(graph.size(), INT_MAX);
    distances[source] = 0;

    // Start with the source node
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // If the distance is greater than the stored distance, skip
        if (dist > distances[node]) continue;

        // Update the distances to the adjacent nodes
        for (const auto& neighbor : graph[node]) {
            int nextNode = neighbor.second;
            int edgeWeight = neighbor.first;

            if (distances[node] + edgeWeight < distances[nextNode]) {
                distances[nextNode] = distances[node] + edgeWeight;
                pq.push({distances[nextNode], nextNode});
            }
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii>> graph(V);

    // Construct the graph
    graph[0].push_back({10, 1});
    graph[0].push_back({5, 2});
    graph[1].push_back({1, 2});
    graph[1].push_back({2, 3});
    graph[2].push_back({9, 3});
    graph[2].push_back({2, 4});
    graph[3].push_back({4, 4});
    graph[4].push_back({6, 0});

    int source = 0;
    vector<int> distances;

    // Call Dijkstra's algorithm
    dijkstra(source, graph, distances);

    // Output the shortest distances from the source to each node
    cout << "Node\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << distances[i] << endl;
    }

    return 0;
}
```

**Time Complexity:** The time complexity of the Dijkstra's Algorithm when implemented using a min heap is O(E \* logV), where E is the number of Edges and V is the number of vertices.

**Note:** The Dijkstra's Algorithm **doesn't work** in the case when the Graph has negative edge weight.

[Find Edges in Shortest Paths](https://leetcode.com/problems/find-edges-in-shortest-paths/)

**Intuition**

1.  Find dist matrix i,e shortest paths from src to every other node
2.  Find dist matrix i,e shortest paths from dest to every other node
3.  given shortest path = dist[n-1] from src
    // a w b
    // src ----- (x) ----- (y) ----- dest

            // the edges are undirected, hence try both ways
            // considering edges[i][0] to be x and edges[i][1] to be y

4.  if a+w+b == shortestpath => it belons to shortest path

#### Code

```cpp
#define ll long long
typedef pair<ll, int> pli;

class Solution {
public:
    vector<ll> getShortestPath(vector<vector<pair<int, ll>>>& graph, int src, int n) {
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        vector<ll> dist(n, LLONG_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] < d)
                continue;

            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<vector<pair<int, ll>>> getGraph(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, ll>>> graph(n);

        for (auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        return graph;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, ll>>> graph = getGraph(n, edges);

        vector<ll> fromStart = getShortestPath(graph, 0, n);
        vector<ll> fromEnd = getShortestPath(graph, n - 1, n);
        ll shortestDistance = fromStart[n - 1];

        vector<bool> res(edges.size(), false);
        for (int i = 0; i < edges.size(); i++) {
            // considering edges[i][0] to be x and edges[i][1] to be y
            ll distFromStart = fromStart[edges[i][0]];
            ll distFromEnd = fromEnd[edges[i][1]];
            ll midDist = edges[i][2];

            if (distFromStart != LLONG_MAX && distFromEnd != LLONG_MAX && distFromStart + distFromEnd + midDist == shortestDistance)
                res[i] = true;

            // considering edges[i][0] to be y and edges[i][1] to be x
            distFromStart = fromStart[edges[i][1]];
            distFromEnd = fromEnd[edges[i][0]];

            if (distFromStart != LLONG_MAX && distFromEnd != LLONG_MAX && distFromStart + distFromEnd + midDist == shortestDistance)
                res[i] = true;
        }

        return res;
    }
};
```

[Network Delay Time](https://leetcode.com/problems/network-delay-time/)
**Intuition**

1. It is 1 indexed to n
2. Find dist vector from scr using dijkstra
3. find max in that vector.

```cpp
typedef pair<int, int>pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> gr(n);

        for (auto& e : times) {
            gr[e[0] - 1].push_back({e[1] - 1, e[2]});
        }

        vector<int> dist = getShortestPath(gr, k - 1, n);

        int maxDist = *max_element(dist.begin(), dist.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }

private:
    vector<ll> getShortestPath(vector<vector<pii>>& graph, int src, int n) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] < d)
                continue;

            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};
```

[Cheapest Flights with K Steps](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
**Intuition**

1. Make a tuple of dist, node, stops
2. Get Min Cost untill stops == 0
3. Aplly Dijkstra without need of distance vector, if for every for u:adj[v] if u is dest then return that cost

```cpp
typedef tuple<int,int,int> ti;//dist, node, stops
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> gr(n);
        for(auto e: flights){
            gr[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<ti, vector<ti>, greater<ti>>pq;
        pq.push({0, src, k+1});

        while(!pq.empty()){
            auto [dist, node, stops] = pq.top();
            pq.pop();
            if(node == dst){
                return dist;
            }
            if(!stops){
                continue;
            }
            for(auto neigh: gr[node]){
                auto [v, w] = neigh;
                pq.push({dist+w, v, stops-1});
            }
        }
        return -1;
    }
};
```

## M-2 BFS

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> gr(n);
        for(auto& e: flights) {
            gr[e[0]].push_back({e[1], e[2]});
        }

        queue<pair<int, int>> q;
        q.push({0, src});
        int res = INT_MAX;

        while(!q.empty() && k-- >= 0){
            int sz = q.size();
            while(sz--){
                auto [cost, node] = q.front();
                q.pop();
                for(auto [v, w]: gr[node]){
                    if(res < cost+w){
                        continue;
                    }
                    q.push({cost+w, v});
                    if(dst == v){
                        res = min(res, cost+w);
                    }
                }
            }
        }
        return res == INT_MAX?-1:res;
    }
};
```

[Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/)

```cpp
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int e) {
        typedef pair<double, int> pdi; // (probability, node)
        vector<vector<pair<int, double>>> gr(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            gr[u].push_back({v, w});
            gr[v].push_back({u, w});
        }

        priority_queue<pdi> pq;
        pq.push({1.0, s}); // (probability, node)
        vector<double> probabilities(n, 0.0);
        probabilities[s] = 1.0;

        while (!pq.empty()) {
            auto [prob, u] = pq.top();
            pq.pop();
            if (u == e) {
                return prob;
            }
            for (auto& [v, w] : gr[u]) {
                double new_prob = prob * w;
                if (new_prob > probabilities[v]) {
                    probabilities[v] = new_prob;
                    pq.push({new_prob, v});
                }
            }
        }
        return 0.0;
    }
};
```
