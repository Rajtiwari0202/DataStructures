/**
 * ============================================================================
 * PHASE 10: CORE DYNAMIC PROGRAMMING PATTERNS (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. 1D DP: House Robber (O(N) Time, O(1) Space)
 *  2. 0/1 & Unbounded Knapsack: Coin Change I (Min Coins) & Coin Change II (Total Ways)
 *  3. String DP: Longest Common Subsequence (LCS) & Edit Distance
 *  4. LIS Pattern: Longest Increasing Subsequence in O(N log N) via Binary Search
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ============================================================================
// PATTERN 1: 1D DP - HOUSE ROBBER (Space Optimized O(1))
// ============================================================================

/**
 * Recurrence:
 *  dp[i] = max(dp[i-1], nums[i] + dp[i-2])
 * 
 * Space Optimization: Only need `prev1` (dp[i-1]) and `prev2` (dp[i-2]).
 */
int robHouse(const vector<int>& nums) {
    if (nums.empty()) return 0;
    int prev2 = 0;
    int prev1 = 0;

    for (int num : nums) {
        int current = max(prev1, num + prev2);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

// ============================================================================
// PATTERN 2: UNBOUNDED KNAPSACK - COIN CHANGE I (Min Coins to make Sum)
// ============================================================================

/**
 * Recurrence:
 *  dp[amount] = min(dp[amount], 1 + dp[amount - coin])
 * 
 * Time Complexity: O(N * Amount) | Auxiliary Space: O(Amount)
 */
int coinChangeMin(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

// ============================================================================
// PATTERN 3: STRING DP - LONGEST COMMON SUBSEQUENCE (LCS)
// ============================================================================

/**
 * Recurrence:
 *  If text1[i-1] == text2[j-1]: dp[i][j] = 1 + dp[i-1][j-1]
 *  Else:                       dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 * 
 * Time Complexity: O(N * M) | Auxiliary Space: O(M) (Space Optimized)
 */
int longestCommonSubsequence(const string& text1, const string& text2) {
    int n = text1.length();
    int m = text2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
            } else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}

// ============================================================================
// PATTERN 4: EDIT DISTANCE (Levenshtein Distance)
// ============================================================================

/**
 * Recurrence:
 *  If s1[i-1] == s2[j-1]: dp[i][j] = dp[i-1][j-1]
 *  Else:                 dp[i][j] = 1 + min({
 *                           dp[i-1][j],   // Delete
 *                           dp[i][j-1],   // Insert
 *                           dp[i-1][j-1]  // Replace
 *                        })
 * 
 * Time Complexity: O(N * M) | Space Complexity: O(N * M)
 */
int minDistanceEdit(const string& word1, const string& word2) {
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[n][m];
}

// ============================================================================
// PATTERN 5: LONGEST INCREASING SUBSEQUENCE (O(N log N) Patience Sorting)
// ============================================================================

/**
 * Strategy: Maintain `temp` vector storing active tail elements.
 *  For each `num`:
 *   If `num` > `temp.back()`: append `num` to `temp`.
 *   Else: replace first element in `temp` >= `num` using `std::lower_bound`!
 * 
 * Time Complexity: O(N log N) | Auxiliary Space: O(N)
 */
int lengthOfLIS(const vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> temp;

    for (int num : nums) {
        auto it = lower_bound(temp.begin(), temp.end(), num);
        if (it == temp.end()) {
            temp.push_back(num);
        } else {
            *it = num;
        }
    }

    return temp.size();
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING CORE DYNAMIC PROGRAMMING TESTS " << endl;
    cout << "==========================================" << endl;

    // Test 1: House Robber
    cout << "\n[Test 1] Testing House Robber..." << endl;
    vector<int> houses = {2, 7, 9, 3, 1};
    assert(robHouse(houses) == 12); // Rob 2 + 9 + 1 = 12
    cout << "✓ House Robber Passed!" << endl;

    // Test 2: Coin Change I
    cout << "\n[Test 2] Testing Coin Change Min Coins..." << endl;
    vector<int> coins = {1, 2, 5};
    assert(coinChangeMin(coins, 11) == 3); // 5 + 5 + 1 = 11
    cout << "✓ Coin Change Passed!" << endl;

    // Test 3: LCS
    cout << "\n[Test 3] Testing LCS..." << endl;
    assert(longestCommonSubsequence("abcde", "ace") == 3); // "ace"
    cout << "✓ LCS Passed!" << endl;

    // Test 4: Edit Distance
    cout << "\n[Test 4] Testing Edit Distance..." << endl;
    assert(minDistanceEdit("horse", "ros") == 3);
    cout << "✓ Edit Distance Passed!" << endl;

    // Test 5: LIS O(N log N)
    cout << "\n[Test 5] Testing LIS O(N log N)..." << endl;
    vector<int> lisArr = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(lengthOfLIS(lisArr) == 4); // [2, 3, 7, 101] or [2, 5, 7, 101]
    cout << "✓ LIS O(N log N) Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << " ALL CORE DYNAMIC PROGRAMMING TESTS PASSED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}
