#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* a, Node* b) {
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    Node* head = NULL;

    if (a->data < b->data) {
        head = a;
        a = a->next;
    }
    else {
        head = b;
        b = b->next;
    }

    Node* current = head;
    while (a != NULL && b != NULL) {

        if (a->data < b->data) {
            current->next = a;
            a = a->next;
        }
        else {
            current->next = b;
            b = b->next;
        }

        current = current->next;
    }

    if (a != NULL) {
        current->next = a;
    }

    if (b != NULL) {
        current->next = b;
    }

    return head;
}

int main() {

    Node* first = new Node(1);
    first->next = new Node(3);
    first->next->next = new Node(5);
    first->next->next->next = new Node(7);

    cout << "First list:" << endl;
    print(first);

    Node* mid = middle(first);

    cout << endl;
    cout << "Middle: " << mid->data << endl;

    Node* second = new Node(2);
    second->next = new Node(4);
    second->next->next = new Node(6);
    second->next->next->next = new Node(8);

    cout << endl;
    cout << "Second list:" << endl;
    print(second);

    Node* result = merge(first, second);

    cout << endl;
    cout << "Merged:" << endl;
    print(result);

    return 0;
}