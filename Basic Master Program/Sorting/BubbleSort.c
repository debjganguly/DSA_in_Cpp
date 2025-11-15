#include <stdio.h>

int main()
{
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int temp;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
