#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int MAX=100;

typedef struct {
    int arr[100];
    int front;
    int rear;
} Queue;

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int item = q->arr[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void BFS (int adjMat[MAX][MAX], int vertices, int start) {
    Queue* q;
    q->front=-1;
    q->rear=-1;

    int traversed[MAX];

    traversed[start]==1;
    enqueue(&q,start);

    while(!isEmpty(q)) {
        int node = dequeue(q);
        
        for(int i =0;i<vertices;i++) {
            if(adjMat[node][i]==1 && !visited(i)) {
                traversed[i]=0;
                enqueue(&q,i);
            } 
        }
    }

    printf("\n");
}

int main() {
    int vertices;
    printf("Enter the vertices of the Tree: ");
    scanf("%d",&vertices);

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d",&edges);

    int adjMat[MAX][MAX];

    printf("Enter the edges in (u v) format (ignore brackets ofc): \n");
    for(int i=0;i<edges;i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }

    int start;
    printf("Enter the start edge: ");
    scanf("%d",&start);

    BFS(adjMat,vertices,start);
}