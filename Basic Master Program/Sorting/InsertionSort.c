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

    int curr, j;

    for(int i=1;i<n;i++) { // Start iteration from 1
        curr=arr[i]; // The current element
        j=i-1; // Previous Element 

        while(j>=0 && curr < arr[j]) { // do while j is non-neg anf do while the current elemnt is less than previous element
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=curr;
    }
}