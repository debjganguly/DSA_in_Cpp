#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Check if queue is empty
bool isEmpty(Node* front) {
    return (front == NULL);
}

// Enqueue: insert element at the rear
void enqueue(Node** front, Node** rear, int val) {
    Node* newNode = createNode(val);
    if (*rear == NULL) { // Emptying queue
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued successfully.\n", val);
}

// Dequeue: remove element from the front
void dequeue(Node** front, Node** rear) {
    if (isEmpty(*front)) {
        printf("Queue is Empty!\n");
        return;
    }
    Node* temp = *front;
    printf("Dequeued element: %d\n", temp->data);
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL; // Queue is now empty
    free(temp);
}

// Peek: show front element
void peek(Node* front) {
    if (isEmpty(front))
        printf("Queue is Empty!\n");
    else
        printf("Front element: %d\n", front->data);
}

// Display all queue elements
void display(Node* front) {
    if (isEmpty(front)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, val;

    printf("\nQueue Menu: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Check if Empty\n");
    printf("6. Exit\n");

    while (1) {
        printf("-------------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&front, &rear, val);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                peek(front);
                break;
            case 4:
                display(front);
                break;
            case 5:
                if (isEmpty(front))
                    printf("Queue is Empty.\n");
                else
                    printf("Queue is not Empty.\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
