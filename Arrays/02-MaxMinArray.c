// Calculating the Maxmimum and Minimum Value in an Array
// Time Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

// Function to Calulate the Max Value in Array
int max(int* arr, int len) {
    int max=arr[0];
    for(int i=0;i<=len;i++) {
        if(arr[i]>max) max=arr[i];
    }
    return max;
}

// Function to Calulate the Min Value in Array
int min(int* arr, int len) {
    int min=arr[0];
    for(int i=0;i<=len;i++) {
        if(arr[i]<min) min=arr[i];
    }
    return min;
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

    // Max & Min Value of an Array
    int maxval = max(arr,len-1);
    int minval = min(arr,len-1);

    // Printing the Answer
    printf("The Maximum Value in the Array is %d\n",maxval);
    printf("The Minimum Value in the Array is %d\n",minval);
}