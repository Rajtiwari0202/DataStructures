/*
 * Day 3 - Linked Lists: Placement Problems
 * -----------------------------------------------------
 * 1. Detect Cycle - Floyd's Tortoise & Hare
 * 2. Find Middle Node - Slow/Fast Pointer
 * 3. Merge Two Sorted Linked Lists - Dummy Node technique
 * 4. Remove Nth Node From End - Two Pointer with Gap
 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Helper to build a list from an array
Node* buildList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// ---------------- 1. Detect Cycle (Floyd's Algorithm) ----------------
// O(n) time, O(1) space
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// ---------------- 2. Find Middle Node ----------------
// O(n) time, O(1) space, single pass
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// ---------------- 3. Merge Two Sorted Linked Lists ----------------
// O(n + m) time, O(1) extra space (reuses existing nodes)
Node* mergeTwoSorted(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// ---------------- 4. Remove Nth Node From End ----------------
// O(n) time, O(1) space, single pass
Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0);
    dummy.next = head;
    Node* fast = &dummy;
    Node* slow = &dummy;

    for (int i = 0; i <= n; i++) fast = fast->next;

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy.next;
}

int main() {
    // 1. Cycle detection
    int arr1[] = {1, 2, 3, 4, 5};
    Node* list1 = buildList(arr1, 5);
    cout << "hasCycle (no cycle): " << (hasCycle(list1) ? "true" : "false") << endl;

    // create a cycle manually: last node points back to 3rd node
    Node* temp = list1;
    Node* thirdNode = nullptr;
    int idx = 0;
    while (temp) {
        if (idx == 2) thirdNode = temp;
        if (!temp->next) temp->next = thirdNode; // close the loop
        temp = temp->next;
        idx++;
        if (idx > 10) break; // safety guard for this demo traversal
    }
    cout << "hasCycle (with cycle): " << (hasCycle(list1) ? "true" : "false") << endl;

    // 2. Find middle (fresh list, no cycle)
    int arr2[] = {1, 2, 3, 4, 5};
    Node* list2 = buildList(arr2, 5);
    cout << "Middle of [1,2,3,4,5]: " << findMiddle(list2)->data << endl;

    int arr3[] = {1, 2, 3, 4};
    Node* list3 = buildList(arr3, 4);
    cout << "Middle of [1,2,3,4]: " << findMiddle(list3)->data << endl;

    // 3. Merge two sorted lists
    int arrA[] = {1, 3, 5};
    int arrB[] = {2, 4, 6};
    Node* la = buildList(arrA, 3);
    Node* lb = buildList(arrB, 3);
    Node* merged = mergeTwoSorted(la, lb);
    cout << "Merged sorted lists: ";
    printList(merged);

    // 4. Remove Nth node from end
    int arr4[] = {1, 2, 3, 4, 5};
    Node* list4 = buildList(arr4, 5);
    Node* afterRemoval = removeNthFromEnd(list4, 2); // remove 2nd from end (value 4)
    cout << "After removing 2nd from end: ";
    printList(afterRemoval);

    return 0;
}