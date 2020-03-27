/*
A singly-linked-list implementation
*/

#include <iostream>

using std::cout;

struct Node { 
    int val; 
    struct Node* next; 
};

Node* appendNode(int val);
void printList(Node* node);
Node* mergeList(Node* L1, Node* L2);

int main()
{
    // create and initialize two linked lists
    Node* List1 = appendNode(0);
    List1->next = appendNode(4);
    List1->next->next = appendNode(6);
    // 0->4->6

    Node* List2 = appendNode(1);
    List2->next = appendNode(2);
    List2->next->next = appendNode(5);
    List2->next->next->next = appendNode(7);
    // 1->2->5->7

    Node* mergedList = mergeList(List1, List2);

    printList(mergedList);
}


Node* appendNode(int val) {
    struct Node* temp = new Node;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void printList(Node* node) {
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}

Node* mergeList(Node* L1, Node* L2) {
    if (!L1)
        return L2;

    if (!L2)
        return L1;

    if (L1->val < L2->val) {
        L1->next = mergeList(L1->next, L2);
        return L1;
    }
    else {
        L2->next = mergeList(L1, L2->next);
        return L2;
    }
}
