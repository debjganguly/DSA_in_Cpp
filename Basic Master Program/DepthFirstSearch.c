#include <stdio.h>

int MAX=100;

void DFS(int arr[][MAX],int vertices, int start) {
    printf("%d ",start);
    int visited[MAX];

    for(int i=0;i<vertices;i++) {
        if(arr[start][i]==1 && !visited[i]) {
            DFS(arr,vertices,i);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    int vertices;
    scanf("%d",&vertices);
    int start;
    printf("Enter the start symbol: ");
    scanf("%d",&start);
    int adj[MAX][MAX];
    DFS(adj,vertices,start);
}