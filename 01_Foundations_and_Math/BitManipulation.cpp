/**
 * ============================================================================
 * PHASE 1: BIT MANIPULATION MASTERY (C++)
 * ============================================================================
 * Concepts Covered:
 *  1. Fundamental Bitwise Operators (&, |, ^, ~, <<, >>)
 *  2. Core Bit Manipulation Tricks (Set, Clear, Toggle, Check, Power of 2, LSB)
 *  3. Brian Kernighan's Algorithm for Bit Counting
 *  4. Single Number I (XOR Property)
 *  5. Single Number III (Two Unique Elements - Partitioning via LSB)
 *  6. Power Set Generation using Bitmasks
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <bitset>

using namespace std;

// ============================================================================
// SECTION 1: CORE BIT TRICKS & HELPER FUNCTIONS
// ============================================================================

namespace BitTricks {

    // 1. Check if the i-th bit (0-indexed from right) is set
    bool isBitSet(int n, int i) {
        // Intuition: Shift 1 left by i positions, perform bitwise AND.
        // If non-zero, the bit was 1.
        return (n & (1 << i)) != 0;
    }

    // 2. Set the i-th bit (turn it to 1)
    int setBit(int n, int i) {
        return n | (1 << i);
    }

    // 3. Clear the i-th bit (turn it to 0)
    int clearBit(int n, int i) {
        return n & ~(1 << i);
    }

    // 4. Toggle the i-th bit (0 -> 1 or 1 -> 0)
    int toggleBit(int n, int i) {
        return n ^ (1 << i);
    }

    // 5. Check if n is a power of 2
    // Intuition: A power of 2 has exactly ONE set bit (e.g., 8 = 1000₂).
    // n - 1 flips all bits up to that set bit (e.g., 7 = 0111₂).
    // Thus n & (n - 1) removes the rightmost set bit. If result is 0, n is a power of 2.
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }

    // 6. Brian Kernighan's Algorithm to Count Set Bits
    // Redundancy in Plain Loop: Iterating all 32 bits takes 32 operations.
    // Kernighan's Insight: n & (n - 1) resets the lowest set bit to 0 in 1 step!
    // Time Complexity: O(Number of set bits) -> Worst case O(32) = O(1)
    // Space Complexity: O(1)
    int countSetBitsKernighan(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1); // Clears the lowest set bit
            count++;
        }
        return count;
    }

    // 7. Extract the Lowest Set Bit (LSB / Rightmost set bit)
    // Formula: n & (-n)
    // Proof: In 2's complement, -n = (~n + 1).
    // Combining n & (~n + 1) isolates the rightmost 1 bit.
    int getLowestSetBit(int n) {
        return n & (-n);
    }
}

// ============================================================================
// SECTION 2: SINGLE NUMBER I (Find element appearing once; rest appear twice)
// ============================================================================

/**
 * Intuition & Redundancy Breakdown:
 *  - Brute Force: Linear search for every element -> O(N²) time.
 *  - Better Approach: Frequency Map (unordered_map) -> O(N) time, O(N) space.
 *  - Optimal Approach: Bitwise XOR!
 * 
 * XOR Properties:
 *  1. x ^ x = 0 (Self-inverse)
 *  2. x ^ 0 = x (Identity)
 *  3. x ^ y = y ^ x (Commutative) & (x ^ y) ^ z = x ^ (y ^ z) (Associative)
 * 
 * Therefore: a ^ b ^ a ^ c ^ b = (a ^ a) ^ (b ^ b) ^ c = 0 ^ 0 ^ c = c.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int singleNumberI(const vector<int>& nums) {
    int xorSum = 0;
    for (int num : nums) {
        xorSum ^= num;
    }
    return xorSum;
}

// ============================================================================
// SECTION 3: SINGLE NUMBER III (Find TWO elements appearing once; rest twice)
// ============================================================================

/**
 * Problem: Given array where every element appears twice except TWO numbers (a and b).
 * Find a and b.
 * 
 * Analysis:
 *  1. Compute total XOR sum of all elements = a ^ b.
 *  2. Since a != b, total XOR sum has AT LEAST one set bit (1).
 *  3. Find any set bit (e.g. lowest set bit LSB = totalXor & -totalXor).
 *  4. This set bit means that at this bit position, 'a' and 'b' have DIFFERENT bits (one has 0, one has 1).
 *  5. Partition all numbers in the array into TWO groups based on this bit position:
 *     - Group 1: Numbers with 1 at LSB position (contains 'a' and pairs).
 *     - Group 2: Numbers with 0 at LSB position (contains 'b' and pairs).
 *  6. XORing each group individually reveals 'a' and 'b'!
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
pair<int, int> singleNumberIII(const vector<int>& nums) {
    long long totalXor = 0;
    for (int num : nums) {
        totalXor ^= num;
    }

    // Isolate LSB (using long long to prevent integer overflow for INT_MIN)
    long long lsb = totalXor & (-totalXor);

    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & lsb) {
            num1 ^= num; // Group with bit set
        } else {
            num2 ^= num; // Group with bit NOT set
        }
    }

    return {num1, num2};
}

// ============================================================================
// SECTION 4: POWER SET (Generate All 2^N Subsets using Bitmasks)
// ============================================================================

/**
 * Intuition: An array of size N has 2^N total subsets.
 * Each binary number from 0 to (2^N - 1) represents a unique subset configuration.
 * If i-th bit of integer 'mask' is 1, include nums[i] in the subset.
 * 
 * Recurrence / Total Operations:
 *  Outer loop runs 2^N times. Inner loop runs N times.
 *  Total Time Complexity: O(N * 2^N)
 *  Auxiliary Space Complexity: O(1) extra space (excluding result container).
 */
vector<vector<int>> generatePowerSet(const vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = 1 << n; // 2^N
    vector<vector<int>> powerSet;
    powerSet.reserve(totalSubsets);

    for (int mask = 0; mask < totalSubsets; ++mask) {
        vector<int> currentSubset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                currentSubset.push_back(nums[i]);
            }
        }
        powerSet.push_back(currentSubset);
    }

    return powerSet;
}

// ============================================================================
// MAIN DRIVER & VERIFICATION SUITE
// ============================================================================

int main() {
    cout << "==========================================" << endl;
    cout << "  RUNNING BIT MANIPULATION TEST SUITE     " << endl;
    cout << "==========================================" << endl;

    // Test 1: Bit Manipulation Helpers
    cout << "\n[Test 1] Testing Bit Helper Operations..." << endl;
    int num = 13; // Binary: 1101₂
    assert(BitTricks::isBitSet(num, 0) == true);
    assert(BitTricks::isBitSet(num, 1) == false);
    assert(BitTricks::setBit(num, 1) == 15);     // 1111₂ = 15
    assert(BitTricks::clearBit(num, 2) == 9);    // 1001₂ = 9
    assert(BitTricks::toggleBit(num, 0) == 12);  // 1100₂ = 12
    assert(BitTricks::isPowerOfTwo(16) == true);
    assert(BitTricks::isPowerOfTwo(18) == false);
    assert(BitTricks::countSetBitsKernighan(13) == 3);
    assert(BitTricks::getLowestSetBit(12) == 4); // 12 = 1100₂, LSB = 0100₂ = 4
    cout << "✓ Bit Helper Operations Passed!" << endl;

    // Test 2: Single Number I
    cout << "\n[Test 2] Testing Single Number I..." << endl;
    vector<int> arr1 = {4, 1, 2, 1, 2};
    int unique1 = singleNumberI(arr1);
    cout << "Input: {4, 1, 2, 1, 2} | Output Unique: " << unique1 << endl;
    assert(unique1 == 4);
    cout << "✓ Single Number I Passed!" << endl;

    // Test 3: Single Number III
    cout << "\n[Test 3] Testing Single Number III..." << endl;
    vector<int> arr2 = {1, 2, 1, 3, 2, 5};
    pair<int, int> uniques = singleNumberIII(arr2);
    cout << "Input: {1, 2, 1, 3, 2, 5} | Output Uniques: (" 
         << uniques.first << ", " << uniques.second << ")" << endl;
    assert((uniques.first == 3 && uniques.second == 5) || (uniques.first == 5 && uniques.second == 3));
    cout << "✓ Single Number III Passed!" << endl;

    // Test 4: Power Set Generation
    cout << "\n[Test 4] Testing Power Set Generation..." << endl;
    vector<int> arr3 = {1, 2, 3};
    vector<vector<int>> subsets = generatePowerSet(arr3);
    cout << "Subsets for {1, 2, 3}:" << endl;
    for (const auto& subset : subsets) {
        cout << "  { ";
        for (int x : subset) cout << x << " ";
        cout << "}" << endl;
    }
    assert(subsets.size() == 8);
    cout << "✓ Power Set Generation Passed!" << endl;

    cout << "\n==========================================" << endl;
    cout << "   ALL BIT MANIPULATION TESTS PASSED!     " << endl;
    cout << "==========================================" << endl;

    return 0;
}
