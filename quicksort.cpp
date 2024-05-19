#include <stdio.h>

void quicksort(int arr[], int start, int end) 
{
    if (start >= end) {
        return;
    }

    int left = start, right = end;
    int pivot = arr[start + (end-start)/2];

    while(left <= right) {

        while(arr[left] < pivot) {
            left++;
        }

        while(arr[right] > pivot) {
            right--;
        }

        if(left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    quicksort(arr, start, right);
    quicksort(arr, left, end);
}

int main(int argc, char const *argv[])
{
    int arr[] = {8, 3, 1, 7, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, size-1);

    printf("Sorted array: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    return 0;
}
