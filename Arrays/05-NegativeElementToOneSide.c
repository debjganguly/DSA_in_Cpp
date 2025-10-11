// Negative Elements to One Side using Double Pointer
// Time Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

void negtoleft(int* arr, int len) {

    // INTIALISING DOUBLE POINTERS
    int start=0,end=len-1;
    while(start!=end) {
        // now there are 4 cases
        if(arr[start]<=0 && arr[end]>=0) {continue;}
        if(arr[start]<=0 && arr[end]<=0) {
            start++;
        }
        if(arr[start]>=0 && arr[end]>=0) {
            end--;
        }
        if(arr[start]>=0 && arr[end]<=0) {
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;end--;
        }
    }
}

int main() {

    // STORING THE LENGTH OF ARRAY
    int len;
    printf("Enter the length of the array: ");
    scanf("%d", &len);

    // DYNAMICALLY ALLOCATE MEMORY TO ARRAY
    int *arr = (int *)malloc(len * sizeof(int));

    // TAKING THE ELEMENTS OF THE ARRAY
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < len; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    negtoleft(arr,len);

    // PRINTING THE OUPUT
    printf("The elements of the array are: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

}