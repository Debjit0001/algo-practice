#include <stdio.h>

void mergesort(int arr[], int start, int end) {
    // base condition where only a single element is left in array
    if((end - start) == 1)
        return;

    int mid = (start+end)/2;

    // recursive call to sort the left part
    mergesort(arr, start, mid); // 2, 4, 6, 8, 10
                                // 0  1  2  3  4

    // recursive call to sort the right part
    mergesort(arr, mid, end); // 3, 5, 7
                              // 5  6  7

    // merging the left and right parts in sorted order
    int i = start, j = mid, k = 0;
    int size = end-start;
    int merge_arr[size];

    while(i < mid && j < end) 
    {
        if(arr[i] < arr[j]) {
            merge_arr[k] = arr[i];
            i++, k++;
        }
        else {
            merge_arr[k] = arr[j];
            j++, k++;   
        }
    }
    // now either both array are empty or any single one has remaining elements
    while(i < mid) {
            merge_arr[k] = arr[i];
            i++, k++;
    }

    while(j < end) {
            merge_arr[k] = arr[j];
            j++, k++;
    }

    // copying the final sorted array into the original array
    for(int k = 0; k < size; k++) 
        arr[start + k] = merge_arr[k];
}

int main()
{
    int arr[] = {6, 2, 8, 1, 5, 3, 7, 4};
    int size = (sizeof(arr)/sizeof(arr[0]));

    printf("Sorted array: ");
    mergesort(arr, 0, size);
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr+i));
    
    return 0;
}
