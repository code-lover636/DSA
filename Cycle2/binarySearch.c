/*
2. Implement Binary Search
Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
Time complexity ……………O(logn)
*/

#include <stdio.h>

void binarySearch(int arr[], int n, int target) {
    int l=0, r=n-1, mid;
    
    while (l<=r) {
        mid = l + (r - l) / 2;
        if (arr[mid] == target){
            printf("Element is found at index %d.\n", mid);
            return;
        }
        if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("Element is not found in array.\n");
    return;
}

int main() {
    int n,target;
    // Read Array
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0 ; i < n ; i++ ){
        printf("Enter number: ");
        scanf("%d",&arr[i]);
    }
    // Read search key
    printf("\nEnter key value to search: ");
    scanf("%d",&target);
    binarySearch(arr, n, target);
}

/*
Ouptut:
Enter total number of elements: 5
Enter number: 1
Enter number: 3
Enter number: 5
Enter number: 6
Enter number: 8
Enter key value to search: 7
Element is not found in array.
*/
