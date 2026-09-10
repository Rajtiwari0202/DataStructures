/**
 * ============================================================================
 * PHASE 3: BINARY SEARCH ON SEARCH SPACE (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Book Allocation Problem (Minimize Maximum Pages)
 *  2. Aggressive Cows Problem (Maximize Minimum Distance)
 *  3. K-th Element of Two Sorted Arrays (Partition Cut Technique in O(log(min(N,M))))
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ============================================================================
// PROBLEM 1: BOOK ALLOCATION PROBLEM
// ============================================================================

/**
 * Problem: Given array `books` where `books[i]` is page count, allocate ALL books 
 * to `m` students such that:
 *  - Each student gets contiguous books.
 *  - Maximum pages allocated to any student is MINIMIZED.
 * 
 * Monotonic Search Space:
 *  - Range: `low = max(books)`, `high = sum(books)`.
 *  - Predicate `isPossible(maxPageLimit)`:
 *    Checks if we can allocate books to <= `m` students such that no student gets > `maxPageLimit` pages.
 * 
 * Time Complexity: O(N log(sum(books) - max(books)))
 * Auxiliary Space Complexity: O(1)
 */
bool isPossibleBookAllocation(const vector<int>& books, int m, long long maxPageLimit) {
    int studentsCount = 1;
    long long pagesAssigned = 0;

    for (int page : books) {
        if (pagesAssigned + page <= maxPageLimit) {
            pagesAssigned += page;
        } else {
            studentsCount++;
            pagesAssigned = page;
        }
    }

    return studentsCount <= m;
}

long long findPagesBookAllocation(const vector<int>& books, int m) {
    if (m > books.size()) return -1; // Not enough books for each student

    long long low = *max_element(books.begin(), books.end());
    long long high = accumulate(books.begin(), books.end(), 0LL);
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossibleBookAllocation(books, m, mid)) {
            ans = mid;         // Candidate maximum pages found
            high = mid - 1;    // Try to find a smaller maximum limit
        } else {
            low = mid + 1;     // Increase capacity limit
        }
    }

    return ans;
}

// ============================================================================
// PROBLEM 2: AGGRESSIVE COWS PROBLEM
// ============================================================================

/**
 * Problem: Place `c` cows in `stalls` array such that MINIMUM distance between 
 * any two cows is MAXIMIZED.
 * 
 * Monotonic Search Space:
 *  - Sort stalls first!
 *  - Range: `low = 1`, `high = stalls[N-1] - stalls[0]`.
 *  - Predicate `canPlaceCows(minDist)`:
 *    Greedily place cows: first cow at stall 0. Place next cow at stall `i` 
 *    if `stalls[i] - lastPosition >= minDist`.
 * 
 * Time Complexity: O(N log N + N log(maxDist))
 * Auxiliary Space Complexity: O(1)
 */
bool canPlaceCows(const vector<int>& stalls, int c, int minDist) {
    int countCows = 1;
    int lastPosition = stalls[0];

    for (size_t i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPosition >= minDist) {
            countCows++;
            lastPosition = stalls[i];
            if (countCows >= c) return true;
        }
    }

    return countCows >= c;
}

int aggressiveCows(vector<int>& stalls, int c) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, c, mid)) {
            ans = mid;        // Valid distance, try to maximize further
            low = mid + 1;
        } else {
            high = mid - 1;   // Distance too large, decrease distance
        }
    }

    return ans;
}

// ============================================================================
// PROBLEM 3: K-TH ELEMENT OF TWO SORTED ARRAYS (O(log(min(N, M))))
// ============================================================================

/**
 * Problem: Given two sorted arrays A (size N) and B (size M), find the K-th smallest element 
 * of the merged sorted array without merging!
 * 
 * Optimal Strategy: Partitioning Binary Search!
 *  Cut array A at index `cut1` (0 to N).
 *  Cut array B at index `cut2 = K - cut1`.
 * 
 *  Condition for valid partition:
 *   left1 <= right2  &&  left2 <= right1
 * 
 * Time Complexity: O(log(min(N, M)))
 * Auxiliary Space Complexity: O(1)
 */
int kthElementTwoSortedArrays(const vector<int>& nums1, const vector<int>& nums2, int k) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    // Ensure nums1 is the smaller array to minimize search space
    if (n1 > n2) return kthElementTwoSortedArrays(nums2, nums1, k);

    int low = max(0, k - n2);
    int high = min(k, n1);

    while (low <= high) {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if (left1 > right2) {
            high = cut1 - 1; // Take fewer elements from nums1
        } else {
            low = cut1 + 1;  // Take more elements from nums1
        }
    }

    return -1;
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "  RUNNING SEARCH SPACE BINARY SEARCH TESTS" << endl;
    cout << "==========================================" << endl;

    // Test 1: Book Allocation Problem
    cout << "\n[Test 1] Testing Book Allocation Problem..." << endl;
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    long long minMaxPages = findPagesBookAllocation(books, students);
    cout << "Minimum Maximum Pages for 2 students: " << minMaxPages << endl;
    assert(minMaxPages == 113); // Student 1: {12, 34, 67}=113, Student 2: {90}=90
    cout << "✓ Book Allocation Passed!" << endl;

    // Test 2: Aggressive Cows
    cout << "\n[Test 2] Testing Aggressive Cows..." << endl;
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    int maxMinDist = aggressiveCows(stalls, cows);
    cout << "Maximum Minimum Distance for 3 cows: " << maxMinDist << endl;
    assert(maxMinDist == 3); // Place cows at stalls 1, 4, 8 -> Distances 3, 4 -> Min = 3
    cout << "✓ Aggressive Cows Passed!" << endl;

    // Test 3: K-th Element of Two Sorted Arrays
    cout << "\n[Test 3] Testing K-th Element of Two Sorted Arrays..." << endl;
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;
    int kthVal = kthElementTwoSortedArrays(arr1, arr2, k);
    cout << "5th smallest element of merged array: " << kthVal << endl;
    assert(kthVal == 6); // Merged: [1, 2, 3, 4, 6, 7, 8, 9, 10] -> 5th element is 6
    cout << "✓ K-th Element Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << " ALL SEARCH SPACE BINARY SEARCH TESTS PASSED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}
