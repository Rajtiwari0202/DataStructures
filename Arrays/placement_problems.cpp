// Iterative - O(n) time, O(1) space
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Recursive - O(n) time, O(n) space (call stack)
void reverseRecursive(int arr[], int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverseRecursive(arr, start + 1, end - 1);
}

int findMissingSum(int arr[], int n) {
    // arr has n-1 elements, numbers range 1 to n
    long long expectedSum = (long long)n * (n + 1) / 2;
    long long actualSum = 0;
    for (int i = 0; i < n - 1; i++) actualSum += arr[i];
    return expectedSum - actualSum;
}
int findMissingXOR(int arr[], int n) {
    int xorAll = 0, xorArr = 0;
    for (int i = 1; i <= n; i++) xorAll ^= i;
    for (int i = 0; i < n - 1; i++) xorArr ^= arr[i];
    return xorAll ^ xorArr;
}

int maxSubArraySum(int arr[], int n) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];

    for (int i = 1; i < n; i++) {
        // either extend previous subarray, or start new one at arr[i]
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

// Variant: also return the subarray indices (commonly asked follow-up)
int maxSubArrayWithIndices(int arr[], int n, int &startIdx, int &endIdx) {
    int maxSoFar = arr[0], maxEndingHere = arr[0];
    int start = 0;
    startIdx = 0; endIdx = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxEndingHere + arr[i]) {
            maxEndingHere = arr[i];
            start = i;              // fresh start
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


void moveZeroes(int arr[], int n) {
    int insertPos = 0; // points to where next non-zero should go

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[insertPos], arr[i]);
            insertPos++;
        }
    }
}

pair<int,int> twoSumBrute(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == target)
                return {i, j};
    return {-1, -1};
}

#include <unordered_map>
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

pair<int,int> twoSumSorted(vector<int> arr, int target) {
    sort(arr.begin(), arr.end()); // O(n log n) — destroys original index order!
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return {arr[left], arr[right]};
        else if (sum < target) left++;
        else right--;
    }
    return {-1, -1};
}