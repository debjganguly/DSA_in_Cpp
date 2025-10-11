// Sort the given values containing either 0,1 or 2 in ascending order
// Time Complexity: O(n^2)

#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int len) {
    // SORTING THE ARRAY
    for(int i=0;i<len-1;i++) {
        for(int j=0;j<len-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
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
        if(!(arr[i]==0 || arr[i]==1 || arr[i]==2)) {printf("Not a Valid input, Re Enter....\n");i--;}
    }

    sort(arr,len);

    // PRINTING THE OUPUT
    printf("The elements of the array are: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

}