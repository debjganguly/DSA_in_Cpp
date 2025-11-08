#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int val;
    int pt;
} Node;

typedef struct {
    Node* arr;
    int len;
    int size;
} PriorityQueue;

void insert (PriorityQueue* pq, int val, int p) {
    if (pq->size == pq->len) {
        printf("Queue Overflow!\n");
        return;
    }
    pq->arr[pq->size].val=val;
    pq->arr[pq->size].pt = p;
    pq->size++;
}

void deleteNode (PriorityQueue* pq) {
    if(pq->size==0) {
        printf("PQueue is Empty\n");
        return;
    }
    int maxpt = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i].pt > pq->arr[maxpt].pt) {
            maxpt = i;
        }
    }

    int item = pq->arr[maxpt].val;

    for (int i = maxpt; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }

    pq->size--;

}

void display(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nCurrent Priority Queue:\n");
    printf("Data\tPriority\n");
    printf("-----------------\n");
    for (int i = 0; i < pq->size; i++) {
        printf("%d\t%d\n", pq->arr[i].val, pq->arr[i].pt);
    }
}

int main() {
    int len;
    printf("Enter the length of Array: ");
    scanf("%d", &len);
    
    PriorityQueue* pq=(PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->len=len;
    pq->size=0;

    pq->arr=(Node*)malloc(len*sizeof(Node));

    printf("\n--- Priority Queue Menu ---\n");
    printf("1. Insert\n");
    printf("2. Delete Highest Priority\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    int choice=0;
    while(choice!=4) {
        printf("-----------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int val, pr;
        switch(choice) {
            case 1: printf("Enter the Value: ");
                    scanf("%d",&val);
                    printf("Enter the priority of this value: ");
                    scanf("%d",&pr);
                    insert(pq,val,pr);
                    break;
            case 2: deleteNode(pq);
                    break;
            case 3: display(pq);
                    break;
            case 4: printf("Exiting, Chilll....\n");
            default: printf("Not in the Menu...");
                     break;
        }
    }

}