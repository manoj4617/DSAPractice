#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) {
        return nullptr;  // If either list is empty, there is no intersection.
    }

    ListNode* ptrA = headA;
    ListNode* ptrB = headB;

    while (ptrA != ptrB) {
        // Move ptrA and ptrB forward by one node at a time (or set to the other list's head).
        ptrA = (ptrA ? ptrA->next : headB);
        ptrB = (ptrB ? ptrB->next : headA);
    }

    return ptrA;  // Either ptrA or ptrB is the intersection point.
}

// Example usage:
int main() {
    // Create nodes and linked lists
    ListNode* commonNode = new ListNode(8);
    ListNode* listA = new ListNode(4);
    listA->next = new ListNode(1);
    listA->next->next = commonNode;
    
    ListNode* listB = new ListNode(5);
    listB->next = new ListNode(6);
    listB->next->next = new ListNode(1);
    listB->next->next->next = commonNode;

    // Call the function to get the intersection node
    ListNode* intersectionNode = getIntersectionNode(listA, listB);

    // Print the result
    if (intersectionNode) {
        std::cout << "Intersection Node Value: " << intersectionNode->val << std::endl;
    } else {
        std::cout << "No Intersection" << std::endl;
    }

    // Clean up memory
    delete listA;
    delete listB;
    delete commonNode;

    return 0;
}
