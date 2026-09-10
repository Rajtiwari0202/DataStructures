/**
 * ============================================================================
 * PHASE 3: BINARY SEARCH ON 1D & 2D ARRAYS (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Custom Lower Bound & Upper Bound Implementation
 *  2. Search in Rotated Sorted Array (Distinct Elements)
 *  3. Find Peak Element (Local Maximum in O(log N))
 *  4. Search in 2D Matrix (Sorted flattened matrix - O(log(N*M)))
 *  5. Search in Row-wise & Column-wise Sorted Matrix (Staircase Search - O(N + M))
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

// ============================================================================
// PROBLEM 1: CUSTOM LOWER & UPPER BOUND
// ============================================================================

// First index with element >= target
int customLowerBound(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1; // Try to find smaller index on left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// First index with element > target
int customUpperBound(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// ============================================================================
// PROBLEM 2: SEARCH IN ROTATED SORTED ARRAY
// ============================================================================

/**
 * Intuition:
 *  In a rotated sorted array (e.g., [4, 5, 6, 7, 0, 1, 2]), for ANY mid point,
 *  AT LEAST ONE HALF (left half [low..mid] or right half [mid..high]) IS GUARANTEED TO BE SORTED!
 * 
 * Strategy:
 *  1. Find which half is sorted:
 *     - If `nums[low] <= nums[mid]`, left half is sorted.
 *     - Otherwise, right half is sorted.
 *  2. Check if target lies within the sorted half bounds.
 *  3. Narrow down `low` and `high` accordingly!
 * 
 * Time Complexity: O(log N)
 * Auxiliary Space Complexity: O(1)
 */
int searchRotatedSortedArray(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;

        // Check if Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1; // Target lies in left sorted half
            } else {
                low = mid + 1;  // Target lies in right half
            }
        } 
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;  // Target lies in right sorted half
            } else {
                high = mid - 1; // Target lies in left half
            }
        }
    }

    return -1;
}

// ============================================================================
// PROBLEM 3: FIND PEAK ELEMENT (Local Maxima in O(log N))
// ============================================================================

/**
 * Problem: Peak element is an element strictly greater than its neighbors.
 * Array may have multiple peaks; return index of ANY peak.
 * 
 * Intuition:
 *  If `nums[mid] < nums[mid + 1]`, we are on an INCREASING SLOPE.
 *  A peak MUST exist on the right side! Move `low = mid + 1`.
 *  Otherwise, we are on a DECREASING SLOPE or at a peak. Move `high = mid`.
 * 
 * Time Complexity: O(log N)
 * Auxiliary Space Complexity: O(1)
 */
int findPeakElement(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[mid + 1]) {
            low = mid + 1; // Climb upward slope to right
        } else {
            high = mid;    // Peak lies at mid or to the left
        }
    }

    return low;
}

// ============================================================================
// PROBLEM 4: SEARCH IN 2D MATRIX (Flattened 1D Mapping)
// ============================================================================

/**
 * Problem: Matrix of size N x M where:
 *  - Each row is sorted.
 *  - First element of each row > last element of previous row.
 * 
 * Solution: Virtual 1D Array Mapping:
 *  `row = mid / M`, `col = mid % M`.
 * 
 * Time Complexity: O(log(N * M))
 * Auxiliary Space Complexity: O(1)
 */
bool searchMatrix2D(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0, high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int r = mid / cols;
        int c = mid % cols;

        if (matrix[r][c] == target) return true;
        else if (matrix[r][c] < target) low = mid + 1;
        else high = mid - 1;
    }

    return false;
}

// ============================================================================
// PROBLEM 5: SEARCH IN ROW & COLUMN SORTED MATRIX (Staircase Search)
// ============================================================================

/**
 * Matrix property: Rows are sorted left-to-right, columns are sorted top-to-bottom.
 * 
 * Strategy: Start at TOP-RIGHT Corner (row = 0, col = M - 1).
 *  - If `matrix[r][c] == target`: Found!
 *  - If `matrix[r][c] > target`: Target must be smaller $\implies$ move LEFT (`col--`).
 *  - If `matrix[r][c] < target`: Target must be larger $\implies$ move DOWN (`row++`).
 * 
 * Time Complexity: O(N + M)
 * Auxiliary Space Complexity: O(1)
 */
bool searchMatrixStaircase(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int r = 0;
    int c = matrix[0].size() - 1;

    while (r < matrix.size() && c >= 0) {
        if (matrix[r][c] == target) return true;
        else if (matrix[r][c] > target) c--; // Move left
        else r++;                           // Move down
    }

    return false;
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING 1D & 2D BINARY SEARCH TESTS    " << endl;
    cout << "==========================================" << endl;

    // Test 1: Lower & Upper Bound
    cout << "\n[Test 1] Testing Lower & Upper Bounds..." << endl;
    vector<int> sortedArr = {1, 2, 4, 4, 4, 6, 8};
    assert(customLowerBound(sortedArr, 4) == 2); // First 4 is at index 2
    assert(customUpperBound(sortedArr, 4) == 5); // First element > 4 is 6 at index 5
    cout << "✓ Lower Bound & Upper Bound Passed!" << endl;

    // Test 2: Search in Rotated Sorted Array
    cout << "\n[Test 2] Testing Rotated Sorted Array Search..." << endl;
    vector<int> rotatedArr = {4, 5, 6, 7, 0, 1, 2};
    assert(searchRotatedSortedArray(rotatedArr, 0) == 4);
    assert(searchRotatedSortedArray(rotatedArr, 3) == -1);
    cout << "✓ Rotated Sorted Array Search Passed!" << endl;

    // Test 3: Find Peak Element
    cout << "\n[Test 3] Testing Find Peak Element..." << endl;
    vector<int> peakArr = {1, 2, 1, 3, 5, 6, 4};
    int peakIndex = findPeakElement(peakArr);
    cout << "Peak element found at index: " << peakIndex << " (Value = " << peakArr[peakIndex] << ")" << endl;
    assert(peakIndex == 1 || peakIndex == 5); // 2 or 6 are peaks
    cout << "✓ Find Peak Element Passed!" << endl;

    // Test 4: Search 2D Matrix (Flattened)
    cout << "\n[Test 4] Testing 2D Matrix Search (Flattened)..." << endl;
    vector<vector<int>> mat1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    assert(searchMatrix2D(mat1, 3) == true);
    assert(searchMatrix2D(mat1, 13) == false);
    cout << "✓ 2D Matrix Search Passed!" << endl;

    // Test 5: Search Row-Col Sorted Matrix (Staircase)
    cout << "\n[Test 5] Testing Staircase Search..." << endl;
    vector<vector<int>> mat2 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24}
    };
    assert(searchMatrixStaircase(mat2, 5) == true);
    assert(searchMatrixStaircase(mat2, 20) == false);
    cout << "✓ Staircase Search Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << "  ALL 1D & 2D BINARY SEARCH TESTS PASSED! " << endl;
    cout << "==========================================" << endl;

    return 0;
}
