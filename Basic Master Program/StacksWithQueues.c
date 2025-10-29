// The menu choice:
// 1: Check stack for empty
// 2: Display elements
// 3: Push
// 4: Pop
// 5: Quit

#include <stdio.h>
#include <stdlib.h>

// Function to check id Empty or not
void isEmpty(int top) {
    if(top==-1) printf("Stack is empty\n");
    else printf("Stack is not empty\n");
}

// Function to display elements of stack
void display(int arr[],int* top) {
    if(*top==-1) {
        printf("Stack is Empty\n");
        return;
    } else {
        printf("Stack elements are:\n");
        for(int i=*top;i>=0;i--) {
            printf("%d\n", arr[i]);
        }
    }
}

// Function to push element into stack
void push(int arr[],int top, int len) {
    if(top==len-1) {
        printf("Stack Overflow\n");
        return;
    } else {
        int val;
        printf("Enter value to be pushed:");
        scanf("%d", &val);
        arr[++top]=val;
    }
}

// Function to pop element from stack
void pop(int arr[], int top) {
    if(top==-1) {
        printf("Stack is Empty\n");
        return;
    }
    else {
        printf("Popped %d from stack\n", arr[top]);
    }
}
    
int main() {
    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);
    int arr[len];

    int choice=1;
    int top=-1;

    printf("1: Check stack for empty\n");
    printf("2: Display elements\n");
    printf("3: Push\n");
    printf("4: Pop\n");
    printf("5: Quit\n\n");
    
    while(choice!=5) {
        printf("Enter your choice:");
        scanf("%d", &choice);

        printf("------------------------------------------\n");

        switch(choice) {
            case 1: isEmpty(top);
                    break;
            case 2: display(arr, &top);
                    break;
            case 3: push(arr, top++, len);
                    break;
            case 4: pop(arr, top--);
                    break;
            case 5: printf("Exiting...\n");
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }

        printf("------------------------------------------\n");

    }

}