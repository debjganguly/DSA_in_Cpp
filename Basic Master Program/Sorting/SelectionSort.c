#include <stdio.h>

int main() {
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min;
    for(int i=0;i<n;i++) {
        min=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[min]) {
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

    printf("The Sorted Array is: ");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}