#include <stdio.h>
#include <stdlib.h>

// Node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNewNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Check if empty
void isEmpty(int top) {
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}

// Display elements
void display(struct Node** head, int* top) {
    if (*top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    struct Node* temp = *head;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Push operation
void push(struct Node** head, int* top, int maxlen) {
    if (*top == maxlen - 1) {
        printf("Stack Overflow\n");
        return;
    }

    int val;
    printf("Enter value to push: ");
    scanf("%d", &val);

    struct Node* newNode = createNewNode(val);
    newNode->next = *head;
    *head = newNode;
    (*top)++;

    printf("Pushed %d to stack\n", val);
}

// Pop operation
void pop(struct Node** head, int* top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = *head;
    printf("Popped %d from stack\n", temp->data);
    *head = (*head)->next;
    free(temp);
    (*top)--;
}

int main() {
    int maxlen;
    printf("Enter the maximum length of stack: ");
    scanf("%d", &maxlen);

    int choice = 1;
    int top = -1;
    struct Node* head = NULL;

    printf("\nMenu:\n");
    printf("1: Check if stack is empty\n");
    printf("2: Display elements\n");
    printf("3: Push\n");
    printf("4: Pop\n");
    printf("5: Quit\n");

    while (choice != 5) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                isEmpty(top);
                break;

            case 2:
                display(&head, &top);
                break;

            case 3:
                push(&head, &top, maxlen);
                break;

            case 4:
                pop(&head, &top);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
