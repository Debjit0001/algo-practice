#include<stdio.h>

void countSort(int arr[], int size) {   // 8 7
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int count_arr[max+1] = {0}; // initialized count array of size (max+1) with 0's 
    
    for(int i = 0; i < size; i++) {
        count_arr[ arr[i] ]++;
    }

    // STABLE 
    for (int i = 1; i < max+1; i++) {
        count_arr[i] = count_arr[i] + count_arr[i-1];   
    }

    int sorted_arr[size];  // temporarily store the sorted order values so that the original array does not have to be modified
    for (int i = size-1; i >= 0 ; i--) {
        sorted_arr[ count_arr[arr[i]] - 1 ] = arr[i];
        count_arr[arr[i]]--;
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = sorted_arr[i];
    }
    


/*  UNSTABLE 
    for (int i = 0, j = 0; i < max+1; i++) 
    {
        while (count_arr[i] > 0) {
            arr[j] = i;  
            count_arr[i]--;  // decreasing the counter
            j++;  // going to the next index in main array
        }      
    }
*/
}

int main()
{
    int arr[] = {3, 4, 1, 3, 2, 5, 2, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting: ");
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr+i));
    }
        
    countSort(arr, size);

    printf("\n After sorting: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", *(arr+i));
    }

    return 0;
}