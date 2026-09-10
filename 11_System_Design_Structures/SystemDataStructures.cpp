/**
 * ============================================================================
 * PHASE 11: SYSTEM DESIGN DATA STRUCTURES (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. All O(1) Data Structure (Inc, Dec, GetMaxKey, GetMinKey in O(1) time)
 *  2. Snapshot Array (O(1) Snapshot creation, O(log S) retrieval via Binary Search)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
#include <cassert>

using namespace std;

// ============================================================================
// SYSTEM DESIGN 1: ALL O(1) DATA STRUCTURE
// ============================================================================

/**
 * Requirement:
 *  - Inc(key): increment count of key by 1.
 *  - Dec(key): decrement count of key by 1.
 *  - GetMaxKey(): return key with max count in O(1).
 *  - GetMinKey(): return key with min count in O(1).
 * 
 * Strategy: Doubly Linked List of Buckets + Hash Map!
 *  Each Bucket node in list holds:
 *   - `count`: integer value
 *   - `keys`: unordered_set<string> of keys with this count.
 * 
 * Hash Map `keyToBucket`: maps `key` to `list<Bucket>::iterator`.
 */
class AllOne {
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };

    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> keyToBucket;

public:
    AllOne() {}

    void inc(string key) {
        if (keyToBucket.find(key) == keyToBucket.end()) {
            // New key (count = 1). Insert at front of list if bucket with count 1 doesn't exist
            if (buckets.empty() || buckets.front().count != 1) {
                buckets.push_front({1, {key}});
            } else {
                buckets.front().keys.insert(key);
            }
            keyToBucket[key] = buckets.begin();
        } else {
            // Key exists: move from current bucket to bucket with count + 1
            auto curIt = keyToBucket[key];
            auto nextIt = next(curIt);

            if (nextIt == buckets.end() || nextIt->count != curIt->count + 1) {
                nextIt = buckets.insert(nextIt, {curIt->count + 1, {key}});
            } else {
                nextIt->keys.insert(key);
            }

            keyToBucket[key] = nextIt;
            curIt->keys.erase(key);

            if (curIt->keys.empty()) {
                buckets.erase(curIt);
            }
        }
    }

    void dec(string key) {
        if (keyToBucket.find(key) == keyToBucket.end()) return;

        auto curIt = keyToBucket[key];

        if (curIt->count == 1) {
            keyToBucket.erase(key);
        } else {
            auto prevIt = prev(curIt);
            if (curIt == buckets.begin() || prevIt->count != curIt->count - 1) {
                prevIt = buckets.insert(curIt, {curIt->count - 1, {key}});
            } else {
                prevIt->keys.insert(key);
            }
            keyToBucket[key] = prevIt;
        }

        curIt->keys.erase(key);
        if (curIt->keys.empty()) {
            buckets.erase(curIt);
        }
    }

    string getMaxKey() {
        return buckets.empty() ? "" : *buckets.back().keys.begin();
    }

    string getMinKey() {
        return buckets.empty() ? "" : *buckets.front().keys.begin();
    }
};

// ============================================================================
// SYSTEM DESIGN 2: SNAPSHOT ARRAY
// ============================================================================

/**
 * Strategy:
 *  Instead of copying the full array during `snap()` (which takes O(N) space/time),
 *  store version history per index!
 * 
 *  `history[index]` = vector of pair `{snap_id, value}`.
 *  - `snap()`: Increment `snap_id` in O(1) time!
 *  - `get(index, snap_id)`: Perform `std::upper_bound` binary search on `history[index]` in O(log S) time!
 */
class SnapshotArray {
    int snap_id;
    vector<vector<pair<int, int>>> history; // index -> vector<{snap_id, val}>

public:
    SnapshotArray(int length) : snap_id(0), history(length) {
        for (int i = 0; i < length; ++i) {
            history[i].push_back({0, 0}); // Initial snap_id 0 has value 0
        }
    }

    void set(int index, int val) {
        if (history[index].back().first == snap_id) {
            history[index].back().second = val; // Update current snapshot value
        } else {
            history[index].push_back({snap_id, val});
        }
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id_val) {
        const auto& vec = history[index];
        // Find first element with snap_id > snap_id_val, then step back 1
        auto it = upper_bound(vec.begin(), vec.end(), make_pair(snap_id_val, INT_MAX));
        return prev(it)->second;
    }
};

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "   RUNNING SYSTEM DATA STRUCTURES TESTS   " << endl;
    cout << "==========================================" << endl;

    // Test 1: All O(1) Data Structure
    cout << "\n[Test 1] Testing All O(1) Data Structure..." << endl;
    AllOne allOne;
    allOne.inc("hello");
    allOne.inc("hello");
    assert(allOne.getMaxKey() == "hello");
    assert(allOne.getMinKey() == "hello");
    allOne.inc("leet");
    assert(allOne.getMaxKey() == "hello");
    assert(allOne.getMinKey() == "leet");
    allOne.dec("hello");
    allOne.dec("hello");
    assert(allOne.getMaxKey() == "leet");
    cout << "✓ All O(1) Data Structure Passed!" << endl;

    // Test 2: Snapshot Array
    cout << "\n[Test 2] Testing Snapshot Array..." << endl;
    SnapshotArray snapArr(3);
    snapArr.set(0, 5);
    int snap0 = snapArr.snap(); // snap0 = 0
    snapArr.set(0, 6);
    int snap1 = snapArr.snap(); // snap1 = 1

    assert(snapArr.get(0, 0) == 5); // At snap 0, index 0 was 5
    assert(snapArr.get(0, 1) == 6); // At snap 1, index 0 was 6
    assert(snapArr.get(1, 0) == 0); // Index 1 was never modified -> 0
    cout << "✓ Snapshot Array Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << " ALL SYSTEM DESIGN DATA STRUCTURES PASSED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}
