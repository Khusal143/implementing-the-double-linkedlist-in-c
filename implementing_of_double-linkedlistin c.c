#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to print the list forward
void printListForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to print the list backward
void printListBackward(struct Node* tail) {
    struct Node* temp = tail;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Function to add a node at the end
struct Node* append(struct Node* tail, int data) {
    struct Node* newNode = createNode(data);
    if (tail != NULL) {
        tail->next = newNode;
        newNode->prev = tail;
    }
    return newNode;
}

int main() {
    struct Node* head = createNode(10);
    struct Node* tail = head;

    tail = append(tail, 20);
    tail = append(tail, 30);

    printf("List forward:\n");
    printListForward(head);

    printf("List backward:\n");
    printListBackward(tail);

    return 0;
}