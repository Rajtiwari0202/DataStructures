/*
 * Day 2 - Strings & Searching: Placement Problems
 * -----------------------------------------------------
 * 1. Palindrome Check - Two Pointer
 * 2. Anagram Check - Sorting vs Frequency Count
 * 3. First Non-Repeating Character - Frequency Map
 * 4. Search in Rotated Sorted Array - Modified Binary Search
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ---------------- 1. Palindrome Check ----------------
// O(n) time, O(1) space
bool isPalindrome(string s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// ---------------- 2. Anagram Check ----------------
// Brute force: sort both strings - O(n log n)
bool isAnagramSort(string a, string b) {
    if (a.size() != b.size()) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

// Optimal: frequency count - O(n) time, O(1) space (fixed 26-letter array)
// NOTE: assumes lowercase a-z only. Use unordered_map<char,int> for general case.
bool isAnagram(string a, string b) {
    if (a.size() != b.size()) return false;
    int freq[26] = {0};
    for (char c : a) freq[c - 'a']++;
    for (char c : b) freq[c - 'a']--;
    for (int f : freq) if (f != 0) return false;
    return true;
}

// ---------------- 3. First Non-Repeating Character ----------------
// O(n) time, O(1) space (bounded alphabet)
char firstNonRepeating(string s) {
    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;
    for (char c : s) {
        if (freq[c - 'a'] == 1) return c;
    }
    return '\0'; // sentinel: no non-repeating character
}

// ---------------- 4. Search in Rotated Sorted Array ----------------
// O(log n) time, O(1) space. Assumes distinct elements.
int searchRotated(vector<int> &arr, int target) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;

        if (arr[low] <= arr[mid]) {
            // left half is sorted
            if (arr[low] <= target && target < arr[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            // right half is sorted
            if (arr[mid] < target && target <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

int main() {
    // 1. Palindrome
    cout << "isPalindrome(\"madam\"): " << (isPalindrome("madam") ? "true" : "false") << endl;
    cout << "isPalindrome(\"hello\"): " << (isPalindrome("hello") ? "true" : "false") << endl;

    // 2. Anagram
    cout << "isAnagram(\"listen\",\"silent\"): " << (isAnagram("listen", "silent") ? "true" : "false") << endl;
    cout << "isAnagramSort(\"listen\",\"silent\"): " << (isAnagramSort("listen", "silent") ? "true" : "false") << endl;
    cout << "isAnagram(\"hello\",\"world\"): " << (isAnagram("hello", "world") ? "true" : "false") << endl;

    // 3. First Non-Repeating Character
    cout << "firstNonRepeating(\"swiss\"): " << firstNonRepeating("swiss") << endl;

    // 4. Search in Rotated Sorted Array
    vector<int> rotated = {4, 5, 6, 7, 0, 1, 2};
    cout << "searchRotated(target=0): index " << searchRotated(rotated, 0) << endl;
    cout << "searchRotated(target=3): index " << searchRotated(rotated, 3) << endl;

    return 0;
}