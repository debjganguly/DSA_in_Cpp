#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* arr;
    int front;
    int rear;
} Queue;

bool isEmpty(Queue* head, int len) {
    return (head->front==-1 && head->rear==-1);
}

bool isFull(Queue* head, int len) {
    return ((head->rear+1)%len==head->front);
}

void enqueue(Queue* head, int len, int value) {
    if(isFull(head,len)) {
        printf("Queue is Full!\n");
        return;
    } else {
        if(head->front == -1 && head->rear == -1) {
            head->front=(head->front+1)%len;
            head->rear=(head->rear+1)%len;
            head->arr[head->rear]=value;
        } else {
            head->rear=(head->rear+1)%len;
            head->arr[head->rear]=value;
        }
    }
}

void dequeue(Queue* head, int len, int value) {
    if(isEmpty(head,len)) {
        printf("Queue is Empty!\n");
        return;
    } 

    printf("Dequeued: %d\n", head->arr[head->front]);

    if (head->front == head->rear) {
        head->front = head->rear = -1;
    } else {
        head->front = (head->front + 1) % len;
    }
}

void display(Queue* head, int len) {
    if(isEmpty(head,len)) {
        printf("Queue is Empty!\n");
        return;
    } else {
        printf("The Elements are: ");
        for(int i=head->front;i<=head->rear;i=(i+1)%len) {
            printf("%d ",head->arr[i]);
        }
        printf("\n");
    }
}

void peek(Queue* head, int len) {
    if(isEmpty(head,len)) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("The Element: %d\n",head->arr[head->front]);
}

int main() {
    int len;
    printf("Enter a len: ");
    scanf("%d",&len);

    Queue* head=(Queue*)malloc(sizeof(Queue));
    head->arr=(int*)malloc(len*sizeof(int));
    head->front=-1;
    head->rear=-1;

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
        int val;
        switch(choice) {
            case 1: 
                    printf("Enter a value: ");
                    scanf("%d",&val);
                    enqueue(head,len,val);
                    break;

            case 2: dequeue(head, len, val);
                    break;

            case 4: if(isEmpty(head,len)) {printf("Queue is Empty...\n");}
                    else {printf("Queue is Not Empty\n");}
                    break;

            case 3: if(isFull(head,len)) {printf("Queue is Full!\n");}
                    else {printf("Queue is not Full...\n");}
                    break;

            case 5: peek(head,len);
                    break;

            case 6: display(head,len);
                    break;

            case 7: printf("Exiting...\n");
                    break;

            default: printf("Not a Valid Option\n");
                     break;
        }
    }
}