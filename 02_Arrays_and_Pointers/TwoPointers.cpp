/**
 * ============================================================================
 * PHASE 2: TWO POINTERS MASTERY (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Opposite Direction Pointers: 2-Sum (Sorted), 3-Sum (Sorting + Pointers), Container With Most Water
 *  2. Trapping Rain Water:
 *     - Brute Force: O(N^2)
 *     - Better (Prefix/Suffix Arrays): O(N) Time, O(N) Space
 *     - Optimal (Two Pointers): O(N) Time, O(1) Space
 *  3. Fast & Slow Pointers: Move Zeroes, Remove Duplicates from Sorted Array
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

// ============================================================================
// PROBLEM 1: 3-SUM (Find all unique triplets that sum to 0)
// ============================================================================

/**
 * Intuition & Redundancy Breakdown:
 *  - Brute Force: 3 nested loops -> O(N³) time. Check uniqueness via set -> O(N³ log N).
 *  - Better: Hash Map for 3rd element -> O(N²) time, O(N) space.
 *  - Optimal: Sort array + Two Pointers!
 *    Fix `i` from 0 to N-3. Use two pointers `left = i + 1` and `right = N - 1`.
 *    Skip duplicate values for `i`, `left`, and `right` to guarantee unique triplets.
 * 
 * Time Complexity: O(N log N + N²) = O(N²)
 * Auxiliary Space Complexity: O(1) (ignoring output vector)
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;

    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicate anchor elements
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;
        int target = -nums[i];

        while (left < right) {
            int currentSum = nums[left] + nums[right];

            if (currentSum == target) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicate left and right elements
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (currentSum < target) {
                left++; // Increase sum
            } else {
                right--; // Decrease sum
            }
        }
    }

    return result;
}

// ============================================================================
// PROBLEM 2: TRAPPING RAIN WATER
// ============================================================================

/**
 * Problem: Given elevation map of non-negative integers, compute trapped rainwater.
 * 
 * Intuition for Water at Index `i`:
 *  water[i] = max(0, min(maxLeftHeight[i], maxRightHeight[i]) - height[i])
 * 
 * --- Approach 1: Better (Prefix/Suffix Max Arrays) ---
 * Precompute leftMax[i] and rightMax[i] in two linear scans.
 * Time Complexity: O(N) | Space Complexity: O(N)
 * 
 * --- Approach 2: Optimal (Two Pointers) ---
 * Maintain `left` (0) and `right` (N-1) pointers, alongside `leftMax` and `rightMax`.
 * Whichever side has smaller height (e.g. `height[left] <= height[right]`), its maximum height 
 * bounds the water for `left`, because we KNOW `rightMax` is at least `height[right] >= height[left]`.
 * 
 * Time Complexity: O(N) | Space Complexity: O(1)
 */
int trapRainWaterOptimal(const vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                totalWater += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                totalWater += rightMax - height[right];
            }
            right--;
        }
    }

    return totalWater;
}

// ============================================================================
// PROBLEM 3: CONTAINER WITH MOST WATER
// ============================================================================

/**
 * Intuition:
 *  Area = min(height[left], height[right]) * (right - left).
 *  Start with widest container: `left = 0`, `right = N - 1`.
 *  To potentially get a LARGER area with a smaller width, we MUST increase the height.
 *  Therefore, always move the pointer pointing to the SHORTER line!
 * 
 * Proof of Correctness:
 *  If height[left] < height[right], keeping left fixed and moving right inward can NEVER 
 *  yield a larger area because width decreases and height is bounded by height[left].
 *  Thus, skipping all containers with 'left' is safe!
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int maxAreaContainer(const vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        int currentWater = min(height[left], height[right]) * (right - left);
        maxWater = max(maxWater, currentWater);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

// ============================================================================
// PROBLEM 4: FAST & SLOW POINTERS (Move Zeroes to End in-place)
// ============================================================================

/**
 * Strategy:
 *  `slow` pointer keeps track of where the next non-zero element should go.
 *  `fast` pointer scans through the array.
 *  When `nums[fast] != 0`, swap `nums[slow]` and `nums[fast]`, then increment `slow`.
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); ++fast) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING TWO POINTERS TEST SUITE        " << endl;
    cout << "==========================================" << endl;

    // Test 1: 3-Sum
    cout << "\n[Test 1] Testing 3-Sum..." << endl;
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = threeSum(nums1);
    cout << "3-Sum Triplets for {-1, 0, 1, 2, -1, -4}:" << endl;
    for (const auto& t : triplets) {
        cout << "  [" << t[0] << ", " << t[1] << ", " << t[2] << "]" << endl;
    }
    assert(triplets.size() == 2); // Expected: {-1, -1, 2} and {-1, 0, 1}
    cout << "✓ 3-Sum Passed!" << endl;

    // Test 2: Trapping Rain Water
    cout << "\n[Test 2] Testing Trapping Rain Water..." << endl;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = trapRainWaterOptimal(height);
    cout << "Trapped Water: " << trappedWater << " units." << endl;
    assert(trappedWater == 6);
    cout << "✓ Trapping Rain Water Passed!" << endl;

    // Test 3: Container With Most Water
    cout << "\n[Test 3] Testing Container With Most Water..." << endl;
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxContainer = maxAreaContainer(heights);
    cout << "Max Container Area: " << maxContainer << endl;
    assert(maxContainer == 49);
    cout << "✓ Container With Most Water Passed!" << endl;

    // Test 4: Move Zeroes
    cout << "\n[Test 4] Testing Move Zeroes..." << endl;
    vector<int> nums2 = {0, 1, 0, 3, 12};
    moveZeroes(nums2);
    vector<int> expected = {1, 3, 12, 0, 0};
    assert(nums2 == expected);
    cout << "✓ Move Zeroes Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << "     ALL TWO POINTERS TESTS PASSED!       " << endl;
    cout << "==========================================" << endl;

    return 0;
}
