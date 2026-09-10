/**
 * ============================================================================
 * PHASE 2: SLIDING WINDOW MASTERY (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Fixed-Size Sliding Window: Max Sum Subarray of Size K
 *  2. Variable-Size Sliding Window: Longest Substring Without Repeating Chars
 *  3. Complex Window with Character Map: Minimum Window Substring
 *  4. Advanced "At Most K / Exactly K" Pattern: Subarrays with K Distinct Integers
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ============================================================================
// PROBLEM 1: FIXED-SIZE WINDOW (Max Sum Subarray of Size K)
// ============================================================================

/**
 * Intuition:
 *  Redundancy in Brute Force: Computing sum of every window of size K takes O(K) per window -> O(N * K).
 *  Sliding Window Insight: When window shifts from [i..i+K-1] to [i+1..i+K],
 *  `newSum = oldSum - arr[i] + arr[i+K]`.
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
long long maxSumSubarrayFixed(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    long long windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += arr[i];
    }

    long long maxSum = windowSum;
    for (int i = k; i < n; ++i) {
        windowSum += arr[i] - arr[i - k]; // Slide window right
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

// ============================================================================
// PROBLEM 2: VARIABLE-SIZE WINDOW (Longest Substring Without Repeating Chars)
// ============================================================================

/**
 * Intuition:
 *  Maintain dynamic window `[left, right]`.
 *  Use a hash table / frequency map to track the last seen index of each character.
 *  When `s[right]` is repeated and its last index >= `left`, jump `left` to `lastIndex + 1`.
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(min(N, AlphabetSize)) = O(1) for ASCII (256)
 */
int lengthOfLongestSubstring(const string& s) {
    vector<int> lastSeen(256, -1);
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); ++right) {
        char currentChar = s[right];

        if (lastSeen[currentChar] >= left) {
            left = lastSeen[currentChar] + 1; // Shrink window to remove duplicate
        }

        lastSeen[currentChar] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

// ============================================================================
// PROBLEM 3: MINIMUM WINDOW SUBSTRING (Hard FAANG Pattern)
// ============================================================================

/**
 * Problem: Given string S and T, find smallest substring of S containing all chars of T.
 * 
 * Algorithm:
 *  1. Build frequency map of T (`targetFreq`). Track total required chars (`requiredCount`).
 *  2. Expand `right` pointer over S, updating `windowFreq`.
 *  3. When `windowFreq[S[right]] == targetFreq[S[right]]`, increment `matchedCount`.
 *  4. While `matchedCount == requiredCount`:
 *     - Record potential minimum window substring.
 *     - Shrink window from `left` pointer to find smaller valid window.
 * 
 * Time Complexity: O(|S| + |T|)
 * Space Complexity: O(1) (Fixed alphabet size 128)
 */
string minWindowSubstring(const string& s, const string& t) {
    if (s.empty() || t.empty() || s.length() < t.length()) return "";

    vector<int> targetFreq(128, 0);
    for (char c : t) targetFreq[c]++;

    int requiredCount = 0;
    for (int count : targetFreq) {
        if (count > 0) requiredCount++;
    }

    vector<int> windowFreq(128, 0);
    int matchedCount = 0;

    int left = 0, minLen = INT_MAX, minStart = 0;

    for (int right = 0; right < s.length(); ++right) {
        char rightChar = s[right];
        windowFreq[rightChar]++;

        if (targetFreq[rightChar] > 0 && windowFreq[rightChar] == targetFreq[rightChar]) {
            matchedCount++;
        }

        // Try to shrink window when all required chars are matched
        while (matchedCount == requiredCount) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            char leftChar = s[left];
            windowFreq[leftChar]--;
            if (targetFreq[leftChar] > 0 && windowFreq[leftChar] < targetFreq[leftChar]) {
                matchedCount--;
            }
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

// ============================================================================
// PROBLEM 4: AT MOST K / EXACTLY K PATTERN (Subarrays with K Distinct Integers)
// ============================================================================

/**
 * Fundamental Mathematical Identity for Subarray Counting:
 *  Count(Exactly K Distinct) = Count(At Most K Distinct) - Count(At Most K-1 Distinct)
 * 
 * Why?
 *  Subarrays with "At Most K" distinct elements = {Subarrays with 1, 2, ..., K distinct elements}.
 *  Subarrays with "At Most K-1" distinct elements = {Subarrays with 1, 2, ..., K-1 distinct elements}.
 *  Subtracting leaves EXACTLY K distinct elements!
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(K)
 */

int countAtMostKDistinct(const vector<int>& nums, int k) {
    if (k <= 0) return 0;
    unordered_map<int, int> freq;
    int left = 0;
    int count = 0;

    for (int right = 0; right < nums.size(); ++right) {
        freq[nums[right]]++;

        while (freq.size() > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            left++;
        }

        // Number of valid subarrays ending at 'right' = window length
        count += (right - left + 1);
    }

    return count;
}

int subarraysWithKDistinct(const vector<int>& nums, int k) {
    return countAtMostKDistinct(nums, k) - countAtMostKDistinct(nums, k - 1);
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING SLIDING WINDOW TEST SUITE      " << endl;
    cout << "==========================================" << endl;

    // Test 1: Fixed Size Sliding Window
    cout << "\n[Test 1] Testing Max Sum Subarray of Size K..." << endl;
    vector<int> arr1 = {2, 1, 5, 1, 3, 2};
    long long maxSubSum = maxSumSubarrayFixed(arr1, 3);
    cout << "Max Sum of window size 3: " << maxSubSum << endl;
    assert(maxSubSum == 9); // Subarray {5, 1, 3} -> Sum = 9
    cout << "✓ Max Sum Subarray Passed!" << endl;

    // Test 2: Longest Substring Without Repeating Chars
    cout << "\n[Test 2] Testing Longest Substring Without Repeats..." << endl;
    string s1 = "abcabcbb";
    int maxLen = lengthOfLongestSubstring(s1);
    cout << "Longest Substring without repeats in 'abcabcbb': " << maxLen << endl;
    assert(maxLen == 3); // "abc"
    cout << "✓ Longest Substring Passed!" << endl;

    // Test 3: Minimum Window Substring
    cout << "\n[Test 3] Testing Minimum Window Substring..." << endl;
    string s2 = "ADOBECODEBANC", t2 = "ABC";
    string minWin = minWindowSubstring(s2, t2);
    cout << "Minimum Window Substring for S='ADOBECODEBANC', T='ABC': " << minWin << endl;
    assert(minWin == "BANC");
    cout << "✓ Minimum Window Substring Passed!" << endl;

    // Test 4: Subarrays with K Distinct Integers
    cout << "\n[Test 4] Testing Subarrays with K Distinct Integers..." << endl;
    vector<int> arr2 = {1, 2, 1, 2, 3};
    int kDistinctCount = subarraysWithKDistinct(arr2, 2);
    cout << "Subarrays with exactly 2 distinct integers: " << kDistinctCount << endl;
    assert(kDistinctCount == 7); // {1,2}, {2,1}, {1,2}, {2,3}, {1,2,1}, {2,1,2}, {1,2,1,2}
    cout << "✓ Subarrays with K Distinct Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << "    ALL SLIDING WINDOW TESTS PASSED!      " << endl;
    cout << "==========================================" << endl;

    return 0;
}
