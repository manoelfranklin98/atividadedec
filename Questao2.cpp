#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};

void convertToCircularList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    convertToCircularList(head);

    Node* current = head;
    do {
        std::cout << current->data << " -> ";
        current = current->next;
    } while (current != head);

    std::cout << "Voltou ao início." << std::endl;

    return 0;
}

