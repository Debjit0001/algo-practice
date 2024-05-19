#include<iostream>
using namespace std;

void heapify(int arr[], int n, int p) {
    int parent = p;

    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < n && arr[parent] < arr[left]) {
        swap(arr[parent], arr[left]);
        heapify(arr, n, left);
    }

    if (right < n && arr[parent] < arr[right]) {
        swap(arr[parent], arr[right]);
        heapify(arr, n, right);
    }
}

void heapSort(int arr[], int size) {
    // building the max heap
    for(int i = 1; i < size; i++) 
    {
        int child = i;
        while(child > 0) {
            int parent = (child-1) / 2;  // i is the 'index' of child
            if( arr[parent] < arr[child] ) {
                swap(arr[parent], arr[child]);
                child = parent;
            }
            else
                break;
        }
    }

    int n = size;  // placing the root(highest) element in their correct position
    while (n > 1) {
        swap(arr[0], arr[n - 1]);  // swapping the root of heap with the last element
        n--;  // reducing the size of the heap
        heapify(arr, n, 0);  // heapify the root element
    }
}

int main() 
{
    int arr[] = {12, 3, 5, 17, 1, 32, 20};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    
    heapSort(arr, size);

    printf("\n After sorting: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]); 

    return 0;
}