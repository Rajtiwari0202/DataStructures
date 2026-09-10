/**
 * ============================================================================
 * PHASE 9: GRAPH TRAVERSALS & SHORTEST PATH ALGORITHMS (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Topological Sort (Kahn's Algorithm - BFS In-Degree)
 *  2. Dijkstra's Algorithm (Single Source Shortest Path with Min-Heap)
 *  3. Bellman-Ford Algorithm (Handles Negative Edges & Cycle Detection)
 *  4. Floyd-Warshall Algorithm (All-Pairs Shortest Path in O(V^3))
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ============================================================================
// SECTION 1: TOPOLOGICAL SORT (Kahn's BFS Algorithm)
// ============================================================================

/**
 * Intuition:
 *  Compute in-degree of all vertices.
 *  Enqueue nodes with in-degree 0.
 *  Pop from queue, append to result, reduce in-degree of neighbors.
 *  If processed count < V, graph has a DIRECTED CYCLE!
 * 
 * Time Complexity: O(V + E) | Space Complexity: O(V)
 */
vector<int> topologicalSortKahn(int V, const vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topo.size() != V) return {}; // Cycle detected!
    return topo;
}

// ============================================================================
// SECTION 2: DIJKSTRA'S ALGORITHM (Single Source Shortest Path)
// ============================================================================

/**
 * Strategy: Min-Priority Queue storing `{dist, u}` pairs.
 *  Greedily pick unvisited vertex `u` with smallest tentative distance.
 *  Relax adjacent edges `(u, v, weight)`:
 *   If `dist[u] + weight < dist[v]`, update `dist[v]` and push `{dist[v], v}` to min-heap.
 * 
 * Time Complexity: O((V + E) log V)
 * Auxiliary Space Complexity: O(V + E)
 */
vector<long long> dijkstra(int V, const vector<vector<pair<int, int>>>& adj, int src) {
    vector<long long> dist(V, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // Stale heap entry

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// ============================================================================
// SECTION 3: BELLMAN-FORD ALGORITHM (Negative Edges & Cycle Detection)
// ============================================================================

struct Edge {
    int u, v, w;
};

/**
 * Strategy: Relax all edges `V - 1` times.
 *  If any edge can still be relaxed on the `V`-th pass, a NEGATIVE WEIGHT CYCLE exists!
 * 
 * Time Complexity: O(V * E)
 * Auxiliary Space Complexity: O(V)
 */
vector<long long> bellmanFord(int V, const vector<Edge>& edges, int src, bool& hasNegativeCycle) {
    vector<long long> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (const auto& e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // 10th pass: check for negative weight cycles
    hasNegativeCycle = false;
    for (const auto& e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    return dist;
}

// ============================================================================
// SECTION 4: FLOYD-WARSHALL ALGORITHM (All-Pairs Shortest Path)
// ============================================================================

/**
 * DP Transition:
 *  `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
 * 
 * Time Complexity: O(V^3)
 * Auxiliary Space Complexity: O(V^2)
 */
vector<vector<long long>> floydWarshall(int V, vector<vector<long long>> dist) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "  RUNNING GRAPH TRAVERSALS & SHORTEST PATH" << endl;
    cout << "==========================================" << endl;

    // Test 1: Topological Sort
    cout << "\n[Test 1] Testing Topological Sort (Kahn's)..." << endl;
    vector<vector<int>> dag = {{1}, {2}, {}};
    vector<int> topo = topologicalSortKahn(3, dag);
    assert(topo == vector<int>({0, 1, 2}));
    cout << "✓ Topological Sort Passed!" << endl;

    // Test 2: Dijkstra's Algorithm
    cout << "\n[Test 2] Testing Dijkstra's Algorithm..." << endl;
    vector<vector<pair<int, int>>> weightedGraph(4);
    weightedGraph[0].push_back({1, 4});
    weightedGraph[0].push_back({2, 1});
    weightedGraph[2].push_back({1, 2});
    weightedGraph[1].push_back({3, 1});
    weightedGraph[2].push_back({3, 5});

    vector<long long> distances = dijkstra(4, weightedGraph, 0);
    assert(distances[3] == 4); // Path: 0 -> 2 (1) -> 1 (2) -> 3 (1) = 4
    cout << "✓ Dijkstra's Algorithm Passed!" << endl;

    // Test 3: Bellman-Ford
    cout << "\n[Test 3] Testing Bellman-Ford..." << endl;
    vector<Edge> edges = {{0, 1, 4}, {0, 2, 1}, {2, 1, 2}, {1, 3, 1}};
    bool negCycle = false;
    vector<long long> bfDist = bellmanFord(4, edges, 0, negCycle);
    assert(!negCycle && bfDist[3] == 4);
    cout << "✓ Bellman-Ford Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << " ALL GRAPH TRAVERSAL & SHORTEST PATH PASSED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}
