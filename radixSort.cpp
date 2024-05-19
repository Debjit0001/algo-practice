#include <iostream>

void countSort(int arr[], int size, int dec) {
    int count_arr[9 + 1] = {0};  // max possible value for each decimal place is 9
    int sorted_arr[size];

    // counting how many times that decimal place(1 or 10 or 100..)'s number occurs in the main array
    for(int i = 0; i < size; i++) {
        int x = (arr[i]/dec) % 10;  // for example, when finding the 10's place in 172, x will be 7
        count_arr[ x ] += 1;
    }

    // running sum of count array:
    for(int i = 1; i < 10; i++) {
        count_arr[i] = count_arr[i] + count_arr[i-1];
    }

    // placing in the stable & correct position in sorted array
    for(int i = size-1; i >= 0; i--) 
    {
        int x = (arr[i]/dec) % 10;
        sorted_arr[ count_arr[x] - 1 ] = arr[i];
        count_arr[x]--;
    }

    // copying into original array
    for (int i = 0; i < size; i++) {
        arr[i] = sorted_arr[i];
    }
}

void radixSort(int arr[], int size) {
    int max = arr[0];

    for(int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for(int dec = 1; max/dec > 0 ; dec *= 10) {
        countSort(arr, size, dec);
    }

    /*
        max = 172

        dec = 1, max/dec: 172/1 > 0

        dec = 10, max/dec > 0

        dec = 100, max/dec =1 > 0

        dec = 1000, max/dec = 0.5 = 0
    */
}

int main()
{
    int arr[] = {3, 21, 172, 73, 51};
    int size = (sizeof(arr) / sizeof(arr[0]));

    printf("Before sorting: ");
    for(int i = 0; i < size; i++)
        printf("%d ", *(arr+i));
        

    radixSort(arr, size);

    printf("\n After sorting: ");
    for(int i = 0; i < size; i++)
        printf("%d ", *(arr+i));

    return 0;
}