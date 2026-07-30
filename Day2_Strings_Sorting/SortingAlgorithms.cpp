/*
 * Day 2 - Sorting Algorithms
 * -----------------------------------------
 * Bubble Sort, Selection Sort, Insertion Sort (O(n^2) family)
 * Merge Sort, Quick Sort (O(n log n) family)
 *
 * Stability / in-place notes in comments above each function.
 */

#include <iostream>
#include <vector>
using namespace std;

// ---------------- Bubble Sort ----------------
// O(n^2) worst/avg, O(n) best (with early-exit optimization). Stable. In-place.
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// ---------------- Selection Sort ----------------
// O(n^2) always. NOT stable (can swap equal elements out of order). In-place.
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// ---------------- Insertion Sort ----------------
// O(n^2) worst, O(n) best (nearly sorted). Stable. In-place.
// Efficient for small or nearly-sorted arrays.
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------------- Merge Sort ----------------
// O(n log n) guaranteed (best/avg/worst). Stable. NOT in-place (O(n) extra space).
void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]); // '<=' preserves stability
        else temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);
    for (int k = left; k <= right; k++) arr[k] = temp[k - left];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// ---------------- Quick Sort ----------------
// O(n log n) average, O(n^2) worst (bad pivot on sorted/reverse-sorted input).
// NOT stable. In-place (O(log n) recursion stack space).
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArr(const vector<int> &arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> base = {5, 2, 9, 1, 7, 3, 8, 4, 6};

    vector<int> a1 = base;
    bubbleSort(a1);
    cout << "Bubble Sort:    "; printArr(a1);

    vector<int> a2 = base;
    selectionSort(a2);
    cout << "Selection Sort: "; printArr(a2);

    vector<int> a3 = base;
    insertionSort(a3);
    cout << "Insertion Sort: "; printArr(a3);

    vector<int> a4 = base;
    mergeSort(a4, 0, a4.size() - 1);
    cout << "Merge Sort:     "; printArr(a4);

    vector<int> a5 = base;
    quickSort(a5, 0, a5.size() - 1);
    cout << "Quick Sort:     "; printArr(a5);

    return 0;
}