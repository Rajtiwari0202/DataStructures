/**
 * ============================================================================
 * PHASE 7: ADVANCED TREES & DATA STRUCTURES (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Trie (Prefix Tree)
 *  2. Bitwise Trie for Maximum XOR Subarray
 *  3. Segment Tree with Lazy Propagation (Range Updates & Range Sum Queries in O(log N))
 *  4. Binary Indexed Tree (Fenwick Tree)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

// ============================================================================
// SECTION 1: TRIE & BITWISE TRIE (Maximum XOR Subarray)
// ============================================================================

struct BitwiseTrieNode {
    BitwiseTrieNode* children[2];
    BitwiseTrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class BitwiseTrie {
    BitwiseTrieNode* root;

public:
    BitwiseTrie() {
        root = new BitwiseTrieNode();
    }

    void insert(int num) {
        BitwiseTrieNode* curr = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new BitwiseTrieNode();
            }
            curr = curr->children[bit];
        }
    }

    // Find maximum XOR of 'num' with any number stored in Trie
    int getMaxXOR(int num) {
        BitwiseTrieNode* curr = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit; // Greedily pick opposite bit to maximize XOR result

            if (curr->children[oppositeBit]) {
                maxXOR |= (1 << i);
                curr = curr->children[oppositeBit];
            } else {
                curr = curr->children[bit];
            }
        }
        return maxXOR;
    }
};

// ============================================================================
// SECTION 2: SEGMENT TREE WITH LAZY PROPAGATION
// ============================================================================

class SegmentTreeLazy {
    int n;
    vector<long long> tree;
    vector<long long> lazy;

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void pushPendingLazy(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) { // Propagate lazy values to children
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

public:
    SegmentTreeLazy(const vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, arr);
    }

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        pushPendingLazy(node, start, end);
        if (start > r || end < l) return; // Completely outside

        if (start >= l && end <= r) { // Completely inside
            lazy[node] += val;
            pushPendingLazy(node, start, end);
            return;
        }

        int mid = start + (end - start) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        pushPendingLazy(node, start, end);
        if (start > r || end < l) return 0; // Completely outside

        if (start >= l && end <= r) return tree[node]; // Completely inside

        int mid = start + (end - start) / 2;
        return queryRange(2 * node, start, mid, l, r) +
               queryRange(2 * node + 1, mid + 1, end, l, r);
    }

    void updateRange(int l, int r, long long val) { updateRange(1, 0, n - 1, l, r, val); }
    long long queryRange(int l, int r) { return queryRange(1, 0, n - 1, l, r); }
};

// ============================================================================
// SECTION 3: FENWICK TREE (Binary Indexed Tree - BIT)
// ============================================================================

class FenwickTree {
    int n;
    vector<long long> bit;

public:
    FenwickTree(int size) : n(size), bit(size + 1, 0) {}

    // Point Update: Add val to index i (0-indexed)
    void add(int i, long long val) {
        for (++i; i <= n; i += i & (-i)) {
            bit[i] += val;
        }
    }

    // Prefix Sum Query: Sum from index 0 to i (0-indexed)
    long long queryPrefixSum(int i) {
        long long sum = 0;
        for (++i; i > 0; i -= i & (-i)) {
            sum += bit[i];
        }
        return sum;
    }

    // Range Sum Query: Sum from index L to R
    long long queryRangeSum(int L, int R) {
        if (L > R) return 0;
        return queryPrefixSum(R) - (L == 0 ? 0 : queryPrefixSum(L - 1));
    }
};

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING ADVANCED TREES TEST SUITE      " << endl;
    cout << "==========================================" << endl;

    // Test 1: Bitwise Trie (Max XOR Pair)
    cout << "\n[Test 1] Testing Bitwise Trie Max XOR..." << endl;
    BitwiseTrie trie;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    for (int num : nums) trie.insert(num);

    int maxResult = 0;
    for (int num : nums) {
        maxResult = max(maxResult, trie.getMaxXOR(num));
    }
    cout << "Maximum XOR Pair Result: " << maxResult << endl;
    assert(maxResult == 28); // 5 ^ 25 = 28
    cout << "✓ Bitwise Trie Passed!" << endl;

    // Test 2: Segment Tree with Lazy Propagation
    cout << "\n[Test 2] Testing Segment Tree Lazy Propagation..." << endl;
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTreeLazy segTree(arr);
    assert(segTree.queryRange(1, 3) == 15); // 3 + 5 + 7 = 15

    segTree.updateRange(1, 3, 10); // Add 10 to indices 1..3 -> {1, 13, 15, 17, 9, 11}
    assert(segTree.queryRange(1, 3) == 45); // 13 + 15 + 17 = 45
    cout << "✓ Segment Tree Passed!" << endl;

    // Test 3: Fenwick Tree (BIT)
    cout << "\n[Test 3] Testing Fenwick Tree..." << endl;
    FenwickTree fenwick(6);
    for (int i = 0; i < arr.size(); ++i) fenwick.add(i, arr[i]);
    assert(fenwick.queryRangeSum(1, 3) == 15);

    fenwick.add(2, 5); // Add 5 to index 2 (5 -> 10)
    assert(fenwick.queryRangeSum(1, 3) == 20); // 3 + 10 + 7 = 20
    cout << "✓ Fenwick Tree Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << "   ALL ADVANCED TREES TESTS PASSED!       " << endl;
    cout << "==========================================" << endl;

    return 0;
}
