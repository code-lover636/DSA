/*
7. Implement Heap sort
The heap sort works as its name suggests - it begins by building a heap out of the data set, and then removing the largest item and placing it at the end of the sorted array. After removing the largest item, it reconstructs the heap and removes the largest remaining item and places it in the next open position from the end of the sorted array. This is repeated until all elements are sorted.

The time complexity is (n log(n))
*/

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }

}


void heapSort(int arr[], int n) {
    
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--) {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {

    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter number:");
        scanf("%d",&arr[i]);
    }
    
    heapSort(arr, n);
    printf("\nSorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

/*
Output:
Enter size of the array: 5
Enter number:2
Enter number:1
Enter number:3
Enter number:3
Enter number:6
Sorted array: 1 2 3 3 6 	
*/
