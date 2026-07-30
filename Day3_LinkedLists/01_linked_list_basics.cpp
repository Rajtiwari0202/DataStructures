/*
 * Day 3 - Linked Lists: Basics
 * -----------------------------------------
 * Singly Linked List, Doubly Linked List, Circular Linked List.
 * Insert, delete, search, traverse, reverse (iterative + recursive).
 */

#include <iostream>
using namespace std;

// ============ SINGLY LINKED LIST ============
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(nullptr) {}

    // Insert at head - O(1)
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail - O(n) (no tail pointer kept; would be O(1) if we tracked one)
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Delete first node with given value - O(n)
    void deleteValue(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val) curr = curr->next;
        if (curr->next) {
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        }
    }

    // Search - O(n)
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Traverse / print - O(n)
    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Reverse iteratively - O(n) time, O(1) space
    void reverseIterative() {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Reverse recursively - O(n) time, O(n) space (call stack)
    Node* reverseRecursiveHelper(Node* node) {
        if (!node || !node->next) return node;
        Node* newHead = reverseRecursiveHelper(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }
    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
    }
};

// ============ DOUBLY LINKED LIST ============
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    DNode* head;
    DoublyLinkedList() : head(nullptr) {}

    // Insert at head - O(1)
    void insertAtHead(int val) {
        DNode* newNode = new DNode(val);
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    }

    // Insert at tail - O(n) without tail pointer
    void insertAtTail(int val) {
        DNode* newNode = new DNode(val);
        if (!head) { head = newNode; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete a given node directly - O(1) since we have prev AND next pointers.
    // This is the key advantage of DLL over SLL for deletion.
    void deleteNode(DNode* node) {
        if (!node) return;
        if (node->prev) node->prev->next = node->next;
        else head = node->next; // deleting head
        if (node->next) node->next->prev = node->prev;
        delete node;
    }

    void traverseForward() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// ============ CIRCULAR LINKED LIST (singly) ============
class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() : head(nullptr) {}

    // Insert at head - O(n) since we must find the last node to update its 'next'
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head; // points to itself
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Traverse - O(n), must stop upon returning to head
    void traverse() {
        if (!head) { cout << "Empty list" << endl; return; }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    cout << "--- Singly Linked List ---" << endl;
    SinglyLinkedList sll;
    sll.insertAtHead(3);
    sll.insertAtHead(2);
    sll.insertAtHead(1);
    sll.insertAtTail(4);
    sll.traverse();

    sll.deleteValue(3);
    sll.traverse();

    cout << "Search 4: " << sll.search(4) << endl;

    sll.reverseIterative();
    sll.traverse();

    sll.reverseRecursive();
    sll.traverse();

    cout << "\n--- Doubly Linked List ---" << endl;
    DoublyLinkedList dll;
    dll.insertAtHead(3);
    dll.insertAtHead(2);
    dll.insertAtHead(1);
    dll.insertAtTail(4);
    dll.traverseForward();

    cout << "\n--- Circular Linked List ---" << endl;
    CircularLinkedList cll;
    cll.insertAtHead(3);
    cll.insertAtHead(2);
    cll.insertAtHead(1);
    cll.traverse();

    return 0;
}