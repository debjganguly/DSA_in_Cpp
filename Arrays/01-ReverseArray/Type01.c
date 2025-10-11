// Usage of Recursion
// Time Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

// Function to Reverse the Array using Recursion
void reverseArray(int* arr, int pos, int len) {
    if(pos>=len) {
        return;
    }

    int temp = arr[pos];
    arr[pos]=arr[len];
    arr[len]=temp;

    reverseArray(arr,pos+1,len-1);
    return;
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
    reverseArray(arr, 0, len - 1);

    // Printing the Reversed Array
    printf("Reversed Array: ");
    for (int j = 0; j < len; j++) {
        printf("%d ", arr[j]);
    }
}