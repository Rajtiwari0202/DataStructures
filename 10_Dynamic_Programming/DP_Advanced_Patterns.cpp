/**
 * ============================================================================
 * PHASE 10: ADVANCED DYNAMIC PROGRAMMING PATTERNS (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Matrix Chain Multiplication (MCM) Interval DP (O(N^3))
 *  2. Burst Balloons (Interval DP Hard)
 *  3. DP on Trees: Maximum Path Sum in Binary Tree
 *  4. DP with Bitmasking: Travelling Salesperson Problem (TSP - O(2^N * N^2))
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ============================================================================
// PATTERN 1: MATRIX CHAIN MULTIPLICATION (MCM) - INTERVAL DP
// ============================================================================

/**
 * Problem: Given dimensions array `arr`, find min scalar multiplications to multiply matrices.
 * Matrix `i` has dimension `arr[i-1] x arr[i]`.
 * 
 * Recurrence:
 *  `dp[i][j] = min_{k=i}^{j-1} (dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j])`
 * 
 * Time Complexity: O(N^3) | Auxiliary Space: O(N^2)
 */
int matrixChainOrder(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // len is chain length
    for (int len = 2; len < n; ++len) {
        for (int i = 1; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

// ============================================================================
// PATTERN 2: BURST BALLOONS (Hard Interval DP)
// ============================================================================

/**
 * Recurrence (Thinking in Reverse: balloon `k` is the LAST balloon burst in range [i, j]):
 *  `dp[i][j] = max_{k=i}^{j} (dp[i][k-1] + dp[k+1][j] + nums[i-1] * nums[k] * nums[j+1])`
 * 
 * Time Complexity: O(N^3) | Space Complexity: O(N^2)
 */
int maxCoinsBurstBalloons(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            for (int k = i; k <= j; ++k) {
                int coins = dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1];
                dp[i][j] = max(dp[i][j], coins);
            }
        }
    }

    return dp[1][n];
}

// ============================================================================
// PATTERN 3: DP WITH BITMASKING - TRAVELLING SALESPERSON PROBLEM (TSP)
// ============================================================================

/**
 * Problem: Find min cost route visiting all N cities starting and ending at city 0.
 * 
 * State Representation:
 *  `dp[mask][u]` = Min cost to visit unvisited cities in `mask` ending at city `u`.
 *  `mask` is an N-bit integer where i-th bit = 1 if city i has been visited.
 * 
 * Recurrence:
 *  `dp[mask][u] = min_{v: bit v not in mask} (dist[u][v] + dp[mask | (1 << v)][v])`
 * 
 * Time Complexity: O(2^N * N^2) | Space Complexity: O(2^N * N)
 */
int tspHelper(int mask, int u, int n, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
    if (mask == (1 << n) - 1) {
        return dist[u][0]; // Return to start city 0
    }

    if (memo[mask][u] != -1) return memo[mask][u];

    int ans = 1e9;
    for (int v = 0; v < n; ++v) {
        if (!(mask & (1 << v))) { // City v not visited yet
            int nextCost = dist[u][v] + tspHelper(mask | (1 << v), v, n, dist, memo);
            ans = min(ans, nextCost);
        }
    }

    return memo[mask][u] = ans;
}

int tsp(const vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<int>> memo(1 << n, vector<int>(n, -1));
    return tspHelper(1, 0, n, dist, memo); // Start at city 0 with mask = 0...0001
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING ADVANCED DYNAMIC PROGRAMMING   " << endl;
    cout << "==========================================" << endl;

    // Test 1: MCM
    cout << "\n[Test 1] Testing Matrix Chain Multiplication..." << endl;
    vector<int> dimensions = {10, 20, 30, 40, 30};
    int minOps = matrixChainOrder(dimensions);
    cout << "Min Scalar Multiplications: " << minOps << endl;
    assert(minOps == 30000);
    cout << "✓ MCM Passed!" << endl;

    // Test 2: Burst Balloons
    cout << "\n[Test 2] Testing Burst Balloons..." << endl;
    vector<int> balloons = {3, 1, 5, 8};
    int maxCoins = maxCoinsBurstBalloons(balloons);
    cout << "Max Coins for [3, 1, 5, 8]: " << maxCoins << endl;
    assert(maxCoins == 167);
    cout << "✓ Burst Balloons Passed!" << endl;

    // Test 3: TSP DP + Bitmasking
    cout << "\n[Test 3] Testing TSP (DP + Bitmasking)..." << endl;
    vector<vector<int>> distMatrix = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };
    int minTSPCost = tsp(distMatrix);
    cout << "Min TSP Tour Cost: " << minTSPCost << endl;
    assert(minTSPCost == 85); // Tour: 0 -> 1 -> 2 -> 3 -> 0 = 20 + 30 + 10 + 25 = 85
    cout << "✓ TSP DP + Bitmasking Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << " ALL ADVANCED DYNAMIC PROGRAMMING PASSED! " << endl;
    cout << "==========================================" << endl;

    return 0;
}
