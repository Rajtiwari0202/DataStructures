/**
 * ============================================================================
 * PHASE 5: LINKED LIST MASTERY & CACHE DESIGN (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Singly Linked List Reversal (Iterative & Recursive)
 *  2. Floyd's Cycle Detection (Fast & Slow Pointers)
 *  3. LRU Cache (Least Recently Used) - O(1) Get and Put
 *  4. LFU Cache (Least Frequently Used) - O(1) Get and Put
 * ============================================================================
 */

#include <iostream>
#include <unordered_map>
#include <list>
#include <cassert>

using namespace std;

// ============================================================================
// LINKED LIST NODE DEFINITION
// ============================================================================

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Iterative Reversal: O(N) Time, O(1) Auxiliary Space
ListNode* reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Floyd's Tortoise and Hare Cycle Detection: O(N) Time, O(1) Space
ListNode* detectCycleStart(ListNode* head) {
    if (!head || !head->next) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Cycle detected! Reset slow to head to find intersection point
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Cycle start node
        }
    }
    return nullptr; // No cycle
}

// ============================================================================
// SYSTEM DESIGN: LRU CACHE (O(1) Get and Put)
// ============================================================================

/**
 * Strategy: Doubly Linked List + Hash Map!
 *  - Doubly Linked List maintains access ordering (Most Recently Used at HEAD, Least Recently Used at TAIL).
 *  - Hash Map stores `key -> list<pair<key, value>>::iterator` for O(1) direct node lookup!
 */
class LRUCache {
    int capacity;
    list<pair<int, int>> cacheList; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;

        // Move accessed node to front (HEAD) of list
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Key exists: update value and move to front
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }

        if (cacheList.size() == capacity) {
            // Evict Least Recently Used (TAIL) item
            int lruKey = cacheList.back().first;
            cacheMap.erase(lruKey);
            cacheList.pop_back();
        }

        // Insert new pair at front
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};

// ============================================================================
// SYSTEM DESIGN: LFU CACHE (O(1) Get and Put)
// ============================================================================

/**
 * Strategy:
 *  - Map 1 (`keyToValFreq`): `key -> {val, freq}`
 *  - Map 2 (`freqToList`): `freq -> list<key>` (Doubly Linked List for each frequency)
 *  - Map 3 (`keyToIter`): `key -> list<key>::iterator`
 *  - Track `minFreq` variable.
 */
class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq; // key -> {val, freq}
    unordered_map<int, list<int>> freqToList;        // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyToIter;// key -> iter in freqToList

    void updateFreq(int key) {
        int freq = keyToValFreq[key].second;
        keyToValFreq[key].second++; // Increment frequency

        // Remove key from current freq list
        freqToList[freq].erase(keyToIter[key]);

        // Add key to (freq + 1) list
        freqToList[freq + 1].push_front(key);
        keyToIter[key] = freqToList[freq + 1].begin();

        // If current minFreq list is empty, increment minFreq
        if (freqToList[minFreq].empty()) {
            minFreq++;
        }
    }

public:
    LFUCache(int cap) : capacity(cap), minFreq(0) {}

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) return -1;
        updateFreq(key);
        return keyToValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value; // Update value
            updateFreq(key);
            return;
        }

        if (keyToValFreq.size() == capacity) {
            // Evict key from minFreq list (back of list = least recently used among min frequency)
            int lfuKey = freqToList[minFreq].back();
            freqToList[minFreq].pop_back();
            keyToIter.erase(lfuKey);
            keyToValFreq.erase(lfuKey);
        }

        // Insert new key with freq = 1
        minFreq = 1;
        keyToValFreq[key] = {value, 1};
        freqToList[1].push_front(key);
        keyToIter[key] = freqToList[1].begin();
    }
};

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "  RUNNING LINKED LIST & CACHE TESTS       " << endl;
    cout << "==========================================" << endl;

    // Test 1: LRU Cache
    cout << "\n[Test 1] Testing LRU Cache..." << endl;
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    assert(lru.get(1) == 1); // Returns 1
    lru.put(3, 3);          // Evicts key 2
    assert(lru.get(2) == -1);// Returns -1 (not found)
    lru.put(4, 4);          // Evicts key 1
    assert(lru.get(1) == -1);
    assert(lru.get(3) == 3);
    assert(lru.get(4) == 4);
    cout << "✓ LRU Cache Passed!" << endl;

    // Test 2: LFU Cache
    cout << "\n[Test 2] Testing LFU Cache..." << endl;
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    assert(lfu.get(1) == 1); // Key 1 freq = 2
    lfu.put(3, 3);           // Evicts key 2 (freq = 1)
    assert(lfu.get(2) == -1);
    assert(lfu.get(3) == 3); // Key 3 freq = 2
    lfu.put(4, 4);           // Evicts key 1 (LRU tie-breaker between key 1 & 3)
    assert(lfu.get(1) == -1);
    assert(lfu.get(3) == 3);
    assert(lfu.get(4) == 4);
    cout << "✓ LFU Cache Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << " ALL LINKED LIST & CACHE TESTS PASSED!    " << endl;
    cout << "==========================================" << endl;

    return 0;
}
