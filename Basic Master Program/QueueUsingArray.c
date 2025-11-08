#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isEmpty(int front, int rear) {
    return (front==-1 || front>rear); 
}

bool isFull(int len, int rear) {
    return (rear==len-1);
}

void enqueue(int arr[],int* front, int* rear, int len, int val) {
    if(isFull(len, *rear)) {printf("Queue is Full...\n"); return;}
    else {
        if(*front ==-1 && *rear ==-1) {
            ++(*front);
            ++(*rear);
            arr[*rear]=val;
        } else {
            ++(*rear);
            arr[*rear]=val;
        }
    }
}

void dequeue(int arr[], int *front, int* rear) {
    if(isEmpty(*front,*rear)) {
        printf("Stack is Empty...\n");
        return;
    } 
    ++(*front);
}

void peek(int arr[],int rear, int front, int len) {
    if(isEmpty(front,rear)) {
        printf("Stack is Empty...\n");
    }
    printf("The element is %d\n",arr[rear]);
}

void display(int arr[],int front, int rear) {
    if(isEmpty(front,rear)) {
        printf("Stack is Empty...\n");
        return;
    }
    printf("The Array Elements are: ");
    for(int i=front;i<=rear;i++) {
        printf("%d",arr[i]);
    }
    printf("\n");
}
int main() {
    int len;
    printf("Enter the Length of the queue: ");
    scanf("%d",&len);
    int arr[len];
    int front =-1, rear=-1;

    printf("Menu: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Check if Full\n");
    printf("4. Check if Empty\n");
    printf("5. Peek\n");
    printf("6. Display\n");
    printf("7. Exit...\n");

    int choice = 0;
    while(choice!=7) {
        printf("-------------------------------------------------------\n");
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter the Value: ");
                    int val;
                    scanf("%d",&val);
                    enqueue(arr,&front,&rear,len, val); 
                    break;
            case 2: dequeue(arr,&front,&rear);
                    break;
            case 3: if(isFull(len,rear)) {
                       printf("Stack is Full...\n");
                    } else {
                        printf("Stack is Hungry...\n");
                    } break;
            case 4: if(isEmpty(front,rear)) {
                       printf("Stack is Empty...\n");
                    } else {
                        printf("Stack is not empty...\n");
                    } break;
            case 5: peek(arr,rear,front,len); break;
            case 6: display(arr,front,rear); break;
            case 7: break;
            default: printf("Not a freaking option... \n");
        }
    }


}