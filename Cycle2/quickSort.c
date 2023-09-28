/*
5. Implement Quick sort
It is also called partition exchange sort. Partition the list recursively and sort the sub lists to obtain the final sorted list.

The time complexity is O(n.log(n))
*/
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int first, int last) {
    int pivot = arr[last]; 
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] <= pivot) 
            swap(&arr[++i], &arr[j]);
    }
    
    swap(&arr[i + 1], &arr[last]);
    return i + 1;
}

void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int pivotIndex = partition(arr, first, last);
        quickSort(arr, first, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
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
    
    quickSort(arr, 0, n - 1);
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
Enter number:7
Enter number:5
Sorted array: 1 2 3 5 7 	
*/
