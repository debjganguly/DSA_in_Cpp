// Use of Loop
// Time COmplexity: O(n)

#include <stdio.h>
#include <stdlib.h>

// Function to Reverse the Array
void reverseArray(int* arr, int len) {
    int start=0,end=len-1;
    while(start<end) {
        int temp=arr[start];
        arr[start++]=arr[end];
        arr[end--]=temp;
    }
}

int main() {

    // Taking the Length of the Array
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

    // Function to Reverse the Array using Recursion
    reverseArray(arr,len);

    // Printing the Reversed Array
    printf("Reversed Array: ");
    for (int j = 0; j < len; j++) {
        printf("%d ", arr[j]);
    }
}