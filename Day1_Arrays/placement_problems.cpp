/*
 * Day 1 - Arrays: 5 Placement-Frequent Problems
 * -----------------------------------------------------
 * 1. Missing Number (1 to n) - Sum & XOR approach
 * 2. Kadane's Algorithm - Maximum Subarray Sum
 * 3. Move Zeroes to End - Two Pointer
 * 4. Two Sum - Brute force, Hashing, Sorted Two Pointer
 *
 * Each includes complexity + edge cases in comments.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ---------------- 1. Missing Number ----------------

// Sum approach - O(n) time, O(1) space
// CAUTION: use long long to avoid integer overflow for large n
int findMissingSum(int arr[], int n) {
    long long expectedSum = (long long)n * (n + 1) / 2;
    long long actualSum = 0;
    for (int i = 0; i < n - 1; i++) actualSum += arr[i];
    return (int)(expectedSum - actualSum);
}

// XOR approach - O(n) time, O(1) space, NO overflow risk
int findMissingXOR(int arr[], int n) {
    int xorAll = 0, xorArr = 0;
    for (int i = 1; i <= n; i++) xorAll ^= i;
    for (int i = 0; i < n - 1; i++) xorArr ^= arr[i];
    return xorAll ^ xorArr;
}
// NOTE: Both approaches only work if EXACTLY ONE number is missing.

// ---------------- 2. Kadane's Algorithm ----------------

// O(n) time, O(1) space
// IMPORTANT: initialize with arr[0], NOT 0, so all-negative arrays work correctly
int maxSubArraySum(int arr[], int n) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];

    for (int i = 1; i < n; i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

// Variant that also returns the subarray's start/end indices
int maxSubArrayWithIndices(int arr[], int n, int &startIdx, int &endIdx) {
    int maxSoFar = arr[0], maxEndingHere = arr[0];
    int start = 0;
    startIdx = 0; endIdx = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxEndingHere + arr[i]) {
            maxEndingHere = arr[i];
            start = i;
        } else {
            maxEndingHere += arr[i];
        }
        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            startIdx = start;
            endIdx = i;
        }
    }
    return maxSoFar;
}

// ---------------- 3. Move Zeroes to End ----------------

// O(n) time, O(1) space - maintains relative order of non-zero elements
void moveZeroes(int arr[], int n) {
    int insertPos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[insertPos], arr[i]);
            insertPos++;
        }
    }
}

// ---------------- 4. Two Sum ----------------

// Brute force - O(n^2) time, O(1) space
pair<int,int> twoSumBrute(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == target)
                return {i, j};
    return {-1, -1};
}

// Hashing - O(n) time, O(n) space - returns INDICES
pair<int,int> twoSumHash(int arr[], int n, int target) {
    unordered_map<int,int> seen; // value -> index
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        seen[arr[i]] = i;
    }
    return {-1, -1};
}

// Sorted + Two Pointer - O(n log n) time, O(1) extra space
// CAUTION: sorting destroys original indices - only use when you need VALUES
pair<int,int> twoSumSorted(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = (int)arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return {arr[left], arr[right]};
        else if (sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

int main() {
    // 1. Missing Number
    int arr1[] = {1, 2, 4, 5};
    int n1 = 5; // numbers should be 1..5, one missing
    cout << "Missing number (sum): " << findMissingSum(arr1, n1) << endl;
    cout << "Missing number (xor): " << findMissingXOR(arr1, n1) << endl;

    // 2. Kadane's Algorithm
    int arr2[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n2 = 9;
    int s, e;
    cout << "Max subarray sum: " << maxSubArraySum(arr2, n2) << endl;
    int maxSum = maxSubArrayWithIndices(arr2, n2, s, e);
    cout << "Max subarray sum: " << maxSum << " from index " << s << " to " << e << endl;

    // 3. Move Zeroes
    int arr3[] = {0, 1, 0, 3, 12};
    int n3 = 5;
    moveZeroes(arr3, n3);
    cout << "After moving zeroes: ";
    for (int i = 0; i < n3; i++) cout << arr3[i] << " ";
    cout << endl;

    // 4. Two Sum
    int arr4[] = {2, 7, 11, 15};
    int n4 = 4;
    int target = 9;
    auto resultBrute = twoSumBrute(arr4, n4, target);
    auto resultHash = twoSumHash(arr4, n4, target);
    cout << "Two Sum (brute) indices: " << resultBrute.first << ", " << resultBrute.second << endl;
    cout << "Two Sum (hash) indices: " << resultHash.first << ", " << resultHash.second << endl;

    return 0;
}