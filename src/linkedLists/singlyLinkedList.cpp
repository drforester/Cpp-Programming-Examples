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

int main()
{
    Node* List1 = appendNode(0);
    List1->next = appendNode(4);
    List1->next->next = appendNode(6);

    printList(List1);
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
