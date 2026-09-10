/**
 * ============================================================================
 * PHASE 2: PREFIX SUM & DIFFERENCE ARRAY MASTERY (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. 1D Prefix Sum: Subarray Sum Equals K (Hash Map Optimization)
 *  2. Difference Array Technique: Range Addition in O(1) per update
 *  3. 2D Prefix Sum: Submatrix Range Sum Query in O(1) time
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

// ============================================================================
// PROBLEM 1: SUBARRAY SUM EQUALS K (Count Subarrays with Sum K)
// ============================================================================

/**
 * Intuition & Proof:
 *  Let prefixSum[i] = sum of elements from index 0 to i.
 *  Subarray sum from index (j + 1) to i = prefixSum[i] - prefixSum[j].
 *  We want: prefixSum[i] - prefixSum[j] = K  =>  prefixSum[j] = prefixSum[i] - K.
 * 
 *  Therefore, at index `i`, we check how many times `prefixSum[i] - K` has appeared 
 *  previously in our prefix sum frequency hash map!
 * 
 * Base Case: `prefixMap[0] = 1` (Handles subarrays starting at index 0).
 * 
 * Time Complexity: O(N)
 * Auxiliary Space Complexity: O(N)
 */
int subarraySumEqualsK(const vector<int>& nums, int k) {
    unordered_map<long long, int> prefixFreq;
    prefixFreq[0] = 1; // Base case: prefix sum of 0 appears once before array start

    long long currentPrefixSum = 0;
    int count = 0;

    for (int num : nums) {
        currentPrefixSum += num;

        long long target = currentPrefixSum - k;
        if (prefixFreq.find(target) != prefixFreq.end()) {
            count += prefixFreq[target];
        }

        prefixFreq[currentPrefixSum]++;
    }

    return count;
}

// ============================================================================
// PROBLEM 2: DIFFERENCE ARRAY (O(1) Range Addition Updates)
// ============================================================================

/**
 * Problem: Given an initial array of size N (all 0s), perform Q updates:
 *  Add `val` to range [L, R].
 * 
 * Redundancy in Plain Loop: Updating range [L, R] takes O(R - L + 1) = O(N) -> O(Q * N).
 * 
 * Difference Array Insight:
 *  Maintain diff array `D` where `D[i] = A[i] - A[i-1]`.
 *  To add `val` to range [L, R]:
 *    - Add `val` to `D[L]`  (Increases all prefix sums from L onwards).
 *    - Subtract `val` from `D[R + 1]` (Cancels the increase from R+1 onwards).
 * 
 * Final Array Reconstruction: Compute prefix sum of difference array!
 * 
 * Time Complexity: O(Q + N)
 * Auxiliary Space Complexity: O(N)
 */
class DifferenceArray {
    vector<long long> diff;
    int n;

public:
    DifferenceArray(int size) : n(size), diff(size + 1, 0) {}

    // Range addition update [L, R] in O(1)
    void updateRange(int L, int R, long long val) {
        diff[L] += val;
        if (R + 1 < n) {
            diff[R + 1] -= val;
        }
    }

    // Reconstruct original array via prefix sums in O(N)
    vector<long long> getFinalArray() {
        vector<long long> result(n, 0);
        long long currentSum = 0;
        for (int i = 0; i < n; ++i) {
            currentSum += diff[i];
            result[i] = currentSum;
        }
        return result;
    }
};

// ============================================================================
// PROBLEM 3: 2D PREFIX SUM (Submatrix Range Sum Queries in O(1))
// ============================================================================

/**
 * Problem: Given 2D Matrix, query sum of submatrix with top-left (r1, c1) and bottom-right (r2, c2).
 * 
 * Preprocessing (2D Inclusion-Exclusion):
 *  prefix[r][c] = matrix[r-1][c-1] + prefix[r-1][c] + prefix[r][c-1] - prefix[r-1][c-1]
 * 
 * Query Formula:
 *  sum(r1, c1, r2, c2) = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1]
 * 
 * Time Complexity: O(N * M) Preprocessing, O(1) per Query
 * Auxiliary Space Complexity: O(N * M)
 */
class NumMatrix2D {
    vector<vector<long long>> prefix2D;

public:
    NumMatrix2D(const vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix2D.assign(rows + 1, vector<long long>(cols + 1, 0));

        for (int r = 1; r <= rows; ++r) {
            for (int c = 1; c <= cols; ++c) {
                prefix2D[r][c] = matrix[r - 1][c - 1]
                               + prefix2D[r - 1][c]
                               + prefix2D[r][c - 1]
                               - prefix2D[r - 1][c - 1];
            }
        }
    }

    long long sumRegion(int r1, int c1, int r2, int c2) {
        return prefix2D[r2 + 1][c2 + 1]
             - prefix2D[r1][c2 + 1]
             - prefix2D[r2 + 1][c1]
             + prefix2D[r1][c1];
    }
};

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING PREFIX SUM TEST SUITE          " << endl;
    cout << "==========================================" << endl;

    // Test 1: Subarray Sum Equals K
    cout << "\n[Test 1] Testing Subarray Sum Equals K..." << endl;
    vector<int> nums1 = {1, 1, 1};
    int count1 = subarraySumEqualsK(nums1, 2);
    cout << "Subarrays with sum 2 in {1, 1, 1}: " << count1 << endl;
    assert(count1 == 2);

    vector<int> nums2 = {1, -1, 0};
    int count2 = subarraySumEqualsK(nums2, 0);
    cout << "Subarrays with sum 0 in {1, -1, 0}: " << count2 << endl;
    assert(count2 == 3); // {1, -1}, {0}, {1, -1, 0}
    cout << "✓ Subarray Sum Equals K Passed!" << endl;

    // Test 2: Difference Array
    cout << "\n[Test 2] Testing Difference Array (Range Updates)..." << endl;
    DifferenceArray diffArr(5);
    diffArr.updateRange(1, 3, 10); // Add 10 to indices 1, 2, 3
    diffArr.updateRange(2, 4, 5);  // Add 5 to indices 2, 3, 4
    vector<long long> finalArr = diffArr.getFinalArray();
    vector<long long> expectedDiff = {0, 10, 15, 15, 5};
    cout << "Final Array after updates: ";
    for (long long x : finalArr) cout << x << " ";
    cout << endl;
    assert(finalArr == expectedDiff);
    cout << "✓ Difference Array Passed!" << endl;

    // Test 3: 2D Prefix Sum
    cout << "\n[Test 3] Testing 2D Matrix Range Sum Query..." << endl;
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix2D numMatrix(matrix);
    long long region1 = numMatrix.sumRegion(2, 1, 4, 3);
    cout << "Submatrix Sum (2,1) to (4,3): " << region1 << endl;
    assert(region1 == 8);

    long long region2 = numMatrix.sumRegion(1, 1, 2, 2);
    cout << "Submatrix Sum (1,1) to (2,2): " << region2 << endl;
    assert(region2 == 11);
    cout << "✓ 2D Prefix Sum Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << "     ALL PREFIX SUM TESTS PASSED!         " << endl;
    cout << "==========================================" << endl;

    return 0;
}
