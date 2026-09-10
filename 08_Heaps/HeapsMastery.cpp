/**
 * ============================================================================
 * PHASE 8: HEAPS & PRIORITY QUEUES MASTERY (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Custom Binary Heap Implementation (O(N) Heapify)
 *  2. Top K Frequent Elements (Min-Heap Pattern)
 *  3. Find Median from Data Stream (Two Heaps Pattern: Max-Heap + Min-Heap)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

// ============================================================================
// SECTION 1: CUSTOM MIN-HEAP IMPLEMENTATION
// ============================================================================

class CustomMinHeap {
    vector<int> heap;

    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int n = heap.size();

        if (left < n && heap[left] < heap[smallest]) smallest = left;
        if (right < n && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

public:
    // Build Heap in O(N) linear time from unsorted vector
    CustomMinHeap(const vector<int>& nums) : heap(nums) {
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int top() const {
        return heap.front();
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    bool empty() const { return heap.empty(); }
};

// ============================================================================
// SECTION 2: TOP K FREQUENT ELEMENTS
// ============================================================================

vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    for (int num : nums) freqMap[num]++;

    // Min-heap storing pair: {frequency, num}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (const auto& [num, count] : freqMap) {
        minHeap.push({count, num});
        if (minHeap.size() > k) {
            minHeap.pop(); // Evict lowest frequency item
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

// ============================================================================
// SECTION 3: FIND MEDIAN FROM DATA STREAM (Two Heaps Pattern)
// ============================================================================

class MedianFinder {
    priority_queue<int> maxHeap; // Smaller half elements
    priority_queue<int, vector<int>, greater<int>> minHeap; // Larger half elements

public:
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);

        // Balance step 1: Ensure all elements in maxHeap <= minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Balance step 2: Keep maxHeap size equal to or +1 greater than minHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING HEAPS & PRIORITY QUEUE TESTS   " << endl;
    cout << "==========================================" << endl;

    // Test 1: Custom Min-Heap
    cout << "\n[Test 1] Testing Custom Min-Heap (Build Heap O(N))..." << endl;
    vector<int> nums = {4, 10, 3, 5, 1};
    CustomMinHeap minHeap(nums);
    assert(minHeap.top() == 1);
    minHeap.pop();
    assert(minHeap.top() == 3);
    cout << "✓ Custom Min-Heap Passed!" << endl;

    // Test 2: Top K Frequent Elements
    cout << "\n[Test 2] Testing Top K Frequent Elements..." << endl;
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    vector<int> topK = topKFrequent(arr, 2);
    assert(find(topK.begin(), topK.end(), 1) != topK.end());
    assert(find(topK.begin(), topK.end(), 2) != topK.end());
    cout << "✓ Top K Frequent Passed!" << endl;

    // Test 3: Median Finder (Two Heaps)
    cout << "\n[Test 3] Testing Median Finder..." << endl;
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    assert(mf.findMedian() == 1.5);
    mf.addNum(3);
    assert(mf.findMedian() == 2.0);
    cout << "✓ Median Finder Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << "  ALL HEAPS & PRIORITY QUEUE TESTS PASSED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}
