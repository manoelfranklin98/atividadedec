#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};

int findMiddleValue(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    int middleValue = findMiddleValue(head);

    std::cout << "O valor do elemento do meio é: " << middleValue << std::endl;

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

