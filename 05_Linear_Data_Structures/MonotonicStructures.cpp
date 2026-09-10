/**
 * ============================================================================
 * PHASE 5: MONOTONIC STACK & MONOTONIC QUEUE (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Next Greater Element I & II (Circular Array)
 *  2. Largest Rectangle in Histogram (O(N) Monotonic Stack)
 *  3. Sliding Window Maximum (O(N) Monotonic Deque)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <cassert>

using namespace std;

// ============================================================================
// PROBLEM 1: NEXT GREATER ELEMENT II (Circular Array)
// ============================================================================

/**
 * Strategy:
 *  Simulate circular array by iterating from `2N - 1` down to `0`.
 *  Maintain MONOTONIC DECREASING STACK storing elements.
 *  Pop elements from stack while `st.top() <= nums[i % N]`.
 * 
 * Time Complexity: O(N) (Each element pushed/popped at most twice)
 * Auxiliary Space Complexity: O(N)
 */
vector<int> nextGreaterElementsCircular(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        if (i < n && !st.empty()) {
            result[i] = st.top();
        }
        st.push(nums[i % n]);
    }

    return result;
}

// ============================================================================
// PROBLEM 2: LARGEST RECTANGLE IN HISTOGRAM
// ============================================================================

/**
 * Problem: Given histogram heights, find max rectangle area.
 * 
 * Intuition:
 *  For any bar `i` with height `H`, the rectangle can extend left until a bar < `H` is found,
 *  and right until a bar < `H` is found.
 * 
 * Monotonic Increasing Stack Approach:
 *  Store indices in stack. Maintain increasing height property.
 *  When `heights[i] < heights[st.top()]`:
 *   Pop `h = heights[st.top()]`.
 *   Width = `st.empty() ? i : (i - st.top() - 1)`.
 *   Area = `h * width`.
 * 
 * Time Complexity: O(N)
 * Auxiliary Space Complexity: O(N)
 */
int largestRectangleArea(const vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; ++i) {
        int currentHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] > currentHeight) {
            int h = heights[st.top()];
            st.pop();

            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }

    return maxArea;
}

// ============================================================================
// PROBLEM 3: SLIDING WINDOW MAXIMUM
// ============================================================================

/**
 * Problem: Find max element in every sliding window of size K.
 * 
 * Strategy: Monotonic Decreasing Deque storing INDICES!
 *  - Remove elements outside window `(dq.front() <= i - K)`.
 *  - Maintain decreasing order by popping smaller elements from back `(nums[dq.back()] <= nums[i])`.
 *  - `dq.front()` ALWAYS holds index of max element in current window!
 * 
 * Time Complexity: O(N) (Each element pushed/popped at most once)
 * Auxiliary Space Complexity: O(K)
 */
vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        // 1. Remove indices outside window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2. Maintain Monotonic Decreasing order in deque
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // 3. Add to result when window reaches size K
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING MONOTONIC STRUCTURES TESTS     " << endl;
    cout << "==========================================" << endl;

    // Test 1: Next Greater Element II
    cout << "\n[Test 1] Testing Next Greater Element II..." << endl;
    vector<int> nums1 = {1, 2, 1};
    vector<int> nge = nextGreaterElementsCircular(nums1);
    assert(nge == vector<int>({2, -1, 2}));
    cout << "✓ Next Greater Element II Passed!" << endl;

    // Test 2: Largest Rectangle in Histogram
    cout << "\n[Test 2] Testing Largest Rectangle in Histogram..." << endl;
    vector<int> hist = {2, 1, 5, 6, 2, 3};
    int maxRect = largestRectangleArea(hist);
    cout << "Largest Rectangle Area: " << maxRect << endl;
    assert(maxRect == 10); // Bars 5 & 6 forming height 5, width 2
    cout << "✓ Largest Rectangle in Histogram Passed!" << endl;

    // Test 3: Sliding Window Maximum
    cout << "\n[Test 3] Testing Sliding Window Maximum..." << endl;
    vector<int> nums2 = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> maxWin = maxSlidingWindow(nums2, 3);
    vector<int> expectedWin = {3, 3, 5, 5, 6, 7};
    assert(maxWin == expectedWin);
    cout << "✓ Sliding Window Maximum Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << " ALL MONOTONIC STRUCTURES TESTS PASSED!   " << endl;
    cout << "==========================================" << endl;

    return 0;
}
