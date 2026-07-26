/*
 * Day 1 - Arrays: Basic Operations
 * -----------------------------------------
 * Covers: traversal, insertion, deletion, linear search,
 * binary search, reversal, max/min, and dynamic array (vector) demo.
 *
 * Time/Space complexity noted above each function.
 */

#include <iostream>
#include <vector>
using namespace std;

// Traversal - O(n) time, O(1) space
void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Insert 'val' at position 'pos' (0-indexed). Assumes arr has extra capacity.
// Time: O(n) worst case (shifting elements), O(1) best case (insert at end)
void insertAt(int arr[], int &n, int pos, int val) {
    if (pos < 0 || pos > n) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];   // shift right
    }
    arr[pos] = val;
    n++;
}

// Delete element at position 'pos'
// Time: O(n) worst case, O(1) if deleting last element
void deleteAt(int arr[], int &n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];   // shift left
    }
    n--;
}

// Linear search - O(n) time, O(1) space
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

// Binary search - O(log n) time, O(1) space. Array must be SORTED.
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // avoids overflow vs (low+high)/2
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Reverse array in place - O(n) time, O(1) space
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Recursive reverse - O(n) time, O(n) space (call stack)
void reverseRecursive(int arr[], int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverseRecursive(arr, start + 1, end - 1);
}

// Find max and min in a single pass - O(n) time, O(1) space
void findMaxMin(int arr[], int n, int &maxVal, int &minVal) {
    maxVal = arr[0];
    minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }
}

int main() {
    int arr[10] = {5, 2, 9, 1, 7};
    int n = 5;

    cout << "Original array: ";
    traverse(arr, n);

    insertAt(arr, n, 2, 100);
    cout << "After inserting 100 at index 2: ";
    traverse(arr, n);

    deleteAt(arr, n, 0);
    cout << "After deleting index 0: ";
    traverse(arr, n);

    cout << "Linear search for 9: index " << linearSearch(arr, n, 9) << endl;

    reverseArray(arr, n);
    cout << "Reversed: ";
    traverse(arr, n);

    int mx, mn;
    findMaxMin(arr, n, mx, mn);
    cout << "Max: " << mx << ", Min: " << mn << endl;

    // Dynamic array (vector) demo
    vector<int> v = {3, 1, 4, 1, 5};
    v.push_back(9);                  // O(1) amortized
    v.insert(v.begin() + 1, 100);    // O(n)
    v.erase(v.begin());              // O(n)
    cout << "Vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    return 0;
}