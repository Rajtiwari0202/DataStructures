/**
 * ============================================================================
 * PHASE 9: ADVANCED GRAPH ALGORITHMS (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Disjoint Set Union (DSU) with Path Compression & Rank/Size
 *  2. Kruskal's Minimum Spanning Tree (MST) Algorithm
 *  3. Tarjan's Algorithm for Bridges & Articulation Points
 *  4. Kosaraju's Algorithm for Strongly Connected Components (SCC)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>

using namespace std;

// ============================================================================
// SECTION 1: DISJOINT SET UNION (DSU)
// ============================================================================

class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    // Find with Path Compression: Amortized O(α(N)) ≈ O(1)
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Compress path directly to root
    }

    // Union by Rank: O(α(N))
    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI == rootJ) return false; // Already in same set (Cycle!)

        if (rank[rootI] < rank[rootJ]) {
            parent[rootI] = rootJ;
        } else if (rank[rootI] > rank[rootJ]) {
            parent[rootJ] = rootI;
        } else {
            parent[rootJ] = rootI;
            rank[rootI]++;
        }
        return true;
    }
};

// ============================================================================
// SECTION 2: KRUSKAL'S MINIMUM SPANNING TREE (MST)
// ============================================================================

struct MSTEdge {
    int u, v, weight;
    bool operator<(const MSTEdge& other) const {
        return weight < other.weight;
    }
};

long long kruskalMST(int V, vector<MSTEdge>& edges, vector<MSTEdge>& mstEdges) {
    sort(edges.begin(), edges.end()); // O(E log E)
    DSU dsu(V);

    long long totalWeight = 0;
    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            totalWeight += edge.weight;
            mstEdges.push_back(edge);
            if (mstEdges.size() == V - 1) break;
        }
    }

    return mstEdges.size() == V - 1 ? totalWeight : -1;
}

// ============================================================================
// SECTION 3: TARJAN'S ALGORITHM FOR BRIDGES IN GRAPH
// ============================================================================

/**
 * Intuition:
 *  `tin[u]` = Insertion time of node `u`.
 *  `low[u]` = Lowest insertion time reachable from `u` (using back-edges).
 *  An edge `(u, v)` is a BRIDGE if `low[v] > tin[u]` (No back-edge from `v` subtree to `u` or above).
 * 
 * Time Complexity: O(V + E)
 */
void tarjanBridgesDFS(int u, int p, int& timer, vector<int>& tin, vector<int>& low, 
                      const vector<vector<int>>& adj, vector<pair<int, int>>& bridges) {
    tin[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == p) continue;

        if (tin[v]) { // Back-edge found!
            low[u] = min(low[u], tin[v]);
        } else {
            tarjanBridgesDFS(v, u, timer, tin, low, adj, bridges);
            low[u] = min(low[u], low[v]);

            if (low[v] > tin[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        }
    }
}

vector<pair<int, int>> findBridgesTarjan(int V, const vector<vector<int>>& adj) {
    vector<int> tin(V, 0), low(V, 0);
    vector<pair<int, int>> bridges;
    int timer = 0;

    for (int i = 0; i < V; ++i) {
        if (!tin[i]) {
            tarjanBridgesDFS(i, -1, timer, tin, low, adj, bridges);
        }
    }
    return bridges;
}

// ============================================================================
// SECTION 4: KOSARAJU'S ALGORITHM FOR STRONGLY CONNECTED COMPONENTS (SCC)
// ============================================================================

/**
 * Algorithm:
 *  1. Perform DFS on original graph to get finishing times (Stack order).
 *  2. Reverse all edges in the graph (Transpose Graph).
 *  3. Pop elements from stack and perform DFS on transposed graph to extract SCCs!
 * 
 * Time Complexity: O(V + E)
 */
void kosarajuDFS1(int u, vector<bool>& visited, const vector<vector<int>>& adj, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) kosarajuDFS1(v, visited, adj, st);
    }
    st.push(u); // Push node to stack after processing all descendants
}

void kosarajuDFS2(int u, vector<bool>& visited, const vector<vector<int>>& adjT, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : adjT[u]) {
        if (!visited[v]) kosarajuDFS2(v, visited, adjT, component);
    }
}

vector<vector<int>> kosarajuSCC(int V, const vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(V, false);

    // Step 1: Fill stack according to finish times
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) kosarajuDFS1(i, visited, adj, st);
    }

    // Step 2: Transpose Graph
    vector<vector<int>> adjT(V);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            adjT[v].push_back(u);
        }
    }

    // Step 3: DFS on Transposed Graph according to stack order
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            vector<int> component;
            kosarajuDFS2(u, visited, adjT, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING ADVANCED GRAPH ALGORITHMS TESTS" << endl;
    cout << "==========================================" << endl;

    // Test 1: Kruskal's MST
    cout << "\n[Test 1] Testing Kruskal's MST..." << endl;
    vector<MSTEdge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    vector<MSTEdge> mst;
    long long mstWeight = kruskalMST(4, edges, mst);
    cout << "MST Weight: " << mstWeight << endl;
    assert(mstWeight == 19); // Edges: (2,3:4), (0,3:5), (0,1:10) -> Sum = 19
    cout << "✓ Kruskal's MST Passed!" << endl;

    // Test 2: Tarjan's Bridges
    cout << "\n[Test 2] Testing Tarjan's Bridges..." << endl;
    vector<vector<int>> graph(4);
    graph[0] = {1, 2}; graph[1] = {0, 2}; graph[2] = {0, 1, 3}; graph[3] = {2};
    vector<pair<int, int>> bridges = findBridgesTarjan(4, graph);
    assert(bridges.size() == 1 && bridges[0] == make_pair(2, 3));
    cout << "✓ Tarjan's Bridges Passed!" << endl;

    // Test 3: Kosaraju's SCC
    cout << "\n[Test 3] Testing Kosaraju's SCC..." << endl;
    vector<vector<int>> dirGraph(5);
    dirGraph[1] = {0}; dirGraph[0] = {2, 3}; dirGraph[2] = {1}; dirGraph[3] = {4};
    vector<vector<int>> sccs = kosarajuSCC(5, dirGraph);
    cout << "Total SCCs found: " << sccs.size() << endl;
    assert(sccs.size() == 3); // {0, 1, 2}, {3}, {4}
    cout << "✓ Kosaraju's SCC Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << " ALL ADVANCED GRAPH ALGORITHMS PASSED!    " << endl;
    cout << "==========================================" << endl;

    return 0;
}
