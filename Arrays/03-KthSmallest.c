// Finding the Kth Smallest ELement in an Array
// Time Complexity: O(n^2)

#include <stdio.h>
#include <stdlib.h>

// Fidning Kth Smallest Element in the Array
int kthSmallest(int* arr, int len) {
    // Sorting the Array
    for(int i=0;i<len-1;i++) {
        for(int j=0;j<len-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    // Asking for kth value
    int k;
    printf("Enter the kth Value: ");
    scanf("%d",&k);

    return arr[len];
}

int main() {
    // ENTERING THE LENGTH OF ARRAY
    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);

    // Dynamically Allocating Memory to the Array
    int *arr = (int *)malloc(len * sizeof(int));

    // Taking the Elements of the Array
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < len; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int val = kthSmallest(arr,len);

    printf("The Kth Smallest Value in the Array: %d\n",val);
}