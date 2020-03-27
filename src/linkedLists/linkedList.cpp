#include <iostream>

using std::cout;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList() { // constructor
        head = NULL;
    }
    ~LinkedList() {}; // destructor
    void addNode(int val);
    void reverseList();
    void display();
};

// function to add node to the end of a list
void LinkedList::addNode(int val) {
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) { // in case this is the list's first node
        head = newnode;
    }
    else {
        Node* temp = head; // start at the head
        while (temp->next != NULL) { 
            temp = temp->next; // go to end of list
        }
        temp->next = newnode; // linking to newnode
    }
}

// reverse Linked List
void LinkedList::reverseList() {
    Node* temp = head;
    Node* nextnode = NULL;
    Node* revnode = NULL;
    while (temp != NULL) {
        head = temp;
        nextnode = temp->next;
        temp->next = revnode;
        revnode = temp;
        temp = nextnode;
    }
}

void LinkedList::display() {
    if (head == NULL) {
        cout << "List is empty." << '\n';
    }
    else {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
}

int main()
{
    LinkedList* list = new LinkedList();
    list->addNode(100);
    list->addNode(200);
    list->addNode(300);
    list->addNode(400); 
    list->addNode(500);
    cout << "Linked List data" << '\n';
    list->display();
    list->reverseList();
    cout << "Reversed Linked List data" << '\n';
    list->display();
    delete list;
}

