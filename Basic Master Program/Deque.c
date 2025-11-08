#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* arr;
    int front;
    int rear;
    int len;
} Deque;

bool isEmpty(Deque* dq) {return (dq->front==-1 && dq->rear==-1);}
bool isFull(Deque* dq) {return (dq->front==(dq->rear+1)%dq->len);}

void insertAtFront(Deque* dq, int val) {
    if(isFull(dq)) {printf("Deque is Full!\n"); return;}
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else
    dq->front = (dq->front - 1 + dq->len) % dq->len;
    dq->arr[dq->front]=val;
}
    

void insertAtRear(Deque* dq, int val) {
    if(isFull(dq)) {printf("Deque is Full!\n"); return;}
    if(dq->rear==-1) {
        dq->front = dq->rear = 0;
    } else 
    dq->rear = (dq->rear + 1) % dq->len;
    dq->arr[dq->rear]=val;
}

void deleteAtFront(Deque* dq) {
    if(isEmpty(dq)) {printf("Deque is Empty!\n"); return;}
    if(dq->front==dq->rear){dq->front=-1;dq->rear=-1;}
    else
    dq->front=(dq->front+1)%(dq->len);
}

void deleteAtRear(Deque* dq) {
    if(isEmpty(dq)) {printf("Deque is Empty!\n"); return;}
    if(dq->front==dq->rear){dq->front=-1;dq->rear=-1;}
    else
    dq->rear=(dq->rear-1+dq->len)%(dq->len);
}

int peekFront(Deque* dq) {
    if (isEmpty(dq)) { 
       printf("Deque is Empty!\n"); 
       return -1; 
    }
    return dq->arr[dq->front];
}

int peekRear(Deque* dq) {
    if (isEmpty(dq)) { 
       printf("Deque is Empty!\n"); 
       return -1; 
    }
    return dq->arr[dq->rear];
}

void display(Deque* dq) {
    if(isEmpty(dq)) {printf("Nothing to Display!\n"); return;}
    printf("The Elements are ");
    for(int i = dq->front; i!=dq->rear ; i=(i+1)%dq->len) {
        printf("%d ",dq->arr[i]);
    }
    printf("%d \n",dq->arr[dq->rear]);
}

int main() {
    int len, choice;
    printf("Enter the Length of Array: ");
    scanf("%d",&len);

    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->arr = (int*)malloc(len*sizeof(int));
    dq->front=-1;
    dq->rear=-1;
    dq->len=len;

    printf("\n===== DEQUE MENU =====\n");
    printf("1. Insert Front\n");
    printf("2. Insert Rear\n");
    printf("3. Delete Front\n");
    printf("4. Delete Rear\n");
    printf("5. IsEmpty\n");
    printf("6. IsFull\n");
    printf("7. Peek From Front\n");
    printf("8. Peek from Rear\n");
    printf("9. Display\n");
    printf("10. Exit\n");

    while(choice!=10) {
        printf("======================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int val;
        switch(choice) {
            case 1: printf("Enter the value to enter from front: ");
                    scanf("%d",&val);
                    insertAtFront(dq,val);
                    break;
            case 2: printf("Enter the value to enter from rear: ");
                    scanf("%d",&val);
                    insertAtRear(dq,val);
                    break;
            case 3: deleteAtFront(dq);
                    break;
            case 4: deleteAtRear(dq);
                    break;
            case 5: if(isEmpty(dq)) {
                       printf("Deque is Empty!\n");
                    } else {
                       printf("Deque is Not Empty!\n");
                    }
                    break;
            case 6: if(isFull(dq)) {
                       printf("Deque is Full!\n");
                    } else {
                       printf("Deque is Not Full!\n");
                    }
                    break;
            case 7: printf("The Value at front is %d",peekFront(dq));
                    break;
            case 8: printf("The Value at Rear is %d",peekRear(dq));
                    break;
            case 9: display(dq);
                    break;
            case 10: printf("ok, Exiting, be Chill....");
                     break;
            default: printf("Going off Books? :)...");
                     break;
        }
    }
}